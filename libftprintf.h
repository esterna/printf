/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 11:54:30 by esterna           #+#    #+#             */
/*   Updated: 2017/07/12 15:54:36 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <math.h>

# define FLAGS "-+ #0"
# define LENGTH "hljz"

typedef			struct s_format
{
	char	specifier;
	int		pad;
	int		sign;
	int		width;
	int		prefix;
	int		precision;
	int		n;
	int		size;
	char	*ptr;
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

char		*ft_strdup(const char *src);

char		*ft_strcpy(char *dest, const char *src);

void		ft_putstr(char const *str);

void		ft_putnstr(char *str, int n);

char		*ft_str_tolower(char *str);

char		*ft_str_toupper(char *str);

int			ft_tolower(int c);

int			ft_toupper(int c);

double   	ft_round(double dbl, int precision);

int			find_exponent(double dbl, int base);

double		ft_fmod(double nb, double div);

double		modf(double x, double *integer);

char		*ft_dtoa_base(double dbl, int base, int precision);

char		*ft_dtosf_base(double dbl, int base, int precision);

#endif
