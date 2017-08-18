/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 19:08:21 by esterna           #+#    #+#             */
/*   Updated: 2017/08/17 22:36:10 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int			nbr_size(unsigned long long n, char sign, int base)
{
	int len;

	len = (sign == 'n' && base == 10) ? 1 : 0;
	if (sign == 'n' && base == 2)
		return (8);
	if (n == 0)
		len++;
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}

static char			*str_setup(unsigned long long n, char sign, int base)
{
	int		len;
	char	*nbr;

	len = nbr_size(n, sign, base);
	nbr = ft_strnew(len);
	if (base == 2 && sign == 'n')
	{
		len--;
		while (len >= 0)
			nbr[len--] = '0';
	}
	if (sign == 'n' && base == 10)
		*nbr = '-';
	return (nbr);
}

static char			*invert_binary(char	*nbr)
{
	char *tmp;

	tmp = nbr;
	while (*tmp)
	{
		*tmp = (*tmp == '0') ? '1' : '0';
		tmp++;
	}
	return (nbr);
}

char				*ft_ulltoa_base(unsigned long long n, char sign, int base)
{
	int		len;
	char	*nbr;
	char	*bstr;

	bstr = "0123456789abcdef";
	if (base < 2)
		return (NULL);
	len = nbr_size(n, sign, base) - 1;
	nbr = str_setup(n, sign, base);
	if (!nbr)
		return (NULL);
	while (len)
	{
		nbr[len--] = bstr[n % base];
		n = n / base;
	}
	if (nbr[len] != '-')
		nbr[len] = bstr[n % base];
	if (sign == 'n' && base == 2)
		nbr = invert_binary(nbr);
	return (nbr);
}
