#include "minishell.h"

int	cmd_unset(t_env **env, char *s)
{
	if (s == NULL)
	{
		g_foreground = 1;
		return (1);
	}
	delete_env(env, s);
	g_foreground = 0;
	return (0);
}
