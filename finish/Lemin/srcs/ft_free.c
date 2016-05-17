/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 17:46:36 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/11 14:20:43 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		free_all_tube(t_env *env)
{
	t_tube		*tmp;

	while (env->t_start)
	{
		tmp = env->t_start->next;
		ft_strdel(&env->t_start->name_a);
		ft_strdel(&env->t_start->name_b);
		free(env->t_start);
		env->t_start = NULL;
		env->t_start = tmp;
	}
}

void		free_all_room(t_env *env)
{
	t_room		*tmp;
	int			i;

	while (env->r_start)
	{
		i = -1;
		tmp = env->r_start->next;
		ft_strdel(&env->r_start->name);
		free(env->r_start->tab);
		env->r_start->tab = NULL;
		free(env->r_start);
		env->r_start = tmp;
	}
}

void		free_all_args(t_env *env)
{
	t_args		*tmp;

	while (env->a_start)
	{
		tmp = env->a_start->next;
		ft_strdel(&env->a_start->data);
		free(env->a_start);
		env->a_start = NULL;
		env->a_start = tmp;
	}
}

void		free_all(t_env *env)
{
	free_all_args(env);
	free_all_room(env);
	free_all_tube(env);
}
