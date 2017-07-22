/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 11:54:30 by esterna           #+#    #+#             */
/*   Updated: 2017/07/20 17:20:18 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <math.h>
# include <wchar.h>

# define FLAGS "-+ #0"
# define LENGTH "hljz"
# define PRINT_S_VALS "SsCc%"
# define PRINT_I_VALS "Ddi"
# define PRINT_D_VALS "aAeEfFgG"
# define PRINT_X_VALS "OoXx"

typedef	struct	s_format
{
	char	specifier;
	int		pad;
	int		sign;
	int		width;
	int		prefix;
	int		precision;
	int		n;
	int		length;
	char	*ptr;
}				t_format;

int				ft_isdigit(int n);

/*
** String manipulation
*/

char			*ft_strchr(const char *str, int c);

char			*ft_strcpy(char *dest, const char *src);

char			*ft_strdup(const char *src);

size_t			ft_strlen(const char *str);

char			*ft_strnew(size_t size);

char			*ft_str_tolower(char *str);

char			*ft_str_toupper(char *str);

int				ft_tolower(int c);

int				ft_toupper(int c);

/*
** Conversion functions
*/

int				find_exponent(double dbl, int base);

char			*ft_dtoa_base(double dbl, int base, int precision);

char			*ft_dtosf_base(double dbl, int base, int precision);

double			ft_fmod(double nb, double div);

char			*ft_itoa_base(int n, int base);

double			ft_modf(double x, double *integer);

double			ft_round(double dbl, int precision);

char			*ft_ulltoa_base(unsigned long long n, char sign, int base);

/*
** Format Functions
*/

t_format		find_format(char **current, t_format format);

t_format		initialise_format(t_format format);

t_format		format_length(char **current, t_format format);

t_format		format_precision(char **current, t_format format);

t_format		format_width(char **current, t_format format);

/*
** Printing Functions
*/

void			char_repeat(char ch, int n);

int				ft_printf(const char *format, ...);

t_format		printd(char *str, char ch, t_format format);

t_format		printi(char *str, char ch, t_format format);

t_format		prints(char *str, char ch, t_format format);

int				ft_nbrsize_base(int n, int base);

void			ft_putchar(char c);

void			ft_putnbr(int nb);

void			ft_putnstr(char *str, int n);

void			ft_putstr(char const *str);

/*
** Length Sorting Functions
*/

char			*sort_i(t_format format, va_list arg);

char			*sort_d(t_format format, va_list arg);

void			sort_n(t_format format, va_list arg);

t_format		sort_p(t_format format, va_list arg);

t_format		sort_s(t_format format, va_list arg);

char			*sort_u(t_format format, va_list arg);

char			*sort_x(t_format format, va_list arg);

#endif
