/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_result.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 14:20:24 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/11 14:29:37 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		add_result(t_env *env, t_room *room)
{
	t_result *tmp;

	if (!(tmp = (t_result*)malloc(sizeof(t_result))))
		error("Error malloc");
	if (env->res_start == NULL)
		env->res_start = tmp;
	tmp->room = room;
	env->nb_op_tmp++;
	tmp->next = NULL;
	if (env->res_end != NULL)
		env->res_end->next = tmp;
	env->res_end = tmp;
}

void		remove_result(t_env *env)
{
	t_result	*tmp;

	tmp = env->res_start;
	while (tmp->next != env->res_end)
		tmp = tmp->next;
	free(env->res_end);
	env->res_end = tmp;
	env->nb_op_tmp--;
	tmp->next = NULL;
}
