#include "inc/minishell.h"

int	cmd_execute(t_env **env, char *cmd, char *option)
{
	if (!ft_strcmp(cmd, "echo"))
		;
	else if (!ft_strcmp(cmd, "cd"))
		;
	else if (!ft_strcmp(cmd, "pwd"))
		cmd_pwd();
	else if (!ft_strcmp(cmd, "env"))
		cmd_env(*env);
	else if (!ft_strcmp(cmd, "export"))
		cmd_export(env, option);
	else if (!ft_strcmp(cmd, "unset"))
		cmd_unset(env, option);
	else if (!ft_strcmp(cmd, "exit"))
		cmd_exit();
	else
		system(ft_strjoin(ft_strjoin(cmd, " "), option));
	return (0);
}
