/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_leaf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:30:41 by junpkim           #+#    #+#             */
/*   Updated: 2022/06/07 16:31:22 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*make_type(char *s)
{
	t_node	*node;

	if (s == NULL)
		return (NULL);
	node = malloc_s(sizeof(t_node));
	node->type = TYPE;
	node->content = s;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

t_node	*make_filename(char *s)
{
	t_node	*node;

	if (s == NULL)
		return (NULL);
	node = malloc_s(sizeof(t_node));
	node->type = FILENAME;
	node->content = s;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

t_node	*make_filepath(char *s)
{
	t_node	*node;

	if (s == NULL)
		return (NULL);
	node = malloc_s(sizeof(t_node));
	node->type = FILEPATH;
	node->content = s;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

t_node	*make_argv(char *s)
{
	t_node	*node;

	if (s == NULL)
		return (NULL);
	node = malloc_s(sizeof(t_node));
	node->type = ARGV;
	node->content = s;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
