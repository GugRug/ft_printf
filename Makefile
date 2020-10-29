# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/03 18:56:21 by gumartin          #+#    #+#              #
#    Updated: 2020/10/29 13:35:22 by gumartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror -c
SRCS_DIR	=	./libft
SRCS		=	ft_printf.c				\
				$(SRCS_DIR)/ft_putnbr.c	\
				$(SRCS_DIR)/ft_strlen.c	\


OBJS = $(SRCS:.c=.o)

all: $(NAME)
	$(NAME): $(SRCS) 
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

tst: all
	$(CC) $(FLAGS) main.c $(SRCS)

batata:
	gcc -g *.c printf.h

.PHONY: all clean fclean re
