#include "minishell.h"

static void	free_s(char **s)
{
	int	i;

	i = -1;
	while (s[++i])
		free(s[i]);
	free(s);
}

int	cmd_export(t_env **env, char *s)
{
	char	**tmp;
	
	if (s == NULL)
	{
		export_print(env);
		g_foreground = 0;
		return (0);
	}
	tmp = ft_split(s, '=');
	if (!ft_isalpha(tmp[0][0]) || !tmp[1])
	{
		print_err_arg("export", "not a valid identifier", s);
		g_foreground = 1;
		free_s(tmp);
		return (0);
	}
	putenv(s);
	new_env(env, s);
	g_foreground = 0;
	return (0);
}
