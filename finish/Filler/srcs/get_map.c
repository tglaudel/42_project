/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 12:00:38 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/18 16:24:59 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static char	**get_board(t_map *map)
{
	char	**tab;
	char	**tmp;
	int		x;
	char	*line;

	x = -1;
	tab = (char**)malloc(sizeof(char*) * map->line + 1);
	get_next_line(0, &line);
	ft_strdel(&line);
	while (++x < map->line)
	{
		get_next_line(0, &line);
		tmp = ft_strsplit(line, ' ');
		tab[x] = ft_strdup(tmp[1]);
		ft_strdel(&line);
		ft_free_tab(tmp);
		line = NULL;
	}
	tab[x] = NULL;
	return (tab);
}

void		get_map(t_env *env)
{
	char	**tab;
	t_map	*map;
	char	*line;

	tab = NULL;
	while (get_next_line(0, &line) == 1)
	{
		if (ft_strncmp(line, "Plateau", 7) == 0)
		{
			tab = ft_strsplit(line, ' ');
			if (!(map = (t_map*)malloc(sizeof(t_map))))
				error("Error : creation de map");
			map->line = ft_atoi(tab[1]);
			map->col = ft_atoi(tab[2]);
			map->tab = get_board(map);
			env->map = map;
			ft_strdel(&line);
			ft_free_tab(tab);
			break ;
		}
		ft_strdel(&line);
		line = NULL;
	}
	if (tab == NULL)
		error("pas de tab");
}
