#include "minishell.h"

static char	*choose(int n)
{
	if (n == 0)
		return (ft_strdup("minishell > "));
	else if (n == 1)
		return (ft_strdup("quote > "));
	else if (n == 2)
		return (ft_strdup("dquote > "));
	else if (n == 0)
		return (ft_strdup("> "));
	return (0);
}

static int	chk_read(char *s)
{
	int		quote;
	int		dquote;
//	int		pipe;
	int		i;
	int		slash;

	quote = 0;
	dquote = 0;
//	pipe = 0;
	slash = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] == '\'' && !dquote && slash % 2 == 0)
			quote = !quote;
		else if (s[i] == '\"' && !quote && slash % 2 == 0)
			dquote = !dquote;
		if (s[i] == '\\')
			slash++;
		else
			slash = 0;
	}
	if (quote)
		return (1);
	else if (dquote)
		return (2);
	else if (slash % 2 == 1)
		return (3);
	else
		return (0);
}

void	add_newline(char **ret)
{
	char	*tmp;

	tmp = ft_strjoin(*ret, "\n");
	free(*ret);
	*ret = tmp;
}

char	*read_line(void)
{
	char	*s;
	char	*ret;
	char	*tmp1;
	char	*tmp;

	s = choose(0);
	ret = NULL;
	while (1)
	{
		tmp = readline(s);
		if (!tmp)
			break ;
		tmp1 = ft_strjoin(ret, tmp);
		free(tmp);
		tmp = NULL;
		if (ret)
			free(ret);
		ret = tmp1;
		free(s);
		s = choose(chk_read(ret));
		if (!chk_read(ret))
			break ;
		add_newline(&ret);
	}
	free(s);
	return (ret);
}
