#include "../minishell.h"

char	*pwd_(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	g_foreground = 0;
	return (path);
}
