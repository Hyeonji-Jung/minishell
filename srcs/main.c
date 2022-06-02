/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:39:33 by hyeojung          #+#    #+#             */
/*   Updated: 2022/06/02 21:20:00 by junpkim          ###   ########.fr       */
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

static void	free_s(char **tmp, char **command, t_info **info)
{
	if (*tmp)
	{
		free(*tmp);
		*tmp = NULL;
	}
	free(*command);
	*command = NULL;
	dup2((*info)->old_stdin, STDIN_FILENO);
	dup2((*info)->old_stdout, STDOUT_FILENO);
	(*info)->tree = NULL;
	(*info)->fd = 0;
}

int	prompt(t_info **info)
{
	char	*command;
	char	*tmp;
	char	*tmp1;
	t_node	*tree;

	tree = NULL;
	while (1)
	{
		// signal 중 interrupt 있으면 다른 프롬프트 표시되어야 함 🙂: 보통 😡: interrupt로 하는 거 어떨까
		command = readline("🙂 ➡️ ");
		add_history(command);
		if (chk_command(command))
			continue ;
		tmp = multi_space(command);
		if (!tmp)
			continue ;
		tmp1 = parse_env(tmp, (*info)->env);
		(*info)->tree = make_pipe(tmp1);
		if (!(*info)->tree)
		{
			free_s(&tmp, &command, info);
			continue ;
		}
		node_execute(info, (*info)->tree);
		free_tree(&(*info)->tree);
		free_s(&tmp, &command, info);
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
