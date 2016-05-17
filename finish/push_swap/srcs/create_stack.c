/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 11:56:30 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/07 19:36:36 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		check_int(t_e *env)
{
	t_s		*tmp;
	t_s		*tmp2;

	tmp = env->a_s;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2 != NULL)
		{
			if (tmp->nbr == tmp2->nbr)
				error();
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

void			create_stack(t_e *env, char **s)
{
	t_s *a;
	int i;

	i = 0;
	if (!(a = (t_s*)malloc(sizeof(t_s))))
		error();
	while (s[i] != NULL)
	{
		if (s[i + 1] == NULL)
			a->next = NULL;
		else if (!(a->next = (t_s*)malloc(sizeof(t_s))))
			error();
		if (env->a_s == NULL)
			env->a_s = a;
		a->nbr = ft_atoi(s[i]);
		env->a_e = a;
		a = a->next;
		env->len_a++;
		i++;
	}
	check_int(env);
}
