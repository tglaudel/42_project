/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 12:49:52 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/07 15:12:26 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_e *env)
{
	int tmp;

	if (env->a_s != NULL && env->a_s->next != NULL)
	{
		tmp = env->a_s->nbr;
		env->a_s->nbr = env->a_s->next->nbr;
		env->a_s->next->nbr = tmp;
		env->nb_op++;
		add_move(env, "sa");
	}
}

void	swap_b(t_e *env)
{
	int tmp;

	if (env->b_s != NULL && env->b_s->next != NULL)
	{
		tmp = env->b_s->nbr;
		env->b_s->nbr = env->b_s->next->nbr;
		env->b_s->next->nbr = tmp;
		env->nb_op++;
		add_move(env, "sb");
	}
}

void	swap_ab(t_e *env)
{
	int tmp;

	if (env->b_s != NULL && env->b_s->next != NULL && env->a_s != NULL && \
		env->a_s->next != NULL)
	{
		tmp = env->b_s->nbr;
		env->b_s->nbr = env->b_s->next->nbr;
		env->b_s->next->nbr = tmp;
		tmp = env->a_s->nbr;
		env->a_s->nbr = env->a_s->next->nbr;
		env->a_s->next->nbr = tmp;
		env->nb_op++;
		add_move(env, "ss");
	}
}
