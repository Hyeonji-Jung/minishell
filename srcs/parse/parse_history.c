/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_history.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:31:44 by junpkim           #+#    #+#             */
/*   Updated: 2022/06/07 16:31:45 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	case1(char **ret, char *s, int i)
{
	char	*add;
	char	*tmp;

	if (s[i + 2] == '\\' && s[i + 3] == '\n')
		return ;
	add = ft_substr(s, i + 2, 1);
	tmp = ft_strjoin(*ret, add);
	if (*ret)
		free(*ret);
	free(add);
	*ret = tmp;
}

static void	case2(char **ret, char *s, int i)
{
	char	*add;
	char	*tmp;

	add = ft_substr(s, i, 3);
	tmp = ft_strjoin(*ret, add);
	if (*ret)
		free(*ret);
	if (s[i + 3] == '\n')
		*ret = ft_strjoin(tmp, "; ");
	else
	{
		free(add);
		add = ft_substr(s, i + 3, 1);
		*ret = ft_strjoin(tmp, add);
	}
	free(tmp);
	free(add);
}

static void case3(char **ret, char *s, int i)
{
	char	*add;
	char	*tmp;

	add = ft_substr(s, i, 1);
	tmp = ft_strjoin(*ret, add);
	if (*ret)
		free(*ret);
	*ret = tmp;
	free(add);
}

char	*parse_history(char *s)
{
	char	*ret;
	int		i;

	i = -1;
	ret = NULL;
	while (s[++i])
	{
		if (s[i] == '\\')
		{
			if (s[i + 1] == '\n')
			{
				case1(&ret, s, i);
				i += 2;
			}
			else if (s[i + 1] == '\\' && s[i + 2] == '\\')
			{
				case2(&ret, s, i);
				i += 3;
			}
			else
				case3(&ret, s, i);
		}
		else
			case3(&ret, s, i);
	}
	return (ret);
}
