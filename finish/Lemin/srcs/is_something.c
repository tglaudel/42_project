/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_something.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 11:50:26 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/10 19:10:56 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		is_room_name(char *s, t_env *env)
{
	t_room *tmp;

	tmp = env->r_start;
	while (tmp)
	{
		if (ft_strcmp(s, tmp->name) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int				is_ants(t_args *arg, t_env *env)
{
	if (ft_isallnum(arg->data))
		if (ft_atoi(arg->data) == env->ants)
			return (1);
	return (0);
}

int				is_tube(t_args *arg, t_env *env)
{
	char	**s;

	s = ft_strsplit(arg->data, '-');
	if (tab_length(s) != 2)
	{
		free_tab(s);
		return (-1);
	}
	if (ft_strcmp(s[0], s[1]) == 0)
	{
		free_tab(s);
		return (-1);
	}
	if (is_room_name(s[0], env) != 1 || is_room_name(s[1], env) != 1)
	{
		free_tab(s);
		return (-1);
	}
	if (is_doublon_tube(s[0], s[1], env) != 1)
	{
		free_tab(s);
		return (-1);
	}
	free_tab(s);
	return (1);
}

int				is_command(t_args *arg)
{
	if (ft_strlen(arg->data) >= 2)
	{
		if (arg->data[0] == '#' && arg->data[1] == '#')
			return (1);
	}
	return (0);
}

int				is_room(t_args *arg, t_env *env, int mode)
{
	char	**s;

	s = ft_strsplit(arg->data, ' ');
	if (tab_length(s) != 3)
	{
		free_tab(s);
		return (-1);
	}
	if (ft_isallnum(s[1]) != 1 || ft_isallnum(s[2]) != 1)
	{
		free_tab(s);
		return (-1);
	}
	if (mode == 1 && is_room_name(s[0], env))
	{
		free_tab(s);
		return (-1);
	}
	free_tab(s);
	return (1);
}
