/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 11:38:08 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/03 17:41:16 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_double(char **s, int i)
{
	int		tmp;
	int		tmp2;

	tmp = i;
	while (s[tmp])
	{
		tmp2 = tmp + 1;
		while (s[tmp2] != NULL)
		{
			if (ft_strcmp(s[tmp], s[tmp2]) == 0)
				return (-1);
			tmp2++;
		}
		tmp++;
	}
	return (1);
}
