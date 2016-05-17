/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 18:57:55 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/11 16:00:47 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char		is_start(t_args *arg)
{
	if (ft_strcmp(arg->data, "##start\0") == 0)
		return (1);
	return (0);
}

char		is_end(t_args *arg)
{
	if (ft_strcmp(arg->data, "##end\0") == 0)
		return (1);
	return (0);
}

int			is_com(t_args *arg)
{
	if (arg->data[0] == '#' && arg->data[1] != '#')
		return (1);
	return (0);
}

static void	add_room(t_env *env, char **s, char start, char end)
{
	t_room *tmp;

	if (!(tmp = (t_room*)malloc(sizeof(t_room))))
		error("Error malloc");
	if (env->r_start == NULL)
		env->r_start = tmp;
	tmp->name = ft_strdup(s[0]);
	tmp->x = ft_atoi(s[1]);
	tmp->y = ft_atoi(s[2]);
	tmp->connect = 0;
	tmp->ants = 0;
	tmp->next = NULL;
	tmp->start = start;
	tmp->end = end;
	if (env->r_end != NULL)
		env->r_end->next = tmp;
	env->r_end = tmp;
	free_tab(s);
}

void		get_rooms(t_env *env)
{
	t_args		*tmp;
	char		start;
	char		end;
	t_args		*prev;

	tmp = env->a_start;
	while (tmp)
	{
		if (start != 1 && tmp != env->a_start)
			start = is_start(prev);
		if (end != 1 && tmp != env->a_start)
			end = is_end(prev);
		if (is_room(tmp, env, 1) != -1)
		{
			add_room(env, ft_strsplit(tmp->data, ' '), start, end);
			start = 0;
			end = 0;
		}
		else if (is_command(tmp) != 1 && is_com(tmp) != 1 && \
		is_ants(tmp, env) != 1)
			break ;
		prev = tmp;
		tmp = tmp->next;
	}
}
