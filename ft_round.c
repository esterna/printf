/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 18:06:33 by esterna           #+#    #+#             */
/*   Updated: 2017/06/20 18:09:43 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** This function takes a double and rounds to a certain number
** of places after the decimal point, given by the precision.
*/

double   		ft_round(double dbl, int precision)
{
	int n1;
	int n2;
	int p;
	double dec;
	double tmp;

	dec = 1;
	tmp = dbl;
	if (precision <= 0)
		precision = 0;
	p = precision;
	if (precision == 0)
		n1 = ((int)dbl) % 10;
	while (p > 0)
	{
		tmp = (tmp - (int)((float)tmp)) * 10;
		if (p == 1)
			n1 = (int)tmp;
		p--;
	}
	tmp = (tmp - (int)((float)tmp)) * 10;
	n2 = (int)tmp;
	while (precision > 0 && dec != 0)
	{
		dec = dec / 10;
		precision--;
	}
	dbl = (int)(dbl / dec) * dec;
	if (n2 > n1)
		dbl = dbl + dec;
	return (dbl);
}
