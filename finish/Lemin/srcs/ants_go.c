/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_go.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 14:36:27 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/11 16:03:28 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void			push_ants(t_env *env, t_result *res_end, t_result *res)
{
	t_ants	*ant;

	ant = env->ant_start;
	while (ant)
	{
		if (ant->res != res_end)
		{
			if (ant->res->next == res_end || ant->res->next->room->ants == 0)
			{
				ant->res->room->ants = 0;
				ant->res = ant->res->next;
				ant->res->room->ants = 1;
				if (ant->res->room == res_end->room)
					env->end_ants++;
				(env->opt & O_COLOR) ? ft_color(ant->id_ants) : 0;
				ft_printf("L%d-%s ", ant->id_ants, ant->res->room->name);
				ft_color(0);
				if (res->next == res_end)
					break ;
			}
		}
		ant = ant->next;
	}
	ft_putchar('\n');
}

static void			create_ants(t_env *env, t_result *res, int i)
{
	t_ants *tmp;

	if (!(tmp = (t_ants*)malloc(sizeof(t_ants))))
		error("Error malloc");
	if (env->ant_start == NULL)
		env->ant_start = tmp;
	tmp->res = res;
	tmp->id_ants = i;
	tmp->next = NULL;
	if (env->ant_end != NULL)
		env->ant_end->next = tmp;
	env->ant_end = tmp;
}

static t_result		*find_short_way(t_env *env)
{
	t_sol		*tmp;
	t_result	*res;
	int			i;

	tmp = env->sol_start;
	if (tmp)
	{
		i = tmp->nb_op;
		res = tmp->res_s;
	}
	while (tmp != NULL)
	{
		if (tmp->nb_op < i)
			res = tmp->res_s;
		tmp = tmp->next;
	}
	return (res);
}

void				ants_go(t_env *env)
{
	t_result	*res;
	t_result	*res_end;
	t_result	*tmp;
	int			i;

	i = 0;
	if (env->sol_start == NULL)
		error("ERROR : No way.");
	print_map(env);
	(env->opt & O_ROOM) ? print_rooms(env) : 0;
	res = find_short_way(env);
	tmp = res;
	while (tmp->next != NULL)
		tmp = tmp->next;
	res_end = tmp;
	while (++i <= env->ants)
		create_ants(env, res, i);
	while (env->end_ants < env->ants)
		push_ants(env, res_end, res);
}
