/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 17:18:21 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/11 13:33:00 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		print_com(t_env *env)
{
	t_com	*tmp;

	tmp = env->c_start;
	ft_putstr("\nCommentaire :\n");
	while (tmp != NULL)
	{
		ft_putendl(tmp->data);
		tmp = tmp->next;
	}
}

void		print_tubes(t_env *env)
{
	t_tube	*tmp;

	tmp = env->t_start;
	while (tmp != NULL)
	{
		ft_printf("Name_a : %s\nName_b : %s\n\n", tmp->name_a, tmp->name_b);
		tmp = tmp->next;
	}
}

void		print_rooms(t_env *env)
{
	t_room	*tmp;
	int		i;

	tmp = env->r_start;
	while (tmp != NULL)
	{
		i = -1;
		ft_printf("----- Room %s ------\n", tmp->name);
		ft_printf("Name :%s\nX    :%d\nY    :%d\nStart:%d\nEnd  :%d\n\n",\
		tmp->name, tmp->x, tmp->y, tmp->start, tmp->end);
		ft_putendl("connection :");
		while (tmp->tab[++i])
			ft_printf("tab : %d %s\n", i, tmp->tab[i]->name);
		ft_putchar('\n');
		tmp = tmp->next;
	}
}

int			print_sol(t_env *env)
{
	t_sol	*tmp;

	tmp = env->sol_start;
	while (tmp != NULL)
	{
		ft_putnbr(tmp->nb_op);
		ft_putstr(" : ");
		print_result(tmp);
		tmp = tmp->next;
	}
	return (0);
}

void		print_args(t_env *env)
{
	t_args	*tmp;

	tmp = env->a_start;
	while (tmp != NULL)
	{
		ft_putendl(tmp->data);
		tmp = tmp->next;
	}
}
