#include "../inc/minishell.h"

void	cmd_echo(char *s)
{
	int		i;
	char	**split;

	split = ft_split(s, ' ');
	if (!ft_strcmp(split[1], "-n"))
		i = 1;
	
	else
		i = 0;
	while (split[++i])
	{
		printf("%s", split[i]);
		if (split[i + 1])
			printf(" ");
	}
	if (ft_strcmp(split[1], "-n"))
		printf("\n");
	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}
