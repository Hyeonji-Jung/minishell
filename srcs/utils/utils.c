#include "minishell.h"

int	get_len(char *s)
{
	int	ret;
	int	i;

	i = -1;
	ret = ft_strlen(s);
	while (++i < ft_strlen(s))
	{
		if (s[i] == ' ')
			ret--;
	}
	return (ret);
}

char	*delete_space(char *s)
{
	char	*ret;
	int		i;
	int		j;

	ret = malloc(sizeof(char) * (get_len(s) + 1));
	ret[get_len(s)] = '\0';
	i = -1;
	j = 0;
	while (++i < ft_strlen(s))
	{
		if (s[i] != ' ')
			ret[j++] = s[i];
	}
	return (ret);
}
