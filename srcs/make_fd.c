#include "minishell.h"

void	new_fd(t_fd **fd, int add_fd)
{
	t_fd	*ret;
	t_fd	*tmp;

	ret = malloc_s(sizeof(t_fd));
	ret->num = add_fd;
	ret->next = NULL;
	if (*fd == NULL)
		*fd = ret;
	else
	{
		tmp = *fd;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = ret;
	}
}
