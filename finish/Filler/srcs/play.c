/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 16:17:42 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/18 15:34:15 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int			no_touch(t_env *env, int i, int j)
{
	int x;
	int y;

	x = -2;
	while (i + x < 0)
		x++;
	while (i + x < env->map->line && x < 2)
	{
		y = -2;
		while (j + y < 0)
			y++;
		while (j + y < env->map->col && y < 2)
		{
			if (env->map->tab[i + x][j + y] == env->player)
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

static int			diff(int x, int y, int i, int j)
{
	int n;
	int o;

	n = x - i;
	o = y - j;
	return (ABS(n) + ABS(o));
}

static int			position_adv(t_env *env, int x, int y)
{
	int	i;
	int j;
	int n;

	n = 0;
	i = -1;
	while (++i < env->map->line)
	{
		j = -1;
		while (++j < env->map->col)
		{
			if (env->map->tab[i][j] != env->player && \
				env->map->tab[i][j] != '.')
			{
				if (no_touch(env, i, j) && diff(x, y, i, j) >= n)
					n = diff(x, y, i, j);
			}
		}
	}
	return (n);
}

int					try_add(t_env *env, int x, int y)
{
	int		i;
	int		j;
	int		n;

	n = 0;
	i = -1;
	while (++i < env->piece->line && i + x < env->map->line)
	{
		j = -1;
		while (++j < env->piece->col && j + y < env->map->col)
		{
			if (env->piece->tab[i][j] != '.' && env->map->tab[x + i][y + j] \
			== ft_toupper(env->player))
				n++;
			else if (env->piece->tab[i][j] != '.' && \
			env->map->tab[x + i][y + j] != '.')
				return (0);
		}
	}
	if (n == 1 && j == env->piece->col && i == env->piece->line)
		return (1);
	return (0);
}

int					play(t_env *env, int x, int y)
{
	t_res	res;
	int		n;

	x = -1;
	res.x = 0;
	res.y = 0;
	res.n = 10000;
	while (++x < env->map->line)
	{
		y = -1;
		while (++y < env->map->col)
			if (try_add(env, x, y))
				if ((n = position_adv(env, x, y)) < res.n)
				{
					res.x = x;
					res.y = y;
					res.n = n;
				}
	}
	if (res.n != 10000)
	{
		ft_printf("%d %d\n", res.x, res.y);
		return (1);
	}
	return (0);
}
