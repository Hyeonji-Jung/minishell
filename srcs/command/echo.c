/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:32:20 by junpkim           #+#    #+#             */
/*   Updated: 2022/06/07 16:32:21 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmd_echo(char **strs)
{
	int	i;

	if (!strs)
	{
		printf("\n");
		return (0);
	}
	if (!ft_strcmp(strs[0], "-n"))
		i = 1;
	else
		i = 0;
	while (strs[i])
	{
		printf("%s", strs[i]);
		if (strs[i + 1])
			printf(" ");
		i++;
	}
	if (ft_strcmp(strs[0], "-n"))
		printf("\n");
	return (0);
}
