/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtosf_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 13:47:49 by esterna           #+#    #+#             */
/*   Updated: 2017/08/07 19:59:56 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** This function finds the resulting double
** after dividing by the base (10 or 2)
** to the power of the result of find_exponent.
*/

static double		find_starting_point(double dbl, int base)
{
	int		exp;
	double	div;
	double	b;

	b = (base == 10) ? 10.0 : 2.0;
	div = 1.0;
	exp = find_exponent(dbl, base);
	while (exp > 0)
	{
		div = div * b;
		exp--;
	}
	while (exp < 0)
	{
		div = div / b;
		exp++;
	}
	return (dbl / div);
}

int					find_precision(double dbl, int base)
{
	double	start;
	int		tmp;
	int		n;

	n = 0;
	start = find_starting_point(dbl, base);
	tmp = (int)start;
	start = start - tmp;
	while (0 < start && start < 1)
	{
		start *= 10.0;
		n++;
		tmp = (int)start + 1;
		start = start - (double)tmp;
	}
	return (n);
}

/*
** This function takes the given double, base,
** and precision and sets up the return string,
** with the NULL character, the exponent and exponent
** sign, e or p, the '-' if negative, and
** 0x if hexadecimal.
*/

static char			*str_setup(double dbl, int base, int precision)
{
	char	*sf;
	int		exp;
	int		len;

	exp = find_exponent(dbl, base);
	len = 5 + ((precision > 0) ? precision + 1 : 0) + ((dbl < 0) ? 1 : 0)
		+ ((base == 16) ? 2 : 0);
	sf = ft_strnew(sizeof(char) * len);
	*sf = (dbl < 0.0) ? '-' : '\0';
	if (base == 10 && precision != 0)
		*(sf + ((dbl < 0.0) ? 2 : 1)) = '.';
	else if (base == 16)
	{
		*(sf + ((dbl < 0.0) ? 1 : 0)) = '0';
		*(sf + 1 + ((dbl < 0.0) ? 1 : 0)) = 'x';
		if (precision != 0)
			*(sf + 3 + ((dbl < 0.0) ? 1 : 0)) = '.';
	}
	len--;
	sf[len--] = (((exp < 0) ? exp * -1 : exp) % 10) + '0';
	sf[len--] = (((exp /= 10) < 0) ? exp * -1 : exp) + '0';
	sf[len--] = (find_exponent(dbl, base) >= 0) ? '+' : '-';
	sf[len--] = (base == 10) ? 'e' : 'p';
	return (sf);
}

static char			*nan_inf(double dbl)
{
	if (dbl == INFINITY)
		return (ft_strdup("inf"));
	else if (dbl == -INFINITY)
		return (ft_strdup("-inf"));
	else if (dbl == NAN)
		return (ft_strdup("nan"));
	return (ft_strdup("-nan"));
}

char				*ft_dtosf_base(double dbl, int base, int precision)
{
	char	*sf;
	char	*bstr;
	char	*tmp;

	bstr = "0123456789abcdef";
	if (base < 2)
		return (NULL);
	if (dbl == INFINITY || dbl == -INFINITY || dbl == NAN || dbl == -NAN)
		return (nan_inf(dbl));
	precision = (precision >= 0) ? precision : find_precision(dbl, base);
	sf = str_setup(dbl, base, precision);
	tmp = sf + ((dbl < 0) ? 1 : 0) + ((base == 16) ? 2 : 0);
	if (dbl < 0)
		dbl = dbl * -1.0;
	dbl = find_starting_point(dbl, base);
	*tmp = bstr[(int)((float)dbl)];
	tmp = tmp + ((precision != 0) ? 2 : 1);
	while (*tmp != 'e' && *tmp != 'p')
	{
		dbl = ft_round_dbl(ft_fmod(dbl, 1.0), precision--) * base;
		*tmp = bstr[(long)(*(tmp + 1) == 'e' || *(tmp + 1) == 'p'
				? ft_round_dbl(dbl, 0.0) : dbl)];
		tmp++;
	}
	return (sf);
}
