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

static void	free_s(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

int	cmd_execute(t_info **info, char *cmd, char *option)
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
		cmd_env((*info)->env);
	else if (!ft_strcmp(cmd, "export"))
		cmd_export(&(*info)->env, split[1]);
	else if (!ft_strcmp(cmd, "unset"))
		cmd_unset(&(*info)->env, split[1]);
	else if (!ft_strcmp(cmd, "exit"))
	{
		free_env(&(*info)->env);
		cmd_exit();
	}
	else
		system(option);
	free_s(split);
	return (0);
}

int	redirect_execute(t_info **info, char *type, char *file_name)
{
	int	fd;

	if (!type || !file_name)
		return (-1);
	if (!ft_strcmp(type, "<"))
		fd = input(file_name);
	else if (!ft_strcmp(type, ">"))
		fd = overwrite(file_name);
	else if (!ft_strcmp(type, ">>"))
		fd = append(file_name);
//	if (fd < 0)
		//error
	return (fd);
}
