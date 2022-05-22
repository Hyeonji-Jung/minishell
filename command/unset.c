#include "../inc/minishell.h"

int	cmd_unset(t_env **env, char *s)
{
	delete_env(env, s);
	return (0);
}
