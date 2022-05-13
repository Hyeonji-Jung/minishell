#include "inc/minishell.h"

t_node	*make_cmd(char *s)
{
	t_node	*node;
	char	**split;

	if (s == NULL)
		return (NULL);
	node = malloc(sizeof(t_node));
	node->type = CMD;
	node->content = s;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

t_node	*make_pipe(char *s)
{
	t_node	*node;
	char	**split;

	if (s == NULL)
		return (NULL);
	split = pipe_split(s);
	node = malloc(sizeof(t_node));
	node->type = PIPE;
	node->content = NULL;
	node->left = make_cmd(split[0]);
	node->right = make_pipe(split[1]);
	return (node);
}
