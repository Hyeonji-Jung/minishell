#include "inc/minishell.h"

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
