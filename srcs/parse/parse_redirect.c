/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:31:54 by junpkim           #+#    #+#             */
/*   Updated: 2022/06/07 16:31:55 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**parse_redirect(char *s)
{
	char	**ret;
	int		loc;

	loc = 0;
	ret = malloc_s(sizeof(char *) * 2);
	if (s[0] == '<')
	{
		if (s[1] == '<')
			loc = 2;
		else
			loc = 1;
	}
	else if (s[0] == '>')
	{
		if (s[1] == '>')
			loc = 2;
		else
			loc = 1;
	}
	ret[0] = ft_substr(s, 0, loc);
	ret[1] = ft_substr(s, loc, ft_strlen(s) - loc);
	return (ret);
}
