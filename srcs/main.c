/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:39:33 by hyeojung          #+#    #+#             */
/*   Updated: 2022/06/01 20:24:31 by hyeojung         ###   ########.fr       */
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

void	node_execute(t_node *node, t_env *env)
{
	if (node->type == SIMPLECMD)
	{
		if (node->right != NULL)
			cmd_execute(&env, node->left->content, node->right->content);
		else
			cmd_execute(&env, node->left->content, NULL);
	}
	if (node->left)
		node_execute(node->left, env);
	if (node->right)
		node_execute(node->right, env);
}

int prompt(t_env *env)
{
    char    *command;
	t_node	*tree;
    
    while (1)
    {
		// signal 중 interrupt 있으면 다른 프롬프트 표시되어야 함 🙂: 보통 😡: interrupt로 하는 거 어떨까
        command = readline("🙂 ➡️ ");
		add_history(command);
		if (!chk_command(command))
			tree = make_pipe(multi_space(command));
		else
			printf("ERROR: 어쩌구\n");
//		tree = make_pipe(command);
	//	node_search(tree, "root");
		node_execute(tree, env);
		tree = NULL;
    }
}

int	main(int argc, char *envp[])
{
	t_env	*env;

	env = env_init(envp);
	if (argc == 1)
		prompt(env);

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
