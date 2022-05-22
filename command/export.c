#include "../inc/minishell.h"

int	cmd_export(char *s)
{
	return (putenv(s));
}
