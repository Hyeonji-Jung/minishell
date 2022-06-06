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
