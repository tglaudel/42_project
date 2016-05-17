/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_resolve.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 15:25:25 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/11 16:14:09 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	count_rooms(t_room *room)
{
	t_room	*tmp;
	int		i;

	i = 0;
	tmp = room;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

static int	count_tubes(t_tube *tube)
{
	t_tube	*tmp;
	int		i;

	i = 0;
	tmp = tube;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

static int	no_start_end(t_env *env)
{
	int		start;
	int		end;
	t_args	*tmp;

	start = 0;
	end = 0;
	tmp = env->a_start;
	while (tmp)
	{
		if (ft_strcmp(tmp->data, "##start") == 0)
			start++;
		else if (ft_strcmp(tmp->data, "##end") == 0)
			end++;
		tmp = tmp->next;
	}
	if (start != 1 || end != 1)
		return (1);
	return (0);
}

static int	one_start_end(t_env *env)
{
	t_room	*r_room;
	t_room	*e_room;
	t_room	*start;

	r_room = NULL;
	e_room = NULL;
	start = env->r_start;
	while (start)
	{
		if (start->start == 1)
			r_room = start;
		if (start->end == 1)
			e_room = start;
		start = start->next;
	}
	if (r_room == e_room)
		return (0);
	return (1);
}

void		check_resolve(t_env *env)
{
	if (count_rooms(env->r_start) < 2)
		error("ERROR : No room.");
	if (count_tubes(env->t_start) < 1)
		error("ERROR");
	if (no_start_end(env) == 1 || one_start_end(env) == 0)
		error("ERROR : start or end.");
}
