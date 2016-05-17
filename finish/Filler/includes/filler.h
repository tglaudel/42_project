/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 10:47:30 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/18 16:20:12 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"
# define ABS(x) x < 0 ? -x : x

typedef struct		s_map
{
	char			**tab;
	int				line;
	int				col;
}					t_map;

typedef struct		s_piece
{
	char			**tab;
	int				line;
	int				col;
}					t_piece;

typedef struct		s_res
{
	int				x;
	int				y;
	int				n;
}					t_res;

typedef struct		s_env
{
	t_map			*map;
	t_piece			*piece;
	char			player;
	char			adv;
}					t_env;

/*
**	fonction get:
*/

void				get_player(t_env *env);
void				get_map(t_env *env);
void				get_piece(t_env *env);

/*
**	fonction algo:
*/

int					play(t_env *env, int x, int y);
int					simple_play(t_env *env);
int					contact_play(t_env *env, int x, int y);
int					try_add(t_env *env, int x, int y);
void				del_to_map(t_env *env);
void				add_to_map(t_env *env, int x, int y);

/*
**	fonction error & free:
*/

void				error(char *s);
void				print_tab(char **s);
void				ft_free_tab(char **s);
void				free_all(t_env *env);

#endif
