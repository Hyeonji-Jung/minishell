/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:31:37 by junpkim           #+#    #+#             */
/*   Updated: 2022/06/07 16:31:38 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	chk_redirects(char *s)
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
		else if ((s[i] == '<' || s[i] == '>') && !quote && !dquote)
			break ;
	}
	return (i);
}

char	**parse_cmd(char *s)
{
	char	**ret;
	int		loc;

	loc = chk_redirects(s);
	ret = malloc_s(sizeof(char *) * 2);
	if (loc == ft_strlen(s))
	{
		ret[0] = ft_strdup(s);
		ret[1] = NULL;
	}
	else
	{
		ret[0] = ft_substr(s, 0, loc);
		ret[1] = ft_substr(s, loc, ft_strlen(s) - loc);
	}
	return (ret);
}
