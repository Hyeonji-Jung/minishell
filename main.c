/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:39:33 by hyeojung          #+#    #+#             */
/*   Updated: 2022/05/26 17:14:55 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "inc/minishell.h"
#include <ctype.h>
#include <stdio.h>
//#include <readline/readline.h>

// int parse_command(char *command, int *nr_tokens, char *tokens[])
// {
// 	char *curr = command;
// 	int token_started = 0;
// 	*nr_tokens = 0;

// 	while (*curr != '\0') {  
// 		if (isspace(*curr)) {  
// 			*curr = '\0';
// 			token_started = 0;
// 		} else {
// 			if (!token_started) {
// 				tokens[*nr_tokens] = curr;
// 				*nr_tokens += 1;
// 				token_started = 1;
// 			}
// 		}
// 		curr++;
// 	}

// 	return 0;
// }

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
    char    **tokens;
    int     nr_tokens;
	t_node	*tree;
	
	tree = NULL;
    while (1)
    {
        command = readline(">> ");
		add_history(command);
		printf("%s\n", parse_env(multi_space(command)));
		tree = make_pipe(parse_env(multi_space(command)));
		if (!tree)
			continue ;
	//	tree = make_pipe(parse_env(multi_space(command)));
//		tree = make_pipe(command);
	//	node_search(tree, "root");
		node_execute(tree, env);
		tree = NULL;
    }
}

int	main(int argc, char *argv[], char *envp[])
{
	t_env	*env;
	
	env = env_init(envp);
	prompt(env);
	int i = 0;

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
