/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 12:11:45 by tglaudel          #+#    #+#             */
/*   Updated: 2015/12/16 15:41:09 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_new_tab(char **tab)
{
	int i;
	int j;

	i = 0;
	tab = (char**)malloc(sizeof(tab) * 20);
	while (i < 20)
	{
		j = 0;
		tab[i] = (char*)malloc(sizeof(tab) * 20);
		while (j < 20)
		{
			tab[i][j] = '.';
			j++;
		}
		i++;
	}
	return (tab);
}

void	ft_free_tab(char **tab)
{
	int i;

	i = 0;
	while (i < 20)
	{
		free(tab[i]);
		i++;
	}
}
