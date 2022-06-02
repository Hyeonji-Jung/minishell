#include "minishell.h"

void	*malloc_s(int size)
{
	char	*p;

	p = malloc(size);
	if (!p)
		exit(1);
	return (p);
}
