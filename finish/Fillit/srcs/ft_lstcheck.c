/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 11:19:58 by tglaudel          #+#    #+#             */
/*   Updated: 2015/12/12 11:23:25 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_lstcheck(t_tetri *tmp)
{
	t_tetri *tet;

	tet = tmp;
	while (tet != NULL && tet->content != NULL)
	{
		if (ft_check(tet->content) == 0)
			return (0);
		else
			tet = tet->next;
	}
	return (1);
}
