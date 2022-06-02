#include "minishell.h"

int cmd_echo(char **strs)
{
    int		i;
	int		n_option;

	i = -1;
	n_option = 0;
	while (strs[++i])
	{
		while (strs[i] && ft_strcmp(strs[i], "-n") == 0)
		{
			n_option = 1;
			i++;
		}
		while (strs[i])
		{
			printf("%s", strs[i]);
			if (strs[i + 1] && strs[i][0] != '\0')
				write(1, " ", 1);
			i++;
		}
	}
	if (n_option == 0)
		write(1, "\n", 1);
	return (0);
}
