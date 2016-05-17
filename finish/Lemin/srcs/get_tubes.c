/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tubes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 13:30:53 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/11 14:29:55 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	add_tube(t_env *env, char **s)
{
	t_tube *tmp;

	if (!(tmp = (t_tube*)malloc(sizeof(t_tube))))
		error("Error malloc");
	if (env->t_start == NULL)
		env->t_start = tmp;
	tmp->name_a = ft_strdup(s[0]);
	tmp->name_b = ft_strdup(s[1]);
	tmp->next = NULL;
	if (env->t_end != NULL)
		env->t_end->next = tmp;
	env->t_end = tmp;
	free_tab(s);
}

void		get_tubes(t_env *env)
{
	t_args		*tmp;

	tmp = env->a_start;
	while (tmp)
	{
		if (is_tube(tmp, env) != -1)
			add_tube(env, ft_strsplit(tmp->data, '-'));
		else if (tmp->data[0] == '#' && tmp->data[1] != '#')
			add_com(env, tmp->data);
		else if (is_command(tmp) != 1 && is_ants(tmp, env) != 1 && \
		is_room(tmp, env, 0) != 1)
			break ;
		tmp = tmp->next;
		env->n_map++;
	}
}
