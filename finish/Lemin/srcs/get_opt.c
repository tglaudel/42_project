/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 11:13:48 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/12 14:16:45 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		add_opt(char c)
{
	if (c == 'R')
		return (O_ROOM);
	else if (c == 'c')
		return (O_COLOR);
	else if (c == 'h')
		return (O_HELP);
	else if (c == 'C')
		return (O_COM);
	else if (c == 's')
		return (O_SOL);
	return (0);
}

static int		new_option(int opt, int new)
{
	if (opt & new)
		return (0);
	return (new);
}

int				get_opt(char *av, int opt)
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (av[i])
	{
		if (new_option(opt, add_opt(av[i])))
		{
			if (add_opt(av[i]) != -1)
				opt += add_opt(av[i]);
		}
		else if (!(add_opt(av[i])))
		{
			print_opt_h();
			error("ERROR : illegal option.");
		}
		i++;
	}
	return (opt);
}
