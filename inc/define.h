/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:38:57 by hyeojung          #+#    #+#             */
/*   Updated: 2022/05/12 18:39:47 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define PIPE 0
# define CMD 1
# define SIMPLECMD 2
# define REDIRECTS 3
# define REDIRECT 4
# define FILEPATH 5
# define ARGV 6
# define TYPE 7
# define FILENAME 8

/*
PIPE ->         left: CMD,                   right: PIPE
CMD ->          left: REDIRECTS,             right: SIMPLECMD
SIMPLECMD ->    left: file_path,             right: ARGV
REDIRECTS ->    left: REDIRECT or REDIRECTS  right: REDIRECT or REDIRECTS
REDIRECT ->     left: type,                  right: file_name
*/

#endif
