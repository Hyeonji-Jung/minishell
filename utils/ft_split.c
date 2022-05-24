/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 21:58:49 by junpkim           #+#    #+#             */
/*   Updated: 2022/05/23 16:34:06 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static char	**do_malloc(int n)
{
	char	**ret;

	ret = malloc(sizeof(char *) * (n + 1));
	if (ret == NULL)
		return (0);
	ret[n] = 0;
	return (ret);
}

static int	get_row(char *str, char c)
{	
	int		cnt;
	int		i;
	int		chk;

	if (str == NULL)
		return (0);
	i = -1;
	cnt = 0;
	chk = 1;
	while (str[++i])
	{
		if (str[i] == c)
			chk = 1;
		else if (chk == 1)
		{
			chk = 0;
			cnt++;
		}
	}
	return (cnt);
}

static char	**chk_null(char **s, int cnt)
{
	int	i;
	int	chk;

	if (s == 0)
		return (0);
	i = 0;
	chk = 0;
	while (i < cnt)
	{
		if (s[i++] == NULL)
			chk = 1;
	}
	i = 0;
	if (chk == 1)
	{
		while (i < cnt)
			free(s[i++]);
		free(s);
		s = NULL;
	}
	return (s);
}

static char	**do_split(char **res, char *s, char c, int cnt)
{
	int	i;
	int	row;
	int	tmp;

	i = -1;
	row = 0;
	tmp = 0;
	while (s[++i])
	{
		if (s[i] == c)
		{
			if (i > tmp)
				res[row++] = ft_substr(s, tmp, i - tmp);
			tmp = i + 1;
		}
	}
	if (row < cnt)
		res[row] = ft_substr(s, tmp, i - tmp);
	res = chk_null(res, cnt);
	return (res);
}

char	**ft_split(char *s, char c)
{
	char	**ret;
	int		row;

	if (s == NULL)
		return (0);
	row = get_row(s, c);
	ret = do_malloc(row);
	if (ret == NULL)
		return (0);
	ret = do_split(ret, s, c, row);
	return (ret);
}
