/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 17:43:42 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/07 15:07:43 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_e *env)
{
	t_s		*tmpa;

	if (env->a_s != NULL)
	{
		tmpa = env->a_s;
		env->a_s = env->a_s->next;
		tmpa->next = env->b_s;
		env->b_s = tmpa;
		if (env->b_e == NULL)
			env->b_e = tmpa;
		env->nb_op++;
		env->len_b++;
		env->len_a--;
		add_move(env, "pb");
	}
}

void	push_to_a(t_e *env)
{
	t_s		*tmpb;

	if (env->b_s != NULL)
	{
		tmpb = env->b_s;
		env->b_s = env->b_s->next;
		tmpb->next = env->a_s;
		env->a_s = tmpb;
		if (env->a_e == NULL)
			env->a_e = tmpb;
		env->nb_op++;
		env->len_b--;
		env->len_a++;
		add_move(env, "pa");
	}
}
