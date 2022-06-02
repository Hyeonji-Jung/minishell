/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:13:29 by hyeojung          #+#    #+#             */
/*   Updated: 2022/06/02 17:21:01 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "minishell.h"

typedef struct s_node
{
	int				type;
	char			*content;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_fd
{
	int			num;
	struct s_fd	*next;
}	t_fd;

typedef struct	s_info
{
	t_node	*tree;
	t_env	*env;
	int		fd;
//	t_fd	*fd;
	int		old_stdin;
	int		old_stdout;
}	t_info;

#endif
