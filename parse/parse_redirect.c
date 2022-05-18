#include "../inc/minishell.h"

char	**parse_redirect(char *s)
{
	char	**ret;
	int		loc;

	if (s[0] == '<')
	{
		if (s[1] == '<')
			loc = 2;
		else
			loc = 1;
	}
	else if (s[0] == '>')
	{
		if (s[1] == '>')
			loc = 2;
		else
			loc = 1;
	}
	ret[0] = ft_substr(s, 0, loc);
	ret[1] = ft_substr(s, loc, ft_strlen(s) - loc);

	return (ret);	
}
