/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 19:08:21 by esterna           #+#    #+#             */
/*   Updated: 2017/07/20 14:20:53 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int			nbr_size(unsigned long long n, char sign, int base)
{
	int len;

	len = (sign == 'n' && base == 10) ? 2 : 1;
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
	nbr = (char *)malloc(sizeof(char) * len);
	if (!nbr)
		return (NULL);
	nbr[len - 1] = '\0';
	if (sign == 'n' && base == 10)
		*nbr = '-';
	return (nbr);
}

char				*ft_ulltoa_base(unsigned long long n, char sign, int base)
{
	int		len;
	char	*nbr;
	char	*bstr;

	bstr = "0123456789ABCDEF";
	if (base < 2)
		return (NULL);
	len = nbr_size(n, sign, base) - 2;
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
	return (nbr);
}
