/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 10:51:00 by tglaudel          #+#    #+#             */
/*   Updated: 2015/12/17 17:33:26 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_checkone(char *src)
{
	int i;
	int count;
	int nb;

	nb = 0;
	i = 0;
	while (src[i] != '\0')
	{
		count = 0;
		while (count < 5)
		{
			if (count < 4 && src[i] != '.' && src[i] != '#')
				return (0);
			count++;
			i++;
			if (src[i] == '\0' && nb % 4 != 3)
				return (0);
			else if (src[i] == '\0')
				return (1);
		}
		nb++;
		if ((nb % 4) == 0)
			i++;
	}
	return (1);
}
