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

t_env	*make_new(char **split)
{
	t_env	*ret;

	ret = malloc_s(sizeof(t_env));
	ret->key = split[0];
	ret->value = split[1];
	ret->next = NULL;
	return (ret);
}

void	new_env(t_env **env, char *s)
{
	t_env	*new_node;
	t_env	*tmp;
	char	**split;

	split = env_split(s);
	if (!split)
		return ;
	if (*env != NULL)
	{
		tmp = *env;
		tmp = search_env(*env, split[0]);
		if (tmp)
		{
			tmp->value = split[1];
			return ;
		}
		free(tmp);
		tmp = *env;
		while (tmp->next != NULL)
			tmp = tmp->next;
	}
	new_node = make_new(split);
	if (*env == NULL)
		*env = new_node;
	else
		tmp->next = new_node;
	free(split);
}

t_env	*env_init(char **s)
{
	t_env	*env;
	int		i;

	i = 0;
	env = NULL;
	while (s[i])
	{	
		new_env(&env, s[i]);
		i++;
	}
	return (env);
}
