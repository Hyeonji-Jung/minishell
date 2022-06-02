#include "minishell.h"

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

	split = ft_split(option, ' '); // 스페이스 말고 공백문자로 수정 필요
	if (!ft_strcmp(cmd, "echo"))
		cmd_echo(split);
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
		system(option); // system 함수가 사용가능한 함수 목록에 없어서 바꿔야 할 거 같음
	return (0);
}
