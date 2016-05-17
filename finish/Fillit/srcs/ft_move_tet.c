/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_tet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 11:46:51 by tglaudel          #+#    #+#             */
/*   Updated: 2015/12/14 11:31:56 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**ft_move_tet_col(char **tab)
{
	int i;

	i = 0;
	if (tab[0][0] == '.' && tab[1][0] == '.' && tab[2][0] == '.' \
			&& tab[3][0] == '.')
	{
		while (i < 4)
		{
			tab[i][0] = tab[i][1];
			tab[i][1] = tab[i][2];
			tab[i][2] = tab[i][3];
			tab[i][3] = '.';
			i++;
		}
		return (ft_move_tet_col(tab));
	}
	return (tab);
}

static char	**ft_move_tet_line(char **tab)
{
	char	*tmp;
	int		i;

	i = 0;
	if (tab[0][0] == '.' && tab[0][1] == '.' && tab[0][2] == '.' \
			&& tab[0][3] == '.')
	{
		tmp = tab[0];
		tab[0] = tab[1];
		tab[1] = tab[2];
		tab[2] = tab[3];
		tab[3] = tmp;
		return (ft_move_tet_line(tab));
	}
	return (tab);
}

static int	ft_check_sharp(char **tab)
{
	int i;
	int j;
	int count;

	count = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tab[i][j] == '#')
				count++;
			j++;
		}
		i++;
	}
	if (count == 4)
		return (1);
	return (0);
}

char		**ft_move_tet(char **tab)
{
	if (ft_check_sharp(tab) == 0)
		return (tab);
	tab = ft_move_tet_line(tab);
	tab = ft_move_tet_col(tab);
	return (tab);
}
