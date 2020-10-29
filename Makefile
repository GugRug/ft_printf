# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/03 18:56:21 by gumartin          #+#    #+#              #
#    Updated: 2020/10/29 18:38:18 by gumartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
FLAGS = -c
#SRCS_DIR	=	./libft
#SRCS		=	ft_printf.c				\
				$(SRCS_DIR)/ft_putnbr.c	\
				$(SRCS_DIR)/ft_strlen.c	\

SRCS		=	./ft_c_print.c\
				./ft_u_print.c\
				./ft_s_print.c\
				./ft_utils.c\
				./ft_flags.c\
				./ft_p_print.c\
				./ft_putnbr.c\
				./ft_di_print.c\
				./ft_xX_print.c\
				./ft_printf.c\
				./ft_clean.c


OBJS = $(SRCS:.c=.o)

all: $(NAME)
$(NAME): $(SRCS) printf.h
	gcc $(FLAGS) $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

#tst: all
#	$(CC) $(FLAGS) main.c $(SRCS)

#batata:
#	gcc -g *.c printf.h

.PHONY: all clean fclean re
