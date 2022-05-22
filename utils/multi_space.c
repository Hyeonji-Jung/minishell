#include "../inc/minishell.h"

int	flag_space(int quote, int dquote, char c)
{
	if (!quote && !dquote && c == ' ')
		return (1);
	else
		return (0);
}

static int	cnt_len(char *s)
{
	int	i;
	int	quote;
	int	dquote;
	int	cnt;
	int	space;

	i = -1;
	quote = 0;
	dquote = 0;
	cnt = 0;
	space = 0;
	while (s[++i])
	{
		if (s[i] == ' ' && space == 1)
			continue ;
		if (s[i] == '\'')
			quote = !quote;
		else if (s[i] == '\"')
			dquote = !dquote;
		space = flag_space(quote, dquote, s[i]);
		cnt++;
	}
	return (cnt);
}

static void	insert_char(char *s, char c, int len)
{
	static int	cnt;

	s[cnt++] = c;
	if (len == cnt)
		cnt = 0;
}

char	*multi_space(char *s)
{
	int		i;
	int		quote;
	int		dquote;
	int		space;
	char	*ret;

	i = -1;
	quote = 0;
	dquote = 0;
	ret = malloc_s(sizeof(char) * (cnt_len(s) + 1));
	ret[cnt_len(s)] = '\0';
	while (s[++i])
	{
		if (s[i] == ' ' && space == 1)
			continue ;
		if (s[i] == '\'')
			quote = !quote;
		else if (s[i] == '\"')
			dquote = !dquote;
		space = flag_space(quote, dquote, s[i]);
		insert_char(ret, s[i], cnt_len(s));
	}
	return (ret);
}
