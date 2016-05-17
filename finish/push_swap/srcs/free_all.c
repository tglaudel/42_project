/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 17:32:00 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/07 17:40:30 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack(t_s *stack)
{
	t_s *tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

static void	free_move(t_m *move)
{
	t_m *tmp;

	while (move)
	{
		tmp = move->next;
		ft_strdel(&move->move);
		free(move);
		move = tmp;
	}
}

void		free_all(t_e *env)
{
	free_stack(env->a_s);
	free_stack(env->b_s);
	free_move(env->m_s);
}
