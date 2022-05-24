int	ft_strncmp(char *s1, char *s2, int n)
{
	int	a;

	a = 0;
	while (a < n && (s1[a] || s2[a]))
	{
		if (s1[a] != s2[a])
			return ((unsigned char)s1[a] - (unsigned char)s2[a]);
		a++;
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	a;

	a = 0;
	while (s1[a] || s2[a])
	{
		if (s1[a] != s2[a])
			return ((unsigned char)s1[a] - (unsigned char)s2[a]);
		a++;
	}
	return (0);
}
