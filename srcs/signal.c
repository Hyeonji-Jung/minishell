/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:39:33 by hyeojung          #+#    #+#             */
/*   Updated: 2022/06/07 16:30:57 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_catch(int sig)
{
	if (sig == SIGINT)
	{
		g_foreground = 130;
		rl_on_new_line();
	//	rl_replace_line("", 1);
		rl_redisplay();
	}
	else if (sig == SIGQUIT)
	{
		return ;
	}
}
