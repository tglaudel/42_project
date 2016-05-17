/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creatlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:06:14 by tglaudel          #+#    #+#             */
/*   Updated: 2015/12/14 11:30:50 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_tetaddback(t_tetri **alst, t_tetri *new)
{
	t_tetri *tmp;

	tmp = *alst;
	if (tmp == NULL)
		*alst = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_tetri	*ft_tetnew(char *str)
{
	t_tetri *test;
	int		count[3];
	char	**tab;

	ft_bzero(count, sizeof(int) * 3);
	test = (t_tetri*)malloc(sizeof(test));
	tab = (char**)malloc(sizeof(tab) * 5);
	while (count[0] < 5)
	{
		tab[count[0]] = (char*)malloc(sizeof(tab) * 6);
		if (count[0] != 4)
		{
			while (count[1] < 5 && count[0] != 4)
				tab[count[0]][count[1]++] = str[count[2]++];
			count[1] = 0;
		}
		count[0]++;
	}
	tab = ft_move_tet(tab);
	test->next = NULL;
	test->content = tab;
	return (test);
}

t_tetri	*ft_creatlst(char *str, int nbtet)
{
	t_tetri	*start;

	start = NULL;
	while (nbtet > 0)
	{
		ft_tetaddback(&start, ft_tetnew(str));
		str = str + 21;
		nbtet--;
	}
	return (start);
}
