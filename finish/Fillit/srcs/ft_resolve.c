/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 10:41:28 by tglaudel          #+#    #+#             */
/*   Updated: 2015/12/16 15:41:18 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			ft_postet(int pos, int lt, char **tab, t_tetri *tetri)
{
	int		i[3];
	char	**tet;

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	tet = tetri->content;
	while (i[0] < 4)
	{
		i[1] = 0;
		while (i[1] < 4)
		{
			if ((pos / lt) + i[0] < lt && (pos % lt) + i[1] < lt)
			{
				if (tet[i[0]][i[1]] == '#' \
						&& tab[(pos / lt) + i[0]][(pos % lt) + i[1]] == '.')
					i[2]++;
				if (i[2] == 4)
					return (1);
			}
			i[1]++;
		}
		i[0]++;
	}
	return (0);
}

static void			ft_addtet(char **tab, int *p, t_tetri *tetri, char c)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetri->content[i][j] == '#')
				tab[p[0] + i][p[1] + j] = c;
			j++;
		}
		i++;
	}
}

static void			ft_supptet(char **tab, char c, int lt)
{
	int i;
	int j;

	i = 0;
	while (i < lt)
	{
		j = 0;
		while (j < lt)
		{
			if (tab[i][j] == c)
				tab[i][j] = '.';
			j++;
		}
		i++;
	}
}

static char			**ft_resolve(t_tetri *tetri, int lt, int index, int reinit)
{
	int			pos;
	int			p[2];
	static char **tab = NULL;

	if (tetri == NULL)
		return (tab);
	pos = 0;
	if (reinit)
		tab = ft_new_tab(tab);
	while (pos < (lt * lt))
	{
		if (ft_postet(pos, lt, tab, tetri) == 1)
		{
			p[0] = pos / lt;
			p[1] = pos % lt;
			ft_addtet(tab, p, tetri, 'A' + index);
			if (ft_resolve(tetri->next, lt, index + 1, 0))
				return (tab);
			ft_supptet(tab, 'A' + index, lt);
		}
		pos++;
	}
	return (NULL);
}

void				ft_res(t_tetri *start, int nbtet)
{
	char	**tab;
	int		lt;
	t_tetri **s;

	s = (t_tetri **)malloc(sizeof(t_tetri));
	*s = start;
	tab = NULL;
	lt = ft_sqrtlow(nbtet * 4);
	while (tab == NULL)
	{
		tab = ft_resolve(*s, lt, 0, 1);
		lt++;
	}
	ft_print_tab(tab, lt);
	ft_free_tab(tab);
}
