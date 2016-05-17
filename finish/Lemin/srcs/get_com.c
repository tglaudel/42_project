/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_com.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 18:45:42 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/11 14:30:07 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	add_com(t_env *env, char *s)
{
	t_com *tmp;

	if (!(tmp = (t_com*)malloc(sizeof(t_com))))
		error("Error malloc");
	if (env->c_start == NULL)
		env->c_start = tmp;
	tmp->data = s;
	tmp->next = NULL;
	if (env->c_end != NULL)
		env->c_end->next = tmp;
	env->c_end = tmp;
}
