# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/30 08:59:28 by tglaudel          #+#    #+#              #
#    Updated: 2015/12/21 17:35:30 by tglaudel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = srcs

INC = ./includes

SRC_NAME = main.c \
		   ft_fillit.c \
		   ft_openread.c \
		   ft_checkone.c \
		   ft_lstcheck.c \
		   ft_count_tetri.c \
		   ft_creatlst.c \
		   ft_move_tet.c \
		   ft_check.c \
		   ft_resolve.c \
		   ft_new_tab.c \
		   ft_print.c \
		   ft_color.c \

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

NAME = fillit

CC = gcc

LIB = -lft

CFLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(NAME):
	@make -C libft/ fclean && make -C libft/
	@$(CC) $(CFLAGS) -c $(SRC) -I $(INC)
	@$(CC) $(CFLAGS) $(OBJ_NAME) -L libft/ -lft -o $(NAME)

clean:
	@rm -rf $(OBJ_NAME)
	@make -C libft/ clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft/ fclean

re: fclean all

.PHONY: all re clean fclean
