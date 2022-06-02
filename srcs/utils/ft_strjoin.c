#include "minishell.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	int		n;
	int		m;
	int		i;

	if (s1 == NULL && s2 == NULL)
		return (0);
	if (s1 == NULL)
		return (s2);
	if (s2 == NULL)
		return (s1);
	n = ft_strlen(s1);
	m = ft_strlen(s2);
	ret = malloc(sizeof(char) * (n + m + 1));
	if (ret == NULL)
		return (0);
	i = -1;
	while (++i < n)
		ret[i] = s1[i];
	i = -1;
	while (++i < m)
		ret[n + i] = s2[i];
	ret[n + i] = '\0';
	return (ret);
}
