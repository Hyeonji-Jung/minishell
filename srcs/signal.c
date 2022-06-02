/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:39:33 by hyeojung          #+#    #+#             */
/*   Updated: 2022/06/01 15:25:21 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	signal_catch(int sig)
{
	if (sig == SIGINT)
	{
		g_foreground = 130;
	}
	else if (sig == SIGQUIT)
	{
		g_foreground = 131;
	}
	return (0);
}
