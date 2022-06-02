#include "minishell.h"

int cmd_echo(char **strs)
{
    int		i;

	if (!ft_strcmp(strs[1], "-n"))
		i = 1;
	else
		i = 0;
	while (strs[++i])
	{
		printf("%s", strs[i]);
		if (strs[i + 1])
			printf(" ");
	}
	if (ft_strcmp(strs[1], "-n"))
		printf("\n");
	return (0);
}
