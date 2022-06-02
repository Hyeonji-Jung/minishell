#include "minishell.h"

int	cmd_export(t_env **env, char *s)
{
	if (s == NULL) // 이 경우 모든 환경변수를 표시해야 함
	{
		print_env(env);
		g_foreground = 1;
		return (1);
	}
	new_env(env, s);
	g_foreground = 0;
	return (0);
}
