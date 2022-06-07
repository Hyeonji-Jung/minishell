#include "minishell.h"

int	chk_command(char *command)
{
	int	quote;
	int	d_quote;

	quote = 0;
	d_quote = 0;
	while (*command)
	{
		if (*command == '\'')
			quote++;
		if (*command == '\"')
			d_quote++;
		if (*command == '-' && !ft_isalpha(*(command + 1)))
			return (1);
		command++;
	}
	if (quote % 2 || d_quote % 2)
		return (1);
	return (0);
}

// void	exit_shell()

void	print_err(char *cmd, char *err)
{
	printf("minishell: %s: %s\n", cmd, err);
}

void	print_err_arg(char *cmd, char *err, char *arg)
{
	printf("minishell: %s: `%s\': %s\n", cmd, arg, err);
}
