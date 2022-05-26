#include "../inc/minishell.h"

void	cmd_exit(void)
{
	system("leaks minishell");
	exit(0);
}
