#include "../inc/minishell.h"

void	cmd_pwd(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	printf("%s\n", path);
	free(path);
	g_foreground = 0;
}
