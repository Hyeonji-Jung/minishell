#include "minishell.h"

char	*cmd_pwd(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	if (path)
	{
		printf("%s\n", path);
		g_foreground = 0;
		return (path);
	}
	else
		return (NULL);
}