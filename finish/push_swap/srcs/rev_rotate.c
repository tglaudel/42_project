/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 16:57:48 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/07 15:08:55 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_a(t_e *env)
{
	t_s		*tmp;

	if (env->a_s != NULL && env->a_s->next != NULL)
	{
		tmp = env->a_s;
		while (tmp->next != env->a_e)
			tmp = tmp->next;
		tmp->next = NULL;
		env->a_e->next = env->a_s;
		env->a_s = env->a_e;
		env->a_e = tmp;
		add_move(env, "rra");
	}
}

void	rev_rotate_b(t_e *env)
{
	t_s		*tmp;

	if (env->b_s != NULL && env->b_s->next != NULL)
	{
		tmp = env->b_s;
		while (tmp->next != env->b_e)
			tmp = tmp->next;
		tmp->next = NULL;
		env->b_e->next = env->b_s;
		env->b_s = env->b_e;
		env->b_e = tmp;
		add_move(env, "rrb");
	}
}

void	rev_rotate_ab(t_e *env)
{
	t_s		*tmp;

	if (env->b_s != NULL && env->b_s->next != NULL && env->a_s != NULL && \
		env->a_s->next != NULL)
	{
		tmp = env->b_s;
		while (tmp->next != env->b_e)
			tmp = tmp->next;
		tmp->next = NULL;
		env->b_e->next = env->b_s;
		env->b_s = env->b_e;
		env->b_e = tmp;
		tmp = env->a_s;
		while (tmp->next != env->a_e)
			tmp = tmp->next;
		tmp->next = NULL;
		env->a_e->next = env->a_s;
		env->a_s = env->a_e;
		env->a_e = tmp;
		add_move(env, "rrr");
	}
}
