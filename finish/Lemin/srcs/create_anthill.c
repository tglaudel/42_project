/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_anthill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 16:17:37 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/09 17:26:09 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	count_connect(char *s, t_tube *tubes)
{
	t_tube	*tmp;
	int		i;

	i = 0;
	tmp = tubes;
	while (tmp)
	{
		if (ft_strcmp(s, tmp->name_a) == 0 || ft_strcmp(s, tmp->name_b) == 0)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

static void	add_connect(t_room *room, t_env *env, char *s, int i)
{
	t_room	*room_tmp;

	room_tmp = env->r_start;
	while (room_tmp)
	{
		if (ft_strcmp(room_tmp->name, s) == 0)
			room->tab[i] = room_tmp;
		room_tmp = room_tmp->next;
	}
}

static void	create_connect(t_room *room, t_env *env)
{
	t_tube	*tube_tmp;
	int		i;

	i = 0;
	tube_tmp = env->t_start;
	room->tab = (t_room**)malloc(sizeof(t_room*) * room->connect + 1);
	while (tube_tmp)
	{
		if (ft_strcmp(room->name, tube_tmp->name_a) == 0)
		{
			add_connect(room, env, tube_tmp->name_b, i);
			i++;
		}
		else if (ft_strcmp(room->name, tube_tmp->name_b) == 0)
		{
			add_connect(room, env, tube_tmp->name_a, i);
			i++;
		}
		tube_tmp = tube_tmp->next;
	}
	room->tab[i] = NULL;
}

void		create_anthill(t_env *env)
{
	t_room	*tmp;

	tmp = env->r_start;
	while (tmp)
	{
		tmp->connect = count_connect(tmp->name, env->t_start);
		create_connect(tmp, env);
		tmp = tmp->next;
	}
}
