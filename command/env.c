#include "../inc/minishell.h"

int	cmd_env(char *env[])
{
	int	i;

	i = -1;
	while (env[++i])
		printf("%s\n", env[i]);
	return (0);
}
