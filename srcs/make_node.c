/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:30:44 by junpkim           #+#    #+#             */
/*   Updated: 2022/06/07 16:31:24 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*make_cmd(char *s)
{
	t_node	*node;
	char	**split;

	if (s == NULL)
		return (NULL);
	node = malloc_s(sizeof(t_node));
	node->type = CMD;
	node->content = ft_strtrim(s, " ");
	split = parse_cmd(node->content);
	node->right = make_simplecmd(split[0]);
	node->left = make_redirects(split[1]);
	free(s);
	free(split);
	return (node);
}

t_node	*make_pipe(char *s)
{
	t_node	*node;
	char	**split;

	if (s == NULL)
	{
		return (NULL);
	}
	node = malloc_s(sizeof(t_node));
	node->type = PIPE;
	node->content = ft_strtrim(s, " ");
	split = parse_pipe(node->content);
	free(s);
	node->left = make_cmd(split[0]);
	node->right = make_pipe(split[1]);
	free(split);
	return (node);
}

t_node	*make_simplecmd(char *s)
{
	t_node	*node;
	char	**split;

	if (s == NULL)
		return (NULL);
	node = malloc_s(sizeof(t_node));
	node->type = SIMPLECMD;
	node->content = ft_strtrim(s, " ");
	split = parse_simplecmd(node->content);
	node->left = make_filepath(split[0]);
	node->right = make_argv(split[1]);
	free(split);
	free(s);
	return (node);
}

t_node	*make_redirects(char *s)
{
	t_node	*node;
	char	**split;

	if (s == NULL)
		return (NULL);
	node = malloc(sizeof(t_node));
	node->type = REDIRECTS;
	node->content = delete_space(s);
	split = parse_redirects(node->content);
	node->left = make_redirect(split[0]);
	node->right = make_redirects(split[1]);
	free(split);
	free(s);
	return (node);
}

t_node	*make_redirect(char *s)
{
	t_node	*node;
	char	**split;

	if (s == NULL)
		return (NULL);
	node = malloc(sizeof(t_node));
	node->type = REDIRECT;
	node->content = ft_strtrim(s, " ");
	split = parse_redirect(node->content);
	node->left = make_type(split[0]);
	node->right = make_filename(split[1]);
	free(s);
	free(split);
	return (node);
}
