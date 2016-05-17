/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_play.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:04:33 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/18 16:17:09 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	n_contact(t_env *env, int i, int j)
{
	int n;
	int x;
	int y;

	n = 0;
	x = -4;
	while (i + x < 0)
		x++;
	while (i + x < env->map->line && x < 4)
	{
		y = -4;
		while (j + y < 0)
			y++;
		while (j + y < env->map->col && y < 4)
		{
			if (env->map->tab[i + x][j + y] == env->adv)
				n++;
			y++;
		}
		x++;
	}
	return (n);
}

static int	count_contact(t_env *env, int x, int y)
{
	int n;
	int i;
	int j;

	n = 0;
	add_to_map(env, x, y);
	i = -1;
	while (++i < env->map->line)
	{
		j = -1;
		while (++j < env->map->col)
		{
			if (env->map->tab[i][j] == 'U')
				n += n_contact(env, i, j);
		}
	}
	del_to_map(env);
	return (n);
}

int			contact_play(t_env *env, int x, int y)
{
	t_res	res;
	int		n;

	x = -1;
	res.x = 0;
	res.y = 0;
	res.n = 0;
	while (++x < env->map->line)
	{
		y = -1;
		while (++y < env->map->col)
			if (try_add(env, x, y))
				if ((n = count_contact(env, x, y)) > res.n)
				{
					res.x = x;
					res.y = y;
					res.n = n;
				}
	}
	if (res.n != 0)
	{
		ft_printf("%d %d\n", res.x, res.y);
		return (1);
	}
	return (0);
}

int			simple_play(t_env *env)
{
	int		x;
	int		y;

	x = -1;
	while (++x < env->map->line)
	{
		y = -1;
		while (++y < env->map->col)
			if (try_add(env, x, y))
			{
				ft_printf("%d %d\n", x, y);
				return (1);
			}
	}
	return (0);
}
