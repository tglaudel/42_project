# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 14:29:20 by tglaudel          #+#    #+#              #
#    Updated: 2015/12/20 08:41:55 by tglaudel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./

SRC_NAME = ft_memset.c ft_memalloc.c ft_lstnew.c \
		   ft_bzero.c ft_memdel.c ft_lstdelone.c \
		   ft_memcpy.c ft_strnew.c ft_lstdel.c \
		   ft_memccpy.c ft_strdel.c ft_lstadd.c \
		   ft_memmove.c ft_strclr.c ft_lstiter.c \
		   ft_memchr.c ft_striter.c ft_lstmap.c \
		   ft_memcmp.c ft_striteri.c ft_power.c \
		   ft_strlen.c ft_strmap.c ft_lstaddback.c \
		   ft_strdup.c ft_strmapi.c ft_count_word.c \
		   ft_strcpy.c ft_strequ.c ft_lenword.c \
		   ft_strncpy.c ft_strnequ.c ft_sqrtlow.c \
		   ft_strcat.c ft_strsub.c ft_putstr_color.c \
		   ft_strncat.c ft_strjoin.c ft_itoa_base.c \
		   ft_strlcat.c ft_strtrim.c \
		   ft_strchr.c ft_strsplit.c \
		   ft_strrchr.c ft_itoa.c \
		   ft_strstr.c ft_putchar.c \
		   ft_strnstr.c ft_putstr.c \
		   ft_strcmp.c ft_putendl.c \
		   ft_strncmp.c ft_putnbr.c \
		   ft_atoi.c ft_putchar_fd.c \
		   ft_isalpha.c ft_putstr_fd.c \
		   ft_isdigit.c ft_putendl_fd.c\
		   ft_isalnum.c ft_putnbr_fd.c \
		   ft_isascii.c \
		   ft_isprint.c \
		   ft_toupper.c \
		   ft_tolower.c \


OBJ_NAME = $(SRC_NAME:.c=.o)
NAME = libft.a
CC = gcc
CFLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -c $(SRC_NAME) -I ./includes
	@ar rc $(NAME) $(OBJ_NAME)

clean:
	@rm -rf $(OBJ_NAME)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

