#include "minishell.h"

static void	case1(char **ret, char *s, int i)
{
	char	*add;
	char	*tmp;

	add = ft_substr(s, i + 2, 1);
	tmp = ft_strjoin(*ret, add);
	free(*ret);
	free(add);
	*ret = tmp;
}

static void	case2(char **ret, char *s, int i)
{
	char	*add;
	char	*tmp;

	add = ft_substr(s, i, 3);
	tmp = ft_strjoin(*ret, add);
	free(*ret);
	*ret = ft_strjoin(tmp, "; ");
	free(tmp);
	free(add);
}`

static void case3(char **ret, char *s, int i)
{
	char	*add;
	char	*tmp;

	add = ft_substr(s, i, 1);
	tmp = ft_strjoin(*ret, add);
	free(*ret);
	*ret = tmp;
	free(add);
}

char	*parse_history(char *s)
{
	char	*ret;
	char	*add;
	char	*tmp;
	int		i;

	i = -1;
	ret = NULL;
	while (s[++i])
	{
		if (s[i] == '\\')
		{
			if (s[i + 1] == '\n')
			{
				case1(&ret, s, i);
				i += 2;
			}
			else if (s[i + 1] == '\\' && s[i + 2] == '\\')
			{
				case2(&ret, s, i);
				i += 3;
			}
		}
		else
			case3(&ret, s, i);
	}
	return (ret);
}

int main(int argc, char *argv[])
{
	char *s;
	char	*p;

	while (1)
	{
		s = readline("> ");
		p = parse_history(s);
		printf("%s\t%s\n",s, p);
	}
	system("leaks a.out");
}
