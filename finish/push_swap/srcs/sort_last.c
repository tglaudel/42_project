/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_last.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 18:22:04 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/07 18:31:42 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			check_nbr(int nbr, t_e *env)
{
	int	i;
	t_s	*tmp;

	i = 0;
	tmp = env->a_s;
	while (tmp)
	{
		if (tmp->nbr > nbr)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

int					sort_last(t_e *env)
{
	rev_rotate_a(env);
	rev_rotate_a(env);
	swap_a(env);
	rotate_a(env);
	rotate_a(env);
	return (1);
}

int					check_last(t_e *env)
{
	t_s	*tmp;
	int	i;

	i = 1;
	tmp = env->a_s;
	if (env->len_a == 0)
		return (1);
	while (tmp && tmp->next)
	{
		if (tmp->nbr > tmp->next->nbr)
		{
			if (i == env->len_a - 1 && check_nbr(tmp->next->nbr, env) == 1)
				return (sort_last(env));
			else
				return (0);
		}
		i++;
		tmp = tmp->next;
	}
	return (1);
}
