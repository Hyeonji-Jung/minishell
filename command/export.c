#include "../inc/minishell.h"

int	cmd_export(t_env **env, char *s)
{
	new_env(env, s);
	return (0);
}
