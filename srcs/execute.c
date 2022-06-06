#include "minishell.h"

void	new_process(t_info **info, t_node *node)
{
	pid_t	pid;
	int		fd[2];
	int		wstatus;

	if (pipe(fd) == -1)
	{
		print_err(" ", "Pipe error");
		return ;
	}
	pid = fork();
	if (pid == 0)
	{
		dup2(fd[1], 1);
		close(fd[0]);
		node_execute(info, node->left);
		exit(g_foreground);
	}
	else
	{
		waitpid(-1, &wstatus, 0);
		if (WIFEXITED(wstatus))
			strerror(WEXITSTATUS(wstatus));
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
	{
		(*info)->fd = redirect_execute(node->left->content,
				node->right->content);
		if ((*info)->fd < 0)
		{
			g_foreground = 2;
			print_err(node->left->content, "No such file or directory");
		}
	}
//	else if (node->type == PIPE && node->right)
//		new_process(info, node);
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

static void	free_s(char **s)
{
	int	i;

	if (!s)
		return ;
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
	char	*tmp_cmd;

	split = ft_split(option, ' ');
	if (cmd[0] == '\'' || cmd[0] == '\"')
		tmp_cmd = ft_substr(cmd, 1, ft_strlen(cmd) - 2);
	else
		tmp_cmd = ft_strdup(cmd);
	if (!ft_strcmp(tmp_cmd, "echo"))
		cmd_echo(split);
	else if (!ft_strcmp(tmp_cmd, "cd"))
		cmd_cd(split[1]);
	else if (!ft_strcmp(tmp_cmd, "pwd"))
		cmd_pwd();
	else if (!ft_strcmp(tmp_cmd, "env"))
		cmd_env((*info)->env);
	else if (!ft_strcmp(tmp_cmd, "export"))
		cmd_export(&(*info)->env, split[1]);
	else if (!ft_strcmp(tmp_cmd, "unset"))
		cmd_unset(&(*info)->env, split[1]);
	else if (!ft_strcmp(tmp_cmd, "exit"))
		cmd_exit(info);
	else
		cmd_bin(tmp_cmd, split, (*info)->envp);
	free_s(split);
	free(tmp_cmd);
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
	else if (!ft_strcmp(type, "<<"))
		fd = double_left_redirect(file_name);
	return (fd);
}
