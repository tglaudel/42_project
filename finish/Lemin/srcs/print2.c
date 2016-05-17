/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 18:43:19 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/11 13:23:25 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		print_result_res(t_result *res)
{
	t_result	*tmp;

	tmp = res;
	while (tmp != NULL)
	{
		ft_putstr(tmp->room->name);
		ft_putchar(' ');
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

void		print_result(t_sol *sol)
{
	t_result	*tmp;

	tmp = sol->res_s;
	while (tmp != NULL)
	{
		ft_putstr(tmp->room->name);
		ft_putchar(' ');
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

void		print_map(t_env *env)
{
	t_args	*tmp;

	tmp = env->a_start;
	while (tmp != NULL && env->n_map > 0)
	{
		ft_putendl(tmp->data);
		tmp = tmp->next;
		env->n_map--;
	}
	ft_putchar('\n');
}

int			print_opt_h(void)
{
	ft_putstr("*******HELPER LEM-IN*******\n");
	ft_putstr("Option : -h : Help\n");
	ft_putstr("         -c : Color\n");
	ft_putstr("         -R : Show Room\n");
	ft_putstr("         -C : Show Com\n");
	ft_putstr("         -s : Show Solutions\n");
	ft_putstr("***************************\n");
	return (0);
}
