/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:39:33 by hyeojung          #+#    #+#             */
/*   Updated: 2022/05/18 20:19:17 by junpkim          ###   ########.fr       */
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

int prompt(void)
{
    char    *command;
    char    **tokens;
    int     nr_tokens;
    
    while (1)
    {
    //    command = readline(">> ");
        // parse_command(command, &nr_tokens, tokens);
        // for (int i = 0; i < nr_tokens; i++)
        //     printf("%s\n", tokens[i]);
    }
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	int		n;
	int		m;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (0);
	n = ft_strlen(s1);
	m = ft_strlen(s2);
	ret = malloc(sizeof(char) * (n + m + 1));
	if (ret == NULL)
		return (0);
	i = -1;
	while (++i < n)
		ret[i] = s1[i];
	i = -1;
	while (++i < m)
		ret[n + i] = s2[i];
	ret[n + i] = '\0';
	return (ret);
}
void	node_search(t_node *node, char *s)
{
//	if (node->content)
	if (!node->left)
		printf("%s: %s\n", s, node->content);
	if (node->left)
		node_search(node->left, ft_strjoin(s, "->left"));
	if (node->right)
		node_search(node->right, ft_strjoin(s, "->right"));
}

int	main(int argc, char *argv[])
{

	char *s = argv[1];
     t_node                  *tree;
//     signal(SIGINT, catch_signal);
//     signal(SIGQUIT, catch_signal);
//     system("clear");
	tree = make_pipe(s);
     g_foreground = 0;
	 node_search(tree, "root");
 }
