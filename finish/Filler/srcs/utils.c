/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:31:00 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/18 16:20:22 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	del_to_map(t_env *env)
{
	int x;
	int y;

	x = -1;
	while (++x < env->map->line)
	{
		y = -1;
		while (++y < env->map->col)
		{
			if (env->map->tab[x][y] == 'U')
				env->map->tab[x][y] = '.';
		}
	}
}

void	add_to_map(t_env *env, int x, int y)
{
	int i;
	int j;

	i = -1;
	while (++i < env->piece->line)
	{
		j = -1;
		while (++j < env->piece->col)
		{
			if (env->piece->tab[i][j] == '*' &&\
			env->map->tab[x + i][y + j] != env->player)
				env->map->tab[x + i][y + j] = 'U';
		}
	}
}

void	free_all(t_env *env)
{
	ft_free_tab(env->map->tab);
	ft_free_tab(env->piece->tab);
	free(env->map);
	free(env->piece);
	env->piece = NULL;
	env->map = NULL;
}
