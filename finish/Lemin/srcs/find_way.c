/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_way.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 18:08:43 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/11 14:29:33 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		check_result(t_env *env)
{
	t_sol		*sol_tmp;
	t_result	*res_tmp;
	t_result	*env_res_tmp;

	sol_tmp = env->sol_start;
	if (sol_tmp == NULL)
		return (1);
	while (sol_tmp)
	{
		res_tmp = sol_tmp->res_s;
		env_res_tmp = env->res_start;
		while (env_res_tmp && res_tmp && env_res_tmp->room == res_tmp->room)
		{
			env_res_tmp = env_res_tmp->next;
			res_tmp = res_tmp->next;
		}
		if (env_res_tmp == NULL && res_tmp == NULL)
			return (0);
		sol_tmp = sol_tmp->next;
	}
	return (1);
}

static void		add_sol(t_env *env)
{
	t_sol *sol;

	if (!(sol = (t_sol*)malloc(sizeof(t_sol))))
		error("Error malloc");
	if (env->sol_start == NULL)
		env->sol_start = sol;
	sol->res_s = env->res_start;
	sol->res_e = env->res_end;
	sol->nb_op = env->nb_op_tmp;
	env->nb_op_tmp = 0;
	env->res_start = NULL;
	env->res_end = NULL;
	sol->next = NULL;
	if (env->sol_end != NULL)
		env->sol_end->next = sol;
	env->sol_end = sol;
}

static int		check_loop(t_room *room, t_env *env)
{
	t_result *tmp;

	tmp = env->res_start;
	while (tmp)
	{
		if (ft_strcmp(room->name, tmp->room->name) == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static int		check_way(t_room *start, t_env *env)
{
	int i;

	i = 0;
	if (start->start == 1)
		add_result(env, start);
	if (start->end == 1 && check_result(env) == 1)
		return (1);
	while (start->tab[i])
	{
		if (check_loop(start->tab[i], env))
		{
			add_result(env, start->tab[i]);
			if (check_way(start->tab[i], env) == 1)
				return (1);
			remove_result(env);
		}
		i++;
	}
	return (0);
}

int				find_way(t_env *env)
{
	t_room		*tmp;
	int			n;

	n = -1;
	tmp = env->r_start;
	while (tmp)
	{
		if (tmp->start == 1)
		{
			env->nb_op_tmp = 0;
			while (check_way(tmp, env) == 1)
				add_sol(env);
		}
		tmp = tmp->next;
	}
	return (0);
}
