#include "minishell.h"

void	new_process(t_info **info, t_node *node)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
	{
		print_error("pipe error");
		return ;
	}
	pid = fork();
	if (pid == 0)
	{
		dup2(fd[1], 1);
		close(fd[0]);
		node_execute(info, node->left);
		exit(0);
	}
	else
	{
		waitpid(-1, NULL, 0);
		dup2(fd[0], 0);
		close(fd[1]);
		node_execute(info, node->right);
	}
}

void	node_execute(t_info **info, t_node *node)
{
	if ((*info)->fd < 0)
		return ;
	if (node->type == SIMPLECMD)
	{
		if (node->right != NULL)
			cmd_execute(info, node->left->content, node->right->content);
		else
			cmd_execute(info, node->left->content, NULL);
	}
	else if (node->type == REDIRECT)
		(*info)->fd = redirect_execute(node->left->content, node->right->content);
	else if (node->type == PIPE && node->right)
		new_process(info, node);
	else
	{
		if (node->left)
			node_execute(info, node->left);
		if (node->right)
			node_execute(info, node->right);
	}
	if ((*info)->fd != -1)
		close((*info)->fd);

}

static void free_s(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

int	cmd_execute(t_info **info, char *cmd, char *option)
{
	char	**split;

	split = ft_split(option, ' '); // 스페이스 말고 공백문자로 수정 필요
	if (!ft_strcmp(cmd, "echo"))
		cmd_echo(split);
	else if (!ft_strcmp(cmd, "cd"))
		cmd_cd(split[1]);
	else if (!ft_strcmp(cmd, "pwd"))
		cmd_pwd();
	else if (!ft_strcmp(cmd, "env"))
		cmd_env((*info)->env);
	else if (!ft_strcmp(cmd, "export"))
		cmd_export(&(*info)->env, split[1]);
	else if (!ft_strcmp(cmd, "unset"))
		cmd_unset(&(*info)->env, split[1]);
	else if (!ft_strcmp(cmd, "exit"))
	{
		free_env(&(*info)->env);
		cmd_exit();
	}
	else
		system(option); // system 함수가 사용가능한 함수 목록에 없어서 바꿔야 할 거 같음
	free_s(split);
	return (0);
}

int	redirect_execute(char *type, char *file_name)
{
	int	fd;

	fd = -1;
	if (!type || !file_name)
		return (-1);
	if (!ft_strcmp(type, "<"))
		fd = input(file_name);
	else if (!ft_strcmp(type, ">"))
		fd = overwrite(file_name);
	else if (!ft_strcmp(type, ">>"))
		fd = append(file_name);
	return (fd);
}
