/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:38:57 by hyeojung          #+#    #+#             */
/*   Updated: 2022/05/22 16:59:48 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <dirent.h>
# include <term.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <sys/ioctl.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "define.h"
# include "struct.h"

int	g_foreground;

char	*ft_substr(char *s, int start, int len);
int		ft_strlen(char *s);
void	*malloc_s(int size);
int		ft_strncmp(char *s1, char *s2, int n);
char	*delete_space(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*multi_space(char *s);

int		signal_catch(int sig);

char	**parse_pipe(char *s);
char	**parse_redirect(char *s);
char	**parse_redirects(char *s);
char	**parse_cmd(char *s);
char	**parse_simplecmd(char *s);

t_node	*make_cmd(char *s);
t_node	*make_pipe(char *s);
t_node	*make_simplecmd(char *s);
t_node	*make_redirect(char *s);
t_node	*make_redirects(char *s);

t_node	*make_type(char *s);
t_node	*make_filename(char *s);
t_node	*make_filepath(char *s);
t_node	*make_argv(char *s);

void	cmd_exit(void);
int		cmd_env(char *env[]);
int		cmd_export(char *s);
int		cmd_unset(char *s);

#endif
