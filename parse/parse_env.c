#include "../inc/minishell.h"

static int	key_length(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '$' || s[i] == '\"')
			break ;
		i++;
	}
	return (i);
}

char	*convert_env(char *s1, char *s2)
{
	char		*ret;
	const int	s1_len = ft_strlen(s1);
	const int	s2_len = ft_strlen(s2);
	int			i;

	if (s2_len == 0)
		return (s1);
	ret = malloc_s(sizeof(char) * (s1_len + s2_len + 1));
	ret[s1_len + s2_len] = '\0';
	i = 0;
	while (i < s1_len)
	{
		ret[i] = s1[i];
		i++;
	}
	while (i - s1_len < s2_len)
	{
		ret[i] = s2[i - s1_len];
		i++;
	}
	return (ret);
}

void	before_env(char **ret, char *s, int save, int i)
{
	char	*tmp;
	char	*tmp1;

	tmp = ft_substr(s, save, i - save);
	tmp1 = convert_env(*ret, tmp);
	if (*ret && tmp1 != *ret)
		free(*ret);
	*ret = tmp1;
	free(tmp);
}

void	after_env(char **ret, char *s, int i, int key_len)
{
	char	*tmp;
	char	*tmp1;

	tmp = ft_substr(&s[i + 1], 0, key_len);
	tmp1 = getenv(tmp);
	free(tmp);
	tmp = convert_env(*ret, tmp1);
	if (*ret != tmp)
		free(*ret);
	*ret = tmp;
}

char	*parse_env(char *s)
{
	int		quote;
	int		i;
	int		save;
	int		key_len;
	char	*ret;

	if (!s)
		return (0);
	ret = NULL;
	quote = 0;
	i = -1;
	save = 0;
	while (s[++i])
	{
		if (s[i] == '\'')
			quote = !quote;
		else if (s[i] == '$' && !quote)
		{
			key_len = key_length(&s[i + 1]);
			before_env(&ret, s, save, i);
			after_env(&ret, s, i, key_len);
			save = i + key_len + 1;
			i += key_len;
		}
	}
	before_env(&ret, s, save, i);
	return (ret);
}
