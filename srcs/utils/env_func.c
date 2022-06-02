#include "minishell.h"


t_env	*search_env(t_env *env, char *s)
{
	t_env	*tmp;

	if (!env)
		return (0);
	tmp = env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, s))
			return (tmp);
		tmp = tmp->next;
	}
	return (0);
}

void	delete_env(t_env **env, char *s)
{
	t_env	*tmp;
	t_env	*del;

	tmp = *env;
	while (tmp->next != NULL && ft_strcmp(tmp->next->key, s))
		tmp = tmp->next;
	if (tmp->next == NULL)
		return ;
	del = tmp->next;
	tmp->next = tmp->next->next;
	free(del->key);
	free(del->value);
	free(del);
	unsetenv(s);
}

void	print_env(t_env **env)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp != NULL)
	{
		printf("%s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
}
