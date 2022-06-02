/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:39:33 by hyeojung          #+#    #+#             */
/*   Updated: 2022/06/02 17:30:25 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	node_search(t_node *node, char *s)
{
//	if (node->content)
//	if (!node->left)
		printf("%s: %s\n", s, node->content);
	if (node->left)
		node_search(node->left, ft_strjoin(s, "->left"));
	if (node->right)
		node_search(node->right, ft_strjoin(s, "->right"));
}

void	node_execute(t_info **info, t_node *node)
{
//	int	fd;

//	fd = -1;
	if ((*info)->fd < 0)
		return ;
	if (node->type == SIMPLECMD)
	{
		if (node->right != NULL)
			cmd_execute(info, node->left->content, node->right->content);
		else
			cmd_execute(info, node->left->content, NULL);
	}
	else if(node->type == REDIRECT)
	{
		(*info)->fd = redirect_execute(node->left->content, node->right->content);
//		if (fd < 0)
//			return ;
//		else
//			new_fd(&(*info)->fd, fd);
	}
	if (node->left)
		node_execute(info, node->left);
	if (node->right)
		node_execute(info, node->right);
	if ((*info)->fd != -1)
		close((*info)->fd);
}

static void free_s(char **tmp, char **tmp1, char **command)
{
	free(*tmp);
	*tmp = NULL;
	free(*tmp1);
	*tmp1 = NULL;
	free(*command);
	*command = NULL;
}

int prompt(t_info **info)
{
    char    *command;
	char	*tmp;
	char	*tmp1;
	t_node	*tree;

	tree = NULL;
    while (1)
    {
		// signal 중 interrupt 있으면 다른 프롬프트 표시되어야 함 🙂: 보통 😡: interrupt로 하는 거 어떨까
        command = readline("🙂 ➡️ ");
		add_history(command);
		tmp = multi_space(command);
		if (!tmp)
			continue ;
		tmp1 = parse_env(tmp, (*info)->env);
		(*info)->tree = make_pipe(tmp1);
//		if (!chk_command(command))
//			(*info)->tree = make_pipe(tmp1);
//		else
//			printf("ERROR: 어쩌구\n");
		if (!(*info)->tree)
		{
			free_s(&tmp, &tmp1, &command);
			continue ;
		}
		node_execute(info, (*info)->tree);
		free_tree(&(*info)->tree);
		free_s(&tmp, &tmp1, &command);
		dup2((*info)->old_stdin, STDIN_FILENO);
		dup2((*info)->old_stdout, STDOUT_FILENO);
		(*info)->tree = NULL;
		(*info)->fd = 0;
    }
}

int	main(int argc, char *argv[], char *envp[])
{
	t_env	*env;
	t_info	*info;

	signal(SIGINT, signal_catch);
	signal(SIGQUIT, signal_catch);
	info = malloc_s(sizeof(t_info));
	info->old_stdin = dup(STDIN_FILENO);
	info->old_stdout = dup(STDOUT_FILENO);
	info->fd = 0;
	env = env_init(envp);
	info->env = env;
	if (argc == 1)
		prompt(&info);

	argv[0] = argv[0];
//	prompt();
/*	char *s = argv[1];
     t_node                  *tree;
//     signal(SIGINT, catch_signal);
//     signal(SIGQUIT, catch_signal);
//     system("clear");
	tree = make_pipe(s);
     g_foreground = 0;
	 node_search(tree, "root");
	 */
}
