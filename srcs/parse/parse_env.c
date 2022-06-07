/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:31:40 by junpkim           #+#    #+#             */
/*   Updated: 2022/06/07 16:31:41 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_isnum(char c)
{
	return ((c >= '0' && c <= '9'));
}

static int	key_length(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isalpha(s[i]) && !ft_isnum(s[i]))
			break ;
		i++;
	}
	return (i);
}

int	parse_env(char *s, char **ret, t_env *env)
{
	int		len;
	char	*tmp;
	char	*tmp1;
	int		slash;
	t_env	*env_tmp;

	if (!s)
		return (0);
	if (ft_isnum(s[1]))
		return (1);
	len = key_length(&s[1]);
	tmp = ft_substr(s, 1, len);
	env_tmp = search_env(env, tmp);
	if (env_tmp)
		tmp1 = env_tmp->value;
	else
		tmp1 = NULL;
	free(tmp);
	tmp = ft_strjoin(*ret, tmp1);
	free(*ret);
	*ret = tmp;
	return (len);
}
