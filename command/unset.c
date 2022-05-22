#include "../inc/minishell.h"

int	cmd_unset(char *s)
{
	return (unsetenv(s));
}
