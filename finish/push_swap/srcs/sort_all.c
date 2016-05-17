/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 12:41:43 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/07 18:31:54 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			sort_a(t_e *env)
{
	t_s		*tmp;

	tmp = env->a_s;
	if (env->len_a == 0)
		return (1);
	while (tmp && tmp->next)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static int			sort_b(t_e *env)
{
	t_s		*tmp;

	tmp = env->b_s;
	if (env->len_b == 0)
		return (1);
	while (tmp != NULL && tmp->next != NULL)
	{
		if (tmp->nbr < tmp->next->nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static void			find_min(t_e *env)
{
	t_s	*tmp;
	int	i;
	int	min;

	i = 0;
	min = 2147483646;
	tmp = env->a_s;
	while (tmp)
	{
		if (tmp->nbr < min)
		{
			min = tmp->nbr;
			env->pos = i;
		}
		i++;
		tmp = tmp->next;
	}
}

static int			sort_stack(t_e *env)
{
	t_s		*tmp;

	if (sort_a(env) && sort_b(env))
	{
		if (env->len_b != 0)
		{
			if (env->a_s->nbr > env->b_s->nbr)
			{
				tmp = env->b_s;
				while (tmp)
				{
					push_to_a(env);
					tmp = env->b_s;
				}
			}
		}
	}
	return (1);
}

int					sort_all(t_e *env)
{
	static int i = 0;

	if (i == 0 && env->len_a > 4 && check_last(env) == 1)
		return (check_last(env));
	i = 1;
	if (sort_a(env) && sort_b(env))
		return (sort_stack(env));
	else if (env->len_a >= 2 && env->a_s->nbr > env->a_s->next->nbr)
		swap_a(env);
	else
	{
		find_min(env);
		if (env->pos <= (env->len_a / 2))
			while (env->pos-- > 0 && sort_a(env) == 0)
				rotate_a(env);
		else
			while (env->pos++ < env->len_a)
				rev_rotate_a(env);
		if (sort_a(env) != 1)
			push_to_b(env);
	}
	sort_all(env);
	return (0);
}
