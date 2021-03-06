/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:38:57 by hyeojung          #+#    #+#             */
/*   Updated: 2022/06/07 16:01:57 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <dirent.h>
# include <term.h>
# include <termios.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <signal.h>
# include <fcntl.h>
# include <errno.h>
# include <limits.h>
# include <sys/ioctl.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "define.h"
# include "struct.h"

int     g_foreground;

char	*ft_substr(char *s, int start, int len);
int		ft_strlen(char *s);
void	*malloc_s(int size);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, int n);
char	*delete_space(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*multi_space(char *s);
char	**ft_split(char *s, char c);
int     ft_isalpha(char c);
void	free_tree(t_node **node);
void	free_env(t_env **env);
char	*ft_itoa(int n);
char	*ft_strdup(char *src);
char	*ft_strnstr(char *str, char *find, int size);
int		ft_atoi(char *s);

void	signal_catch(int sig);

char	**parse_pipe(char *s);
char	**parse_redirect(char *s);
char	**parse_redirects(char *s);
char	**parse_cmd(char *s);
char	**parse_simplecmd(char *s);
int		parse_env(char *s, char **ret, t_env *env);
char	*parse_history(char *s);
char    *parse_input(char *s);

t_node	*make_cmd(char *s);
t_node	*make_pipe(char *s);
t_node	*make_simplecmd(char *s);
t_node	*make_redirect(char *s);
t_node	*make_redirects(char *s);

t_node	*make_type(char *s);
t_node	*make_filename(char *s);
t_node	*make_filepath(char *s);
t_node	*make_argv(char *s);

char	**env_split(char *s);
void	new_env(t_env **env, char *s);
t_env	*search_env(t_env *env, char *s);
void	delete_env(t_env **env, char *s);
void	print_env(t_env **env);
void	export_print(t_env **env);
t_env	*env_init(char **s);

void    cmd_pwd(void);
void	cmd_exit(t_info **info, char **s);
int		cmd_env(t_env *env);
int		cmd_export(t_env **env, char *s);
int		cmd_unset(t_env **env, char *s);
int		cmd_cd(char *s);
int     cmd_echo(char **strs);
void    cmd_bin(char *command, char **split, char **envp);

void	node_convert(t_info **info, t_node **node);
void	new_process(t_info **info, t_node *node);
void	node_execute(t_info **info, t_node *node);
int		cmd_execute(t_info **info, char *cmd, char *option);
int		redirect_execute(char *type, char *file_name);

int		input(char *s);
int		overwrite(char *s);
int		append(char *s);
int		double_left_redirect(char *s);

char	*read_line(void);
void	new_fd(t_fd **fd, int new_fd);

int     chk_command(char *command);
void	print_err(char *cmd, char *err);
void	print_err_arg(char *cmd, char *err, char *arg);

#endif
