# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esterna <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/26 17:01:46 by esterna           #+#    #+#              #
#    Updated: 2017/06/12 17:11:17 by esterna          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf
CFLAGS = -Wall -Wextra -Werror
DEPS = libftprintf.h
FUNCTIONS = $(wildcard *.c)
OBJ = $(FUNCTIONS:.c=.o)

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -c $(FUNCTIONS) $(DEPS)
	ar rc $@.a $(OBJ)
	ranlib $@.a

exe:
	gcc $(CFLAGS) -g -o printf main_test.c ft_printf.c ft_ulltoa_base.c libftprintf.a

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f printf
	/bin/rm -f $(NAME).a
	/bin/rm -f $(NAME).h.gch

re: fclean all
