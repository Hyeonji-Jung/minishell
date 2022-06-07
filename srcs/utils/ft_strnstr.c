/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:33:26 by junpkim           #+#    #+#             */
/*   Updated: 2022/06/07 16:33:28 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strnstr(char *str, char *find, int size)
{
	int	find_len;

	find_len = ft_strlen(find);
	if (*find)
	{
		if (size == 0)
			return (0);
		while (ft_strncmp(str, find, find_len) != 0 && size--)
		{
			if (!*str || size < find_len)
				return (0);
			str++;
		}
	}
	return ((char *)str);
}
