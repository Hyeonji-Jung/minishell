/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:32:15 by junpkim           #+#    #+#             */
/*   Updated: 2022/06/07 16:32:16 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    cmd_bin(char *command, char **split, char **envp)
{
    int		status;

    status = 0;
    if (execve(command, split, envp) == -1)
        status = errno;
    if (status == 2)
    {
        if (command[0] == '/' || command[ft_strlen(command) - 1] == '/')
			print_err(command, "no such file or directory");
        else
            print_err(command, "command not found");
    }
    strerror(status);
}
