/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:14:15 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/07 17:51:47 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		check_len(char *s, t_e *env)
{
	double	tmp;

	tmp = ft_atod(s);
	if (tmp > 2147483647 || tmp <= -2147483648)
	{
		env->err = 1;
		return (-1);
	}
	return (1);
}

static int		check_num(char *s, t_e *env)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[0] == '-' || s[0] == '+')
			s++;
		if (s[i] < '0' || s[i] > '9')
		{
			env->err = 1;
			return (-1);
		}
		i++;
	}
	return (1);
}

static int		ft_init_env(t_e *env)
{
	env->opt_v = 0;
	env->opt_c = 0;
	env->opt_m = 0;
	env->err = 0;
	env->a_s = NULL;
	env->b_s = NULL;
	env->a_e = NULL;
	env->b_e = NULL;
	env->m_s = NULL;
	env->m_e = NULL;
	env->nb_op = 0;
	env->len_a = 0;
	env->len_b = 0;
	return (0);
}

static int		get_opt(char **av, t_e *env)
{
	int i;
	int ret;

	i = -1;
	ret = 1;
	while (av[++i] != NULL && av[i][0] == '-')
		if (av[i][0] == '-' && (av[i][1] == 'v' || av[i][1] == 'c' || \
		av[i][1] == 'm'))
		{
			if (av[i][1] == 'v' && av[i][2] == '\0')
				env->opt_v = 1;
			if (av[i][1] == 'c' && av[i][2] == '\0')
				env->opt_c = 1;
			if (((av[i][1] == 'v' && av[i][2] == 'c') || (av[i][1] == 'c' \
			&& av[i][2] == 'v')) && av[i][3] == '\0')
			{
				env->opt_c = 1;
				env->opt_v = 1;
			}
			if (av[i][1] == 'm' && av[i][2] == '\0')
				env->opt_m = 1;
			ret++;
		}
	return (ret);
}

int				main(int ac, char **av)
{
	t_e		env;
	int		i;
	int		tmp;

	ft_init_env(&env);
	if (ac <= 1)
		return (0);
	i = get_opt(&av[1], &env);
	tmp = i;
	while (av[i] != NULL)
	{
		if (check_num(av[i], &env) != 1)
			break ;
		if (check_len(av[i], &env) != 1)
			break ;
		i++;
	}
	if (env.err == 1 || check_double(av, tmp) != 1)
		error();
	create_stack(&env, &av[tmp]);
	sort_all(&env);
	if (env.opt_v == 0)
		print_move(&env);
	free_all(&env);
	return (0);
}
