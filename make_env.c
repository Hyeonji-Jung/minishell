#include "inc/minishell.h"

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
