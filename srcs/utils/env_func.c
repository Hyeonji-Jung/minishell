/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:32:58 by junpkim           #+#    #+#             */
/*   Updated: 2022/06/07 16:32:59 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*search_env(t_env *env, char *s)
{
	t_env	*tmp;

	if (!env)
		return (0);
	tmp = env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, s))
			return (tmp);
		tmp = tmp->next;
	}
	return (0);
}

void	delete_env(t_env **env, char *s)
{
	t_env	*tmp;
	t_env	*del;

	tmp = *env;
	while (tmp->next != NULL && ft_strcmp(tmp->next->key, s))
		tmp = tmp->next;
	if (tmp->next == NULL)
		return ;
	del = tmp->next;
	tmp->next = tmp->next->next;
	free(del->key);
	free(del->value);
	free(del);
	unsetenv(s);
}

void	print_env(t_env **env)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp != NULL)
	{
		printf("%s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
}

t_env	*export_sort(t_env **env)
{
	char	*tmp;
	t_env	*sort;
	t_env	*cmp;
	t_env	*ret;

	sort = *env;
	ret = sort;
	while (sort != NULL)
	{
		cmp = sort;
		while (cmp != NULL)
		{
			if (ft_strcmp(sort->key, cmp->key) > 0)
			{
				tmp = sort->key;
				sort->key = cmp->key;
				cmp->key = tmp;
				tmp = sort->value;
				sort->value = cmp->value;
				cmp->value = tmp;
			}
			cmp = cmp->next;
		}
		sort = sort->next;
	}
	return (ret);
}

void	export_print(t_env **env)
{
	t_env	*tmp;

	tmp = export_sort(env);
	while (tmp != NULL)
	{
		printf("declare -x %s=\"%s\"\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
}
