/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:32:45 by junpkim           #+#    #+#             */
/*   Updated: 2022/06/07 16:32:47 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmd_unset(t_env **env, char *s)
{
	if (s == NULL)
	{
		g_foreground = 1;
		return (1);
	}
	delete_env(env, s);
	g_foreground = 0;
	return (0);
}
