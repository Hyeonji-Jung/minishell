#include "../inc/minishell.h"

char **parse_redirects(char *s)
{
	char	**ret;
	int		i;

	i = 1;
	ret = malloc_s(sizeof(char *) * 2);
	while (s[++i])
	{
		if (s[i] == '<' || s[i] == '>')
			break;
	}
	ret[0] = ft_substr(s, 0, i);
	if (ft_strlen(s) > i)
		ret[1] = ft_substr(s, i, ft_strlen(s) - i);
	else
		ret[1] = NULL;
	return (ret);
}
