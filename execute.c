#include "inc/minishell.h"

/*
static char	*split_space(char *s)
{
	char	**ret;
	int		i;

	ret = malloc_s(sizeof(char *) * cnt_len(s));
	i = 0;
	while (i < cnt_len(s))
	{

	}
*/
int	cmd_execute(t_env **env, char *cmd, char *option)
{
	char	**split;

	split = ft_split(option, ' ');
	if (!ft_strcmp(cmd, "echo"))
		;
	else if (!ft_strcmp(cmd, "cd"))
		cmd_cd(split[1]);
	else if (!ft_strcmp(cmd, "pwd"))
		cmd_pwd();
	else if (!ft_strcmp(cmd, "env"))
		cmd_env(*env);
	else if (!ft_strcmp(cmd, "export"))
		cmd_export(env, split[1]);
	else if (!ft_strcmp(cmd, "unset"))
		cmd_unset(env, split[1]);
	else if (!ft_strcmp(cmd, "exit"))
		cmd_exit();
	else
		system(option);
	return (0);
}
