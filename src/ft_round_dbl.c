/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round_dbl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 14:22:13 by esterna           #+#    #+#             */
/*   Updated: 2017/07/20 14:34:22 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** This function takes a double and rounds to a certain number
** of places after the decimal point, given by the precision.
*/

double			ft_round(double dbl, int precision)
{
	int		n1;
	int		n2;
	int		p;
	double	dec;
	double	tmp;

	dec = 1;
	tmp = dbl;
	precision = (precision <= 0) ? 0 : precision;
	p = precision;
	n1 = (precision == 0) ? ((int)dbl) % 10 : 0;
	while (p)
	{
		tmp = (tmp - (int)((float)tmp)) * 10;
		n1 = (p == 1) ? (int)tmp : n1;
		p--;
	}
	tmp = (tmp - (int)((float)tmp)) * 10;
	n2 = (int)tmp;
	while (precision-- && dec != 0)
		dec = dec / 10;
	dbl = (int)((float)(dbl / dec)) * dec;
	dbl = (n2 > n1) ? dbl + dec : dbl;
	return (dbl);
}
