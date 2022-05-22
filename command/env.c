#include "../inc/minishell.h"

int	cmd_env(t_env *env)
{
	print_env(&env);
	return (0);
}
