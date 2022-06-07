/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:33:32 by junpkim           #+#    #+#             */
/*   Updated: 2022/06/07 16:33:33 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_substr(char *s, int start, int len)
{
	char	*ret;
	int		i;

	ret = malloc_s(sizeof(char) * (len + 1));
	ret[len] = '\0';
	i = 0;
	while (i < len)
	{
		ret[i] = s[start + i];
		i++;
	}
	return (ret);
}
