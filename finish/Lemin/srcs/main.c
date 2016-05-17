/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 16:31:22 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/11 16:11:55 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		init_env(t_env *env)
{
	env->r_start = NULL;
	env->r_end = NULL;
	env->t_start = NULL;
	env->t_end = NULL;
	env->a_start = NULL;
	env->a_end = NULL;
	env->res_start = NULL;
	env->res_end = NULL;
	env->c_start = NULL;
	env->c_end = NULL;
	env->sol_start = NULL;
	env->sol_end = NULL;
	env->ant_start = NULL;
	env->ant_end = NULL;
	env->opt = 0;
	env->fd = 0;
	env->end_ants = 0;
	env->n_map = 0;
}

int				main(int ac, char **av)
{
	t_env	env;
	int		i;

	i = 0;
	(void)ac;
	init_env(&env);
	while (av[++i] && av[i][0] == '-' && av[i][1] != '\0')
		env.opt = get_opt(av[i], env.opt);
	if (env.opt & O_HELP)
		return (print_opt_h());
	get_args(&env);
	check_resolve(&env);
	create_anthill(&env);
	find_way(&env);
	if (env.opt & O_SOL)
		return (print_sol(&env));
	ants_go(&env);
	(env.opt & O_COM) ? print_com(&env) : 0;
	free_all(&env);
	return (0);
}
