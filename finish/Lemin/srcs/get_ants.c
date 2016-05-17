/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 17:32:31 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/11 15:59:22 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	check_is_ants(t_env *env)
{
	t_args	*tmp;
	int		ants;

	tmp = env->a_start;
	ants = 0;
	if (tmp)
	{
		while ((tmp && tmp->data[0] == '#' && tmp->data[1] != '#') || \
		is_command(tmp) == 1)
		{
			if (is_com(tmp))
				add_com(env, ft_strdup(tmp->data));
			tmp = tmp->next;
		}
		if (tmp == NULL || ft_isallnum(tmp->data) == 0)
			return (-1);
		ants = ft_atoi(tmp->data);
		if (ants <= 0)
			return (-1);
		else
			return (ants);
	}
	return (-1);
}

void		get_ants(t_env *env)
{
	int		ants;

	ants = check_is_ants(env);
	if (ants == -1)
	{
		free_all_args(env);
		error("ERROR : no ants");
	}
	env->ants = ants;
}
