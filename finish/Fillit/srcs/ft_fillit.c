/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 09:20:07 by tglaudel          #+#    #+#             */
/*   Updated: 2015/12/21 18:03:30 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_fillit(char *name)
{
	char	*src;
	t_tetri	*start;

	src = ft_openread(name);
	if (src == NULL)
		return (0);
	if (ft_checkone(src) == 0)
	{
		ft_putendl("error");
		return (0);
	}
	if (ft_count_tetri(src) > 26)
	{
		ft_putendl("error");
		return (0);
	}
	start = ft_creatlst(src, ft_count_tetri(src));
	if (ft_lstcheck(start) == 0)
	{
		ft_putendl("error");
		return (0);
	}
	ft_res(start, ft_count_tetri(src));
	return (1);
}
