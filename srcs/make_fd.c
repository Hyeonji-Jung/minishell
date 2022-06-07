/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:30:38 by junpkim           #+#    #+#             */
/*   Updated: 2022/06/07 16:31:17 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	new_fd(t_fd **fd, int add_fd)
{
	t_fd	*ret;
	t_fd	*tmp;

	ret = malloc_s(sizeof(t_fd));
	ret->num = add_fd;
	ret->next = NULL;
	if (*fd == NULL)
		*fd = ret;
	else
	{
		tmp = *fd;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = ret;
	}
}
