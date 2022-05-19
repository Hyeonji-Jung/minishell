#include "../inc/minishell.h"

int chk_space(char *s)
{
    int i;
    int quote;
    int dquote;

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

int	last_space(char *s)
{
	int	i;

	i = -1;
	while (s[++i] == ' ')
		;
	return (i);
}

char    **parse_simplecmd(char *s)
{
    char    **ret;
    int     loc;
	char	*tmp;

	loc = chk_space(s);
    ret = malloc_s(sizeof(char *) * 2);
	if (loc == ft_strlen(s))
	{
		ret[0] = s;
		ret[1] = NULL;
	}
	else
	{
		ret[0] = ft_substr(s, 0, loc);
		ret[1] = s;
//		ret[1] = ft_substr(s, loc + last_space(&s[loc]) - 1, ft_strlen(s) - loc - last_space(&s[loc]) + 1);
//		tmp = ft_strjoin(ret[0], ret[1]);
//		free(ret[1]);
//		ret[1] = tmp;
	}
    return (ret);
}
