/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_simplecmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:32:01 by junpkim           #+#    #+#             */
/*   Updated: 2022/06/07 16:32:01 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	chk_space(char *s)
{
	int	i;
	int	quote;
	int	dquote;

	i = -1;
	quote = 0;
	dquote = 0;
	while (s[++i])
	{
		if (s[i] == '\'' && !dquote)
			quote = !quote;
		else if (s[i] == '\"' && !quote)
			dquote = !dquote;
		else if (s[i] == ' ' && !quote && !dquote)
			break ;
	}
	return (i);
}

char	**parse_simplecmd(char *s)
{
	char	**ret;
	int		loc;

	loc = chk_space(s);
	ret = malloc_s(sizeof(char *) * 2);
	if (loc == ft_strlen(s))
	{
		ret[0] = ft_strdup(s);
		ret[1] = NULL;
	}
	else
	{
		ret[0] = ft_substr(s, 0, loc);
		ret[1] = ft_substr(s, loc + 1, ft_strlen(s) - loc);
	}
	return (ret);
}
