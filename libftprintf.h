/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 11:54:30 by esterna           #+#    #+#             */
/*   Updated: 2017/06/21 16:40:46 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define FLAGS "-+ #0"

typedef			struct s_format
{
	int pad;
	int sign;
	int width;
	int prefix;
	int precision;
	int n;
	int size;
}				   		t_format;

void		char_repeat(char ch, int n);

char		*ft_strnew(size_t size);

char		*ft_dtosf_base(double dbl, int base, int precision);

int			ft_printf(const char *format, ...);

int			ft_isdigit(int n);

char		*ft_itoa_base(int n, int base);

char		*ft_ulltoa_base(unsigned long long n, char sign, int base);

void		ft_putchar(char c);

void		ft_putnchar(char *str, int n);

int			ft_nbrsize_base(int n, int base);

void		ft_putnbr(int nb);

char		*ft_strchr(const char *str, int c);

size_t		ft_strlen(const char *str);

void		ft_putstr(char const *str);

void		ft_putnstr(char *str, int n);

char		*ft_str_tolower(char *str);

char		*ft_str_toupper(char *str);

int			ft_tolower(int c);

int			ft_toupper(int c);

double   	ft_round(double dbl, int precision);

int			find_exponent(double dbl, int base);

char		*ft_dtoa_base(double dbl, int base, int precision);

char		*ft_dtosf_base(double dbl, int base, int precision);

#endif
