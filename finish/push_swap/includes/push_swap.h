/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:15:40 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/17 16:10:27 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

typedef struct	s_s
{
	int			nbr;
	struct s_s	*next;
}				t_s;

typedef struct	s_m
{
	char		*move;
	struct s_m	*next;
}				t_m;

typedef struct	s_e
{
	t_s			*a_s;
	t_s			*a_e;
	t_s			*b_s;
	t_s			*b_e;
	t_m			*m_s;
	t_m			*m_e;
	int			pos;
	int			mid;
	int			len_a;
	int			len_b;
	int			opt;
	int			opt_v;
	int			opt_c;
	int			opt_m;
	int			err;
	int			nb_op;
}				t_e;

void			error(void);
void			free_all(t_e *env);

int				check_double(char **s, int i);

void			add_move(t_e *env, char *s);
void			print_move(t_e *env);
void			create_stack(t_e *env, char **s);
void			print_stack(t_e *env, char stack);
int				sort_all(t_e *env);

void			swap_a(t_e *env);
void			swap_b(t_e *env);
void			swap_ab(t_e *env);
void			rotate_a(t_e *env);
void			rotate_b(t_e *env);
void			rotate_ab(t_e *env);
void			rev_rotate_a(t_e *env);
void			rev_rotate_b(t_e *env);
void			rev_rotate_ab(t_e *env);
void			push_to_b(t_e *env);
void			push_to_a(t_e *env);
int				sort_last(t_e *env);
int				check_last(t_e *env);

#endif
