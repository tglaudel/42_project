/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 11:26:27 by tglaudel          #+#    #+#             */
/*   Updated: 2015/12/21 17:54:43 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_tet(char **c)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 5)
		{
			ft_putchar(c[i][j]);
			j++;
		}
		i++;
	}
}

void	ft_print_lst(t_tetri *tmp)
{
	t_tetri *tet;

	tet = tmp;
	while (tet != NULL && tet->content != NULL)
	{
		ft_print_tet(tet->content);
		tet = tet->next;
		ft_putchar('\n');
	}
}

void	ft_print_tab(char **tab, int lt)
{
	int i;
	int j;

	i = 0;
	while (i < lt - 1)
	{
		j = 0;
		while (j < lt - 1)
		{
			ft_putchar(tab[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
