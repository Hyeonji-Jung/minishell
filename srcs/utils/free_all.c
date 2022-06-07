/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:33:01 by junpkim           #+#    #+#             */
/*   Updated: 2022/06/07 16:33:02 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tree(t_node **node)
{
	t_node	*tmp;

	tmp = *node;
	if (tmp->left)
		free_tree(&tmp->left);
	if (tmp->right)
		free_tree(&tmp->right);
	if (tmp->content)
	{
		if (tmp->content[0])
			free((*node)->content);
	}
	free(*node);
}

void	free_env(t_env **env)
{
	t_env	*tmp;
	t_env	*next;

	tmp = *env;
	while (tmp)
	{
		free(tmp->key);
		free(tmp->value);
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
}
