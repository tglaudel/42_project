/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 10:53:03 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/11 10:57:55 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_color	g_color[13] = {
	{0, C_RED},
	{1, C_RED2},
	{2, C_GREEN},
	{3, C_GREEN2},
	{4, C_YELLOW},
	{5, C_YELLOW2},
	{6, C_BLUE},
	{7, C_BLUE2},
	{8, C_MAGENTA},
	{9, C_CYAN},
	{10, C_GRAY},
	{11, C_BLACK},
	{12, C_NONE}};

void	ft_color(int n)
{
	int i;
	int index;

	i = 0;
	index = n % 11;
	if (n != 0 && n != 46)
	{
		while (g_color[i].index != index)
			i++;
		ft_putstr(g_color[i].color);
	}
	else
		ft_putstr(C_NONE);
}
