/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 10:59:18 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/18 16:05:39 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static char	**get_form(t_piece *piece)
{
	char	**tab;
	int		x;
	char	*line;

	x = -1;
	tab = (char**)malloc(sizeof(char*) * piece->line + 1);
	while (++x < piece->line)
	{
		get_next_line(0, &line);
		tab[x] = ft_strdup(line);
		ft_strdel(&line);
		line = NULL;
	}
	tab[x] = NULL;
	return (tab);
}

void		get_piece(t_env *env)
{
	char	**tab;
	char	*line;
	t_piece	*piece;

	while (get_next_line(0, &line) == 1)
	{
		if (ft_strncmp(line, "Piece", 5) == 0)
		{
			tab = ft_strsplit(line, ' ');
			if (!(piece = (t_piece*)malloc(sizeof(t_piece))))
				error("Error : creation piece");
			piece->line = ft_atoi(tab[1]);
			piece->col = ft_atoi(tab[2]);
			piece->tab = get_form(piece);
			env->piece = piece;
			ft_strdel(&line);
			line = NULL;
			ft_free_tab(tab);
			break ;
		}
		ft_strdel(&line);
		line = NULL;
	}
}
