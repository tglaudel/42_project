/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 17:02:14 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/11 14:30:16 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	add_args(t_env *env, char *s)
{
	t_args *tmp;

	if (!(tmp = (t_args*)malloc(sizeof(t_args))))
		error("Error malloc");
	if (env->a_start == NULL)
		env->a_start = tmp;
	tmp->data = s;
	tmp->next = NULL;
	if (env->a_end != NULL)
		env->a_end->next = tmp;
	env->a_end = tmp;
}

static void	create_largs(t_env *env)
{
	char	*line;

	line = NULL;
	while (1)
	{
		get_next_line(0, &line);
		if (ft_strcmp(line, "\0") == 0)
			break ;
		else
			add_args(env, ft_strdup(line));
		ft_strdel(&line);
		line = NULL;
	}
	ft_strdel(&line);
	line = NULL;
}

void		get_args(t_env *env)
{
	create_largs(env);
	get_ants(env);
	get_rooms(env);
	get_tubes(env);
}
