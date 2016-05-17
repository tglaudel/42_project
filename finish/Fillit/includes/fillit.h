/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 09:30:01 by tglaudel          #+#    #+#             */
/*   Updated: 2015/12/21 17:34:26 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include "fillit.h"
# define BUF_SIZE 4096

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

typedef struct		s_tetri
{
	char			**content;
	struct s_tetri	*next;
}					t_tetri;

typedef struct		s_color
{
	int				index;
	char			*color;
}					t_color;

/*
** fonctions principales :
*/

int					ft_fillit(char *name);
t_tetri				*ft_creatlst(char *str, int nbtet);
void				ft_res(t_tetri *start, int nbtet);

/*
** fonctions secondaires :
*/

int					ft_check(char **tab);
void				ft_color(int n);
int					ft_checkone(char *src);
char				*ft_openread(char *name);
int					ft_count_tetri(char *str);
int					ft_lstcheck(t_tetri *tmp);
void				ft_print_tab(char **tab, int lt);
char				**ft_move_tet(char **tab);
char				**ft_new_tab(char **tab);
void				ft_free_tab(char **tab);

/*
** fonctions tests :
*/

void				ft_print_tet(char **tab);
void				ft_print_lst(t_tetri *tmp);

#endif
