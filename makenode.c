#include "inc/minishell.h"

t_node	*make_cmd(char *s)
{
	t_node	*node;
	char	**split;

	if (s == NULL)
		return (NULL);
	split = parse_redirects(s);
	node = malloc_s(sizeof(t_node));
	node->type = CMD;
	node->content = s;
	node->right = make_simplecmd(split[0]);
	node->left = make_redirect(split[1]);
	return (node);
}

t_node	*make_pipe(char *s)
{
	t_node	*node;
	char	**split;

	if (s == NULL)
		return (NULL);
	split = parse_pipe(s);
	node = malloc_s(sizeof(t_node));
	node->type = PIPE;
	node->content = s;
	node->left = make_cmd(split[0]);
	node->right = make_pipe(split[1]);
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
	node->content = s;
	split = parse_cmd(s);
	node->left = make_filepath(split[0]);
	node->right = make_argv(split[1]);
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
	node->content = s;
	node->left = make_redirect(split[0]);
	node->right = make_redirects(split[1]);
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
	node->content = s;
	split = parse_redirect(s);
	node->left = make_type(split[0]);
	node->right = make_filename(split[1]);
	return (node);
}
