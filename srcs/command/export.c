#include "minishell.h"

int	cmd_export(t_env **env, char *s)
{
	if (s == NULL)
	{
		export_print(env);
		g_foreground = 0;
		return (0);
	}
	putenv(s);
	new_env(env, s);
	g_foreground = 0;
	return (0);
}
