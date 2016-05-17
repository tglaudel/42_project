# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/30 08:59:28 by tglaudel          #+#    #+#              #
#    Updated: 2016/03/18 15:33:09 by tglaudel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = srcs

SRC_NAME = main.c \
		   get_piece.c \
		   get_player.c \
		   get_map.c \
		   play.c \
		   simple_play.c \
		   utils.c \


OBJ = $(SRC:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

NAME = filler

CC = gcc

LIBFT = libft/libft.a

CFLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -Iincludes -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -Iincludes -o $@

$(LIBFT):
	make -C libft

clean:
	rm -rf $(OBJ)
	make -C libft/ clean

fclean: clean
	rm -rf $(NAME)
	make -C libft/ fclean

re: fclean all

.PHONY: all re clean fclean
