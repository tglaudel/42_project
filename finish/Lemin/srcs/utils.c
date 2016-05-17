/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 18:18:18 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/09 16:17:19 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			tab_length(char **s)
{
	int i;

	i = 0;
	while (s[i] != NULL)
		i++;
	return (i);
}

int			ft_isallnum(char *s)
{
	int i;

	i = -1;
	while (s[++i])
	{
		if (ft_isdigit(s[i]) != 1)
			return (0);
	}
	return (1);
}

int			is_doublon_tube(char *s1, char *s2, t_env *env)
{
	t_tube *tmp;

	tmp = env->t_start;
	while (tmp)
	{
		if (ft_strcmp(s1, s2) == 0)
			return (-1);
		if (ft_strcmp(s1, tmp->name_a) == 0 && ft_strcmp(s2, tmp->name_b) == 0)
			return (-1);
		if (ft_strcmp(s2, tmp->name_a) == 0 && ft_strcmp(s1, tmp->name_b) == 0)
			return (-1);
		tmp = tmp->next;
	}
	return (1);
}
