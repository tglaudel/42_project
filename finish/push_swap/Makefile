# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/30 08:59:28 by tglaudel          #+#    #+#              #
#    Updated: 2016/05/17 16:08:34 by tglaudel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = srcs

SRC_NAME = main.c check_double.c print.c create_stack.c rotate.c add_move.c  \
		   swap.c rev_rotate.c push.c sort_all.c error.c free_all.c sort_last.c\

OBJ = $(SRC:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

NAME = push_swap

CC = gcc

LIBFT = libft/libft.a

CFLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -Iincludes -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -Iincludes -o $@

$(LIBFT):
	@make -C libft

clean:
	@rm -rf $(OBJ)
	@make -C libft/ clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft/ fclean

re: fclean all

.PHONY: all re clean fclean
