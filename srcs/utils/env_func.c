#include "minishell.h"

char	**env_split(char *s)
{
	char	**ret;
	int		i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == '=')
			break ;
	}
	if (ft_strlen(s) == i)
		return (0);
	ret = malloc_s(sizeof(char *) * 2);
	ret[0] = ft_substr(s, 0, i);
	ret[1] = ft_substr(s, i + 1, ft_strlen(s) - i);
	return (ret);
}

void	new_env(t_env **env, char *s)
{
	t_env	*new_node;
	t_env	*tmp;

	if (!env_split(s))
		return ;
	if (*env != NULL)
	{
		tmp = *env;
		while (tmp->next != NULL)
		{
			if (!ft_strcmp(tmp->key, env_split(s)[0]))
			{
				tmp->value = env_split(s)[1];
				return ;
			}
			tmp = tmp->next;
		}
	}
	new_node = malloc_s(sizeof(t_env));
	new_node->key = env_split(s)[0];
	new_node->value = env_split(s)[1];
	new_node->next = NULL;
	if (*env == NULL)
		*env = new_node;
	else
		tmp->next = new_node;
}

char	*search_env(t_env *env, char *s)
{
	t_env	*tmp;

	tmp = env;
	while (!tmp->next)
	{
		if (!ft_strcmp(tmp->key, s))
			return (tmp->key);
		tmp = tmp->next;
	}
	return (0);
}

void	delete_env(t_env **env, char *s)
{
	t_env	*tmp;
	t_env	*del;

	tmp = *env;
	while (ft_strcmp(tmp->next->key, s))
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
