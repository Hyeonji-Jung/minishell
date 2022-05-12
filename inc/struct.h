/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:13:29 by hyeojung          #+#    #+#             */
/*   Updated: 2022/05/12 18:23:05 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_node
{
	int		type;
	char	*content;
	t_node	*left;
	t_node	*right;
}	t_node;

typedef struct	s_tree
{
	t_node	*node;
}	t_tree;

#endif
