#include "minishell.h"

static int	ft_isnum(char *s)
{
	int	i;

	i = -1;
	if (s[0] == '-')
		i++;
	while (s[++i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			continue ;
		else
			return (0);
	}
	return (1);
}

void	cmd_exit(t_info **info, char **s)
{
	/*
	* 여기에서 고려해야 할 것 - 아름다운 마무리
	* 프로그램 종료 경우가 여러 가지 있음! signal(Ctrl-D), exit 명령어
	* 이때 내부적으로 어떻게 다르게 처리할지 고민해 보자 !
	*/
	if (info)
		free_env(&(*info)->env);
	system("leaks minishell");
	if (!s)
		exit(0);
	else
	{
		if (ft_isnum(*s))
			exit((unsigned char)ft_atoi(*s));
		else
		{
			print_err("exit", ft_strjoin(*s, ": numeric argument required"));
			exit(255);
		}
	}
}
