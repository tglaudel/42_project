/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 12:10:08 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/07 19:42:16 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_e *env, char stack)
{
	t_s		*tmp;

	tmp = NULL;
	ft_putchar(stack);
	ft_putstr(" : ");
	if (stack == 'a')
		tmp = env->a_s;
	else if (stack == 'b')
		tmp = env->b_s;
	while (tmp)
	{
		ft_putnbr(tmp->nbr);
		tmp = tmp->next;
		ft_putchar(' ');
	}
	ft_putchar('\n');
}

void	print_move(t_e *env)
{
	t_m		*tmp;
	int		i;

	i = 0;
	tmp = env->m_s;
	if (tmp == NULL)
		return ;
	if (env->opt_m == 1)
		ft_printf("%d\n", env->nb_op);
	while (tmp)
	{
		if (tmp->next == NULL && env->opt_c)
		{
			ft_putstr("\033[31m");
			ft_putstr(tmp->move);
			ft_putstr("\033[0m");
		}
		else
			ft_putstr(tmp->move);
		if (tmp->next != NULL)
			ft_putchar(' ');
		tmp = tmp->next;
		i++;
	}
	ft_putchar('\n');
}
