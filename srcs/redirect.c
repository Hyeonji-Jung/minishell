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
