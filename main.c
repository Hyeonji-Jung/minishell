/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:39:33 by hyeojung          #+#    #+#             */
/*   Updated: 2022/05/12 18:09:21 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "inc/minishell.h"
#include <ctype.h>
#include <stdio.h>
#include <readline/readline.h>

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
        command = readline(">> ");
        // parse_command(command, &nr_tokens, tokens);
        // for (int i = 0; i < nr_tokens; i++)
        //     printf("%s\n", tokens[i]);
    }
}

// int	main(void)
// {
//     static struct sigaction act;
//     t_tree                  *tree;

//     // act.sa_handler = catch_signal;
//     sigaction(SIGINT, &act, NULL);
//     sigaction(SIGQUIT, &act, NULL);
//     system("clear");
//     tree = init_tree();
//     g_foreground = 0;
// }