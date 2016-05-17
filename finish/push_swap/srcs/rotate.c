/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 12:57:37 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/07 15:09:30 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_e *env)
{
	t_s		*tmp;

	if (env->a_s != NULL && env->a_s->next != NULL)
	{
		tmp = env->a_s->next;
		env->a_s->next = NULL;
		env->a_e->next = env->a_s;
		env->a_e = env->a_s;
		env->a_s = tmp;
		env->nb_op++;
		add_move(env, "ra");
	}
}

void	rotate_b(t_e *env)
{
	t_s		*tmp;

	if (env->b_s != NULL && env->b_s->next != NULL)
	{
		tmp = env->b_s->next;
		env->b_s->next = NULL;
		env->b_e->next = env->b_s;
		env->b_e = env->b_s;
		env->b_s = tmp;
		env->nb_op++;
		add_move(env, "rb");
	}
}

void	rotate_ab(t_e *env)
{
	t_s		*tmp;

	if (env->a_s != NULL && env->a_s->next != NULL && env->b_s != NULL && \
		env->b_s->next != NULL)
	{
		tmp = env->a_s->next;
		env->a_s->next = NULL;
		env->a_e->next = env->a_s;
		env->a_e = env->a_s;
		env->a_s = tmp;
		tmp = env->b_s->next;
		env->b_s->next = NULL;
		env->b_e->next = env->b_s;
		env->b_e = env->b_s;
		env->b_s = tmp;
		env->nb_op++;
		add_move(env, "rr");
	}
}
