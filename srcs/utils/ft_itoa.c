#include "minishell.h"

static int	get_length(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*b_zero(void)
{
	char	*ret;

	ret = malloc_s(sizeof(char) * 2);
	ret[0] = '0';
	ret[1] = '\0';
	return (ret);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		len;
	int		minus;

	if (n < 0)
	{
		minus = 1;
		n *= -1;
	}
	else if (n == 0)
		return (b_zero());
	len = get_length(n);
	ret = malloc_s(sizeof(char) * (len + 1));
	ret[len] = '\0';
	minus = 0;
	while (len-- > 0)
	{
		ret[len] = n % 10 + '0';
		n /= 10;
	}
	if (minus)
		ret[0] = '-';
	return (ret);
}
