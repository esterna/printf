/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dniux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 15:34:22 by esterna           #+#    #+#             */
/*   Updated: 2017/08/15 15:36:35 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char			*sort_i(t_format format, va_list arg)
{
	long long	i;
	intmax_t	j;

	if (format.length == -2)
		return (ft_itoa_base((signed char)va_arg(arg, int), 10));
	else if( format.length == -1)
		return (ft_itoa_base((short)va_arg(arg, int), 10));
	else if (0 <= format.length && format.length <= 2)
	{
		if (format.length == 1 || format.specifier == 'D')
			i = va_arg(arg, long int);
		else
			i = format.length != 0 ? va_arg(arg, long long) : va_arg(arg, int);
		return (ft_ulltoa_base(((i >= 0) ? i : i * -1),
					((i >= 0) ? 'p' : 'n'), 10));
	}
	else if (format.length == 3)
	{
		j = va_arg(arg, intmax_t);
		return (ft_ulltoa_base(((j >= 0) ? j : j * -1),
					((j >= 0) ? 'p' : 'n'), 10));
	}
	else if (format.length == 4)
	{
		i = va_arg(arg, long long);
		return (ft_ulltoa_base(((i >= 0) ? i : i * -1),
					((i >= 0) ? 'p' : 'n'), 10));
	}
	return (NULL);
}

char			*sort_x(t_format format, va_list arg)
{
	char	*tmp;
	int		base;

	base = (format.specifier == 'X' || format.specifier == 'x') ? 16 : 8;
	if (format.length == 1)
		tmp = ft_ulltoa_base(va_arg(arg, unsigned long), 'p', base);
	else if (format.length == -2)
		tmp = ft_ulltoa_base((unsigned char)va_arg(arg, unsigned int), 'p', base);
	else if (format.length == -1)
		tmp = ft_ulltoa_base((unsigned short)va_arg(arg, unsigned int), 'p', base);
	else if (format.length == 0)
		tmp = ft_ulltoa_base(va_arg(arg, unsigned int), 'p', base);
	else if (format.length == 2)
		tmp = ft_ulltoa_base(va_arg(arg, unsigned long long int), 'p', base);
	else if (format.length == 3)
		tmp = ft_ulltoa_base(va_arg(arg, uintmax_t), 'p', base);
	else if (format.length == 4)
		tmp = ft_ulltoa_base(va_arg(arg, size_t), 'p', base);
	if (65 <= format.specifier && format.specifier <= 90)
		return (ft_str_toupper(tmp));
	return (tmp);
}

char			*sort_u(t_format format, va_list arg)
{
	if (format.length == 1 || format.specifier == 'U')
		return (ft_ulltoa_base(va_arg(arg, unsigned long int), 'p', 10));
	else if (format.length == -2)
		return (ft_ulltoa_base((unsigned char)va_arg(arg, unsigned int), 'p', 10));
	else if (format.length == -1)
		return (ft_ulltoa_base((unsigned short)va_arg(arg, unsigned int), 'p', 10));
	else if (format.length == 0)
		return (ft_ulltoa_base(va_arg(arg, unsigned int), 'p', 10));
	else if (format.length == 2)
		return (ft_ulltoa_base(va_arg(arg, unsigned long long int), 'p', 10));
	else if (format.length == 3)
		return (ft_ulltoa_base(va_arg(arg, uintmax_t), 'p', 10));
	else if (format.length == 4)
		return (ft_ulltoa_base(va_arg(arg, size_t), 'p', 10));
	return (NULL);
}

char			*sort_d(t_format format, va_list arg)
{
	char		*tmp;
	long double	dbl;
	int			base;

	tmp = NULL;
	dbl = (format.length == 0) ? va_arg(arg, double) : va_arg(arg, long double);
	base = (format.specifier == 'A' || format.specifier == 'a') ? 16 : 10;
	if (format.specifier != 'a' && format.specifier != 'A')
		format.precision = format.precision >= 0 ? format.precision : 6;
	dbl = ft_round_dbl(dbl, format.precision);
	if (format.specifier == 'G' || format.specifier == 'g')
	{	
		if (find_exponent(dbl, 10) < -4 ||
				find_exponent(dbl, 10) >= format.precision)
		{
			format.specifier = format.specifier - 2;
			tmp = ft_dtosf_base(dbl, 10, format.precision);
		}
		else
		{
			tmp = ft_dtoa_base(dbl, base, dbl_frac_size(dbl, 10));
			format.specifier--;
		}
	}
	else if (format.specifier != 'F' && format.specifier != 'f')
		tmp = ft_dtosf_base(dbl, base, format.precision);
	else
		tmp = ft_dtoa_base(dbl, base, format.precision);
	if (65 <= format.specifier && format.specifier <= 90)
		tmp = ft_str_toupper(tmp);
	return (tmp);
}

void			sort_n(t_format format, va_list arg)
{
	if (format.length == -2)
		*(va_arg(arg, signed char *)) = format.n;
	else if (format.length == -1)
		*(va_arg(arg, short int *)) = format.n;
	else if (format.length == 0)
		*(va_arg(arg, int *)) = format.n;
	else if (format.length == 1)
		*(va_arg(arg, long int *)) = format.n;
	else if (format.length == 2)
		*(va_arg(arg, long long int *)) = format.n;
	else if (format.length == 3)
		*(va_arg(arg, intmax_t *)) = format.n;
	else if (format.length == 4)
		*(va_arg(arg, size_t *)) = format.n;
}
