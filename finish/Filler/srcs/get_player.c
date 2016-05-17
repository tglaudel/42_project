/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 11:13:58 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/18 16:17:08 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		get_player(t_env *env)
{
	char *line;
	char **tab;

	if (get_next_line(0, &line) != 1)
		error("ERROR");
	tab = ft_strsplit(line, ' ');
	ft_strdel(&line);
	line = NULL;
	if (ft_strcmp(tab[2], "p1") == 0)
	{
		env->player = 'O';
		env->adv = 'X';
	}
	else
	{
		env->adv = 'O';
		env->player = 'X';
	}
	ft_free_tab(tab);
}
