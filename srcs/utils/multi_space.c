#include "minishell.h"

static int	flag_space(char c)
{
	static int	dquote;
	static int	quote;
	static int	space;

	if (c == 0)
	{
		quote = 0;
		dquote = 0;
		space = 0;
		return (0);
	}
	if (c == ' ' && space == 1)
		return (0);
	else if (c == ' ' || space == 1)
		space = !space;
	if (c == '\'')
		quote = !quote;
	else if (c == '\"')
		dquote = !dquote;
	return (1);
}

static int	cnt_len(char *s)
{
	int	i;
	int	cnt;

	if (!s)
		return (0);
	i = -1;
	cnt = 0;
	while (s[++i])
	{
		if (flag_space(s[i]))
			cnt++;
	}
	flag_space(0);
	return (cnt);
}

static void	insert_char(char *s, char c, int len)
{
	static int	cnt;

	s[cnt++] = c;
	if (len == cnt)
	{
		cnt = 0;
	}
}

char	*multi_space(char *s)
{
	int		i;
	int		len;
	char	*ret;

	if (!s)
		return (0);
	len = cnt_len(s);
	i = -1;
	ret = malloc_s(sizeof(char) * (len + 1));
	ret[len] = '\0';
	while (s[++i])
	{
		if (flag_space(s[i]))
			insert_char(ret, s[i], len);
	}
	flag_space(0);
	return (ret);
}
