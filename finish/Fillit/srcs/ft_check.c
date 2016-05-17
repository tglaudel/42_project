/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:20:32 by tglaudel          #+#    #+#             */
/*   Updated: 2015/12/16 18:11:48 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_count(char **tab)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
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

static int		ft_checkcol(char **tab, int i, int j)
{
	int count;

	count = 0;
	if (j > 0 && j < 3)
	{
		if (tab[i][j + 1] == '#')
			count++;
		if (tab[i][j - 1] == '#')
			count++;
		return (count);
	}
	else if (j == 0)
	{
		if (tab[i][j + 1] == '#')
			return (1);
	}
	else if (j == 3)
	{
		if (tab[i][j - 1] == '#')
			return (1);
	}
	return (0);
}

static int		ft_checkline(char **tab, int i, int j)
{
	int count;

	count = 0;
	if (i > 0 && i < 3)
	{
		if (tab[i + 1][j] == '#')
			count++;
		if (tab[i - 1][j] == '#')
			count++;
		return (count + ft_checkcol(tab, i, j));
	}
	else if (i == 0)
	{
		if (tab[i + 1][j] == '#')
			return (1 + ft_checkcol(tab, i, j));
	}
	else if (i == 3)
	{
		if (tab[i - 1][j] == '#')
			return (1 + ft_checkcol(tab, i, j));
	}
	return (ft_checkcol(tab, i, j));
}

static int		ft_form(char **tab)
{
	int i;
	int j;
	int count;

	count = 0;
	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tab[i][j] == '#')
			{
				count += ft_checkline(tab, i, j);
				if (count >= 6)
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int				ft_check(char **tab)
{
	if (ft_count(tab) == 0)
		return (0);
	if (ft_form(tab) == 0)
		return (0);
	return (1);
}
