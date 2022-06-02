#include "minishell.h"

int	chk_space(char *s)
{
	int	i;
	int	quote;
	int	dquote;

	i = -1;
	quote = 0;
	dquote = 0;
	while (s[++i])
	{
		if (s[i] == '\'')
			quote = !quote;
		else if (s[i] == '\"')
			dquote = !dquote;
		else if (s[i] == ' ' && !quote && !dquote)
			break ;
	}
	return (i);
}

char	**parse_simplecmd(char *s)
{
	char	**ret;
	int		loc;

	loc = chk_space(s);
	ret = malloc_s(sizeof(char *) * 2);
	if (loc == ft_strlen(s))
	{
		ret[0] = ft_strdup(s);
		ret[1] = ft_strdup(s);
	}
	else
	{
		ret[0] = ft_substr(s, 0, loc);
		ret[1] = ft_strdup(s);
	}
	return (ret);
}
