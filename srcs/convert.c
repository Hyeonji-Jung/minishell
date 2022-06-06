/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.seoul.k>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:35:18 by junpkim           #+#    #+#             */
/*   Updated: 2022/06/06 20:11:22 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	append_char(char **ret, char *s)
{
	char	*tmp;
	char	*tmp1;

	tmp = ft_substr(s, 0, 1);
	if (tmp[0] == '\n')
		return ;
	tmp1 = ft_strjoin(*ret, tmp);
	free(tmp);
	if (*ret)
		free(*ret);
	*ret = tmp1;
}

int	append_env(t_info **info, char **ret, char *s)
{
	char	*tmp;
	char	*tmp1;
	int		len;

	if (s[1] == '$')
	{
		tmp1 = ft_itoa(getpid());
		tmp = ft_strjoin(*ret, tmp1);
		if (*ret)
			free(*ret);
		*ret = tmp;
		return (1);
	}
	else
	{
		len = 0;
		len = parse_env(s, ret, (*info)->env);
		if (len == 0)
		{
			tmp = ft_strdup("$");
			append_char(ret, tmp);
			free(tmp);
			return (0);
		}
		else
			return (len);
	}
}

char	*convert(t_info **info, char *s)
{
	char	*ret;
	int		quote;
	int		dquote;
	int		i;
	int		slash;

	if (!s)
		return (0);
	quote = 0;
	dquote = 0;
	i = -1;
	ret = NULL;
	slash = 0;
	while (s[++i])
	{
		if (s[i] == '\n')
			continue ;
		if (s[i] == '\'' && !dquote && slash % 2 == 0)
			quote = !quote;
		else if (s[i] == '\"' && !quote && slash % 2 == 0)
			dquote = !dquote;
		if (s[i] == '\'' && (dquote || slash))
			append_char(&ret, &s[i]);
		else if (s[i] == '\"' && (quote || slash))
			append_char(&ret, &s[i]);
		else if (s[i] == '$' && !quote)
			i += append_env(info, &ret, &s[i]);
		else if ((s[i] != '\'' && s[i] != '\"' && s[i] != '\\') || slash % 2 == 1)
			append_char(&ret, &s[i]);
		if (s[i] == '\\')
			slash++;
		else
			slash = 0;
	}
	free(s);
	return (ret);
}

void	node_convert(t_info **info, t_node **node)
{
	char	*tmp;

	if ((*node)->left)
		node_convert(info, &(*node)->left);
	if ((*node)->right)
		node_convert(info, &(*node)->right);
	tmp = convert(info, (*node)->content);
	(*node)->content = tmp;
}
