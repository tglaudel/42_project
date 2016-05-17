/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 10:46:49 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/18 16:19:41 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			print_tab(char **s)
{
	int i;

	i = -1;
	while (s[++i])
	{
		ft_putendl(s[i]);
	}
}

void			ft_free_tab(char **s)
{
	int i;

	i = -1;
	while (s[++i])
	{
		ft_strdel(&s[i]);
		s[i] = NULL;
	}
	free(s);
	s = NULL;
}

void			error(char *s)
{
	ft_putendl(s);
	exit(0);
}

static void		init_env(t_env *env)
{
	env->map = NULL;
	env->piece = NULL;
	env->player = 0;
	env->adv = 0;
}

int				main(void)
{
	t_env	env;
	int		x;

	x = -1;
	init_env(&env);
	get_player(&env);
	while (1)
	{
		get_map(&env);
		get_piece(&env);
		if (contact_play(&env, 0, 0) != 1)
		{
			if (play(&env, 0, 0) != 1)
			{
				if (simple_play(&env) != 1)
				{
					ft_putstr("0 0\n");
					break ;
				}
			}
		}
		free_all(&env);
	}
	return (0);
}
