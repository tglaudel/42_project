/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 13:10:12 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/07 15:06:14 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_move(t_e *env, char *s)
{
	t_m		*m;

	if (!(m = (t_m*)malloc(sizeof(t_m))))
		ft_putstr("error malloc");
	if (env->m_s == NULL)
		env->m_s = m;
	m->move = ft_strdup(s);
	m->next = NULL;
	if (env->m_e != NULL)
		env->m_e->next = m;
	env->m_e = m;
	if (env->opt_v == 1)
	{
		print_stack(env, 'a');
		print_stack(env, 'b');
		print_move(env);
	}
}
