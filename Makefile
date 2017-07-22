# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esterna <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/26 17:01:46 by esterna           #+#    #+#              #
#    Updated: 2017/07/22 16:34:45 by esterna          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf
CFLAGS = -Wall -Wextra -Werror
DEPS = includes/libftprintf.h
_FUNCTIONS = char_repeat.c\
			find_exponent.c\
			format_setup.c\
			ft_dtoa_base.c\
			ft_dtosf_base.c\
			ft_fmod.c\
			ft_isdigit.c\
			ft_itoa_base.c\
			ft_modf.c\
			ft_nbrsize_base.c\
			ft_printf.c\
			ft_putchar.c\
			ft_putnbr.c\
			ft_putnstr.c\
			ft_putstr.c\
			ft_round_dbl.c\
			ft_str_tolower.c\
			ft_str_toupper.c\
			ft_strchr.c\
			ft_strcpy.c\
			ft_strdup.c\
			ft_strlen.c\
			ft_strnew.c\
			ft_tolower.c\
			ft_toupper.c\
			ft_ulltoa_base.c\
			print_ids.c\
			sort_dniux.c\
			sort_ps.c
FUNCTIONS = $(patsubt %,src/%,$(_FUNCTIONS))
OBJ = $(FUNCTIONS:.c=.o)

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -c $(FUNCTIONS) $(DEPS)
	ar rc $@.a $(OBJ)
	ranlib $@.a

exe:
	gcc $(CFLAGS) -g -o printf main_test.c $(FUNCTIONS)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f printf
	/bin/rm -f $(NAME).a
	/bin/rm -f $(NAME).h.gch

re: fclean all
