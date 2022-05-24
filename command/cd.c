#include "../inc/minishell.h"

int	cmd_cd(char *s)
{
	g_foreground = chdir(s);
	return (g_foreground);
}
