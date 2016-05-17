/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 16:26:07 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/11 16:01:04 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "../libft/includes/libft.h"

# define C_RED		"\033[31m"
# define C_RED2		"\033[1;31m"
# define C_GREEN	"\033[32m"
# define C_GREEN2	"\033[1;32m"
# define C_YELLOW	"\033[33m"
# define C_YELLOW2	"\033[1;33m"
# define C_BLUE		"\033[34m"
# define C_BLUE2	"\033[1;34m"
# define C_MAGENTA	"\033[35m"
# define C_CYAN		"\033[36m"
# define C_GRAY		"\033[37m"
# define C_BLACK	"\033[30m"
# define C_NONE		"\033[0m"
# define O_COLOR 2
# define O_HELP 4
# define O_SOL 8
# define O_ROOM 16
# define O_COM 32

typedef struct		s_color
{
	int				index;
	char			*color;
}					t_color;

typedef struct		s_com
{
	char			*data;
	struct s_com	*next;
}					t_com;

typedef struct		s_args
{
	char			*data;
	struct s_args	*next;
}					t_args;

typedef struct		s_tube
{
	char			*name_a;
	char			*name_b;
	struct s_tube	*next;
}					t_tube;

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	int				connect;
	char			start;
	char			end;
	int				ants;
	struct s_room	**tab;
	struct s_room	*next;
}					t_room;

typedef struct		s_result
{
	t_room			*room;
	struct s_result	*next;
}					t_result;

typedef struct		s_sol
{
	t_result		*res_s;
	t_result		*res_e;
	int				nb_op;
	struct s_sol	*next;
}					t_sol;

typedef struct		s_ants
{
	int				id_ants;
	t_result		*res;
	struct s_ants	*next;
}					t_ants;

typedef struct		s_env
{
	t_room			*r_start;
	t_room			*r_end;
	t_tube			*t_start;
	t_tube			*t_end;
	t_args			*a_start;
	t_args			*a_end;
	t_com			*c_start;
	t_com			*c_end;
	t_result		*res_start;
	t_result		*res_end;
	t_sol			*sol_start;
	t_sol			*sol_end;
	t_ants			*ant_start;
	t_ants			*ant_end;
	int				opt;
	int				fd;
	int				ants;
	int				end_ants;
	int				start;
	int				end;
	int				nb_op_tmp;
	int				n_map;
}					t_env;

/*
** Fonctions gestion erreur :
*/

void				error(char *s);
void				check_resolve(t_env *env);

/*
** Fonctions get :
*/

void				get_args(t_env *env);
void				get_ants(t_env *env);
void				get_rooms(t_env *env);
void				add_com(t_env *env, char *s);
void				get_tubes(t_env *env);
void				add_result(t_env *env, t_room *room);
void				remove_result(t_env *env);
int					get_opt(char *av, int opt);

/*
** Fonctions algorythme :
*/

void				create_anthill(t_env *env);
int					find_way(t_env *env);
void				ants_go(t_env *env);

/*
** Fonctions print :
*/

void				print_args(t_env *env);
void				print_com(t_env *env);
void				print_rooms(t_env *env);
void				print_tubes(t_env *env);
void				print_result(t_sol *sol);
int					print_sol(t_env *env);
void				print_result_res(t_result *res);
void				print_map(t_env *env);
void				ft_color(int n);
int					print_opt_h(void);

/*
** Fonctions utils :
*/

int					tab_length(char **s);
int					ft_isallnum(char *s);
int					is_tube(t_args *arg, t_env *env);
int					is_room(t_args *arg, t_env *env, int mode);
int					is_command(t_args *arg);
int					is_ants(t_args *arg, t_env *env);
int					is_doublon_tube(char *s1, char *s2, t_env *env);
char				is_start(t_args *arg);
char				is_end(t_args *arg);
int					is_com(t_args *arg);

/*
** Fonctions free :
*/

void				free_all_args(t_env *env);
void				free_all_com(t_env *env);
void				free_all(t_env *env);
void				free_tab(char **s);
void				free_all_room(t_env *env);
void				free_all_tube(t_env *env);
void				free_all_sol(t_env *env);

#endif
