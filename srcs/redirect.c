#include "minishell.h"

int	input(char *s)
{
	int	fd;

	fd = open(s, O_RDONLY, 0644);
	dup2(fd, STDIN_FILENO);
	return (fd);
}

int	overwrite(char *s)
{
	int	fd;

	fd = open(s, O_RDWR | O_CREAT | O_TRUNC | O_SYNC, 0644);
	if (fd < 0)
		return (0);
	dup2(fd, STDOUT_FILENO);
	return (fd);
}

int	append(char *s)
{
	int	fd;

	fd = open(s, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
		return (0);
	dup2(fd, STDOUT_FILENO);
	return (fd);
}

int	double_left_redirect(char *s)
{
	char	*ret;
	char	*input;
	char	*tmp;

	ret = NULL;
	tmp = NULL;
	input = readline(">");
	while (ft_strcmp(input, s))
	{
		if (ret)
			tmp = ft_strjoin(ret, "\n");
		free(ret);
		ret = ft_strjoin(tmp, input);
		if (tmp)
			free(tmp);
		if (input)
			free(input);
		input = readline(">");
	}
	free(input);
	dup2(STDIN_FILENO, STDOUT_FILENO);
	free(s);
	write(1, ret, ft_strlen(ret));
	free(ret);
	return (STDIN_FILENO);
}
