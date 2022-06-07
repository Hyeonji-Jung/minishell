/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:32:27 by junpkim           #+#    #+#             */
/*   Updated: 2022/06/07 16:32:32 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_isnum(char *s)
{
	int	i;

	i = -1;
	if (s[0] == '-')
		i++;
	while (s[++i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			continue ;
		else
			return (0);
	}
	return (1);
}

void	cmd_exit(t_info **info, char **s)
{
	if (info)
		free_env(&(*info)->env);
	system("leaks minishell");
	if (!s)
		exit(0);
	else
	{
		if (ft_isnum(*s))
			exit((unsigned char)ft_atoi(*s));
		else
		{
			print_err("exit", ft_strjoin(*s, ": numeric argument required"));
			exit(255);
		}
	}
}
