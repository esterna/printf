/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:08:42 by esterna           #+#    #+#             */
/*   Updated: 2017/06/01 22:57:52 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		padding(int n, int pad)
{
	char ch;

	if (n <= 0)
		return ;
	if (pad == 0 || pad == 1)
		ch = ' ';
	else
		ch = '0';
	while (n)
	{
		ft_putchar(ch);
		n--;
	}
}

int			ft_printf(const char *format, ...)
{
	const char *current;
	int	n;
	int pad;
	int sign;
	int width;
	int prefix;
	int precision;
	char *tmp;
	int *ntmp;
	unsigned int i;
	va_list arg;
	
	n = 0;
	va_start(arg, format);
	current = format;
	while(*current)
	{
		while(*current != '%' && *current)
		{
			ft_putchar(*current);
			current++;
			n++;
		}
		if (!*current)
			break;
		current++;
		pad = 0;
		sign = 0;
		width = 0;
		prefix = 0;
		precision = 1;
		switch(*current)
		{
			case '\0' : break;
			case '-' : pad = 1;
					   current++;
			case '0' :  pad |= 2;
						while (*current == '0')
							current++;
			case ' ' : sign = -1;
					   current++;
			case '+' : sign = 1;
					   current++;
			case '#' : prefix = 1;
					   current++;
					   while ('0' <= *current && *current <= '9')
						   width = (width * 10) + (*current - '0');
			case '.' : current++;
					   precision = 0;
					   while ('0' <= *current && *current <= '9')
						   precision = (precision * 10) + (*current - '0');
			case 'h' : 
			case '%' : ft_putchar('%');
					   n++;
					   break;
			case 'c' : i = va_arg(arg, int);
					   ft_putchar(i);
					   n++;
					   break;
			case 'D' : i = va_arg(arg, long int);
					   if (pad == 0 || pad == 2)
						   padding(precision - ft_nbrsize_base(i, 10), pad);
					   if (!(precision == 0 && i == 0))
					   {
						   if (sign && i > 0)
							   ft_putchar((sign > 0) ? '+' : ' ');
						   ft_putnbr(i);
						   n = n + ft_strlen(ft_itoa_base(i, 10)) + ((sign) ? 1 : 0);
					   }
					   if (pad == 1 || pad == 3)
						   padding(precision - ft_nbrsize_base(i, 10), pad);
					   break;
			case 'i' :
			case 'd' : i = va_arg(arg, int);
					   if (pad == 0 || pad == 2)
						   padding(precision - ft_nbrsize_base(i, 10), pad);
					   if (!(precision == 0 && i == 0))
					   {
						   if (sign && i > 0)
							   ft_putchar((sign > 0) ? '+' : ' ');
						   ft_putnbr(i);
						   n = n + ft_strlen(ft_itoa_base(i, 10)) + ((sign) ? 1 : 0);
					   }
					   if (pad == 1 || pad == 3)
						   padding(precision - ft_nbrsize_base(i, 10), pad);
					   break;
			case 'o' : i = va_arg(arg, unsigned int);
					   if (pad == 0 || pad == 2)
						   padding(precision - ft_nbrsize_base(i, 8), pad);
					   if (!(precision == 0 && i == 0))
					   {
						   if (prefix && i)
							   ft_putchar('0');
						   ft_putstr(ft_itoa_base(i, 8));
						   n = n + ft_strlen(ft_itoa_base(i, 8)) + ((prefix) ? 1 : 0);
					   }
					   if (pad == 1 || pad == 3)
						   padding(precision - ft_nbrsize_base(i, 8), pad);
					   break;
			case 's' : tmp = va_arg(arg, char *);
					   if (!tmp)
					   {
						   ft_putstr("(null)");
						   n += 6;
					   }
					   else if (precision == 1)
					   {
						   ft_putstr(tmp);
						   n += ft_strlen(tmp);
					   }
					   else if (precision)
					   {
						   ft_putnstr(tmp, precision);
						   n += precision;
					   }
					   break;
			case 'x' : i = va_arg(arg, unsigned int);
					   if (pad == 0 || pad == 2)
						   padding(precision - ft_nbrsize_base(i, 16), pad);
					   if (!(precision == 0 && i == 0))
					   {
						   if (prefix && i)
							   ft_putstr("0x");
						   ft_putstr(ft_str_tolower(ft_itoa_base(i, 16)));
						   n = n + ft_strlen(ft_itoa_base(i, 16)) + ((prefix) ? 2 : 0);
					   }
					   if (pad == 1 || pad == 3)
						   padding(precision - ft_nbrsize_base(i, 16), pad);
					   break;
			case 'X' : i = va_arg(arg, unsigned int);
					   if (pad == 0 || pad == 2)
						   padding(precision - ft_nbrsize_base(i, 16), pad);
					   if (!(precision == 0 && i == 0))
					   {
						   if (prefix && i)
							   ft_putstr("0X");
						   ft_putstr(ft_itoa_base(i, 16));
						   n = n + ft_strlen(ft_itoa_base(i, 16)) + ((prefix) ? 2 : 0);
					   }
					   if (pad == 1 || pad == 3)
						   padding(precision - ft_nbrsize_base(i, 16), pad);
					   break;
			case 'u' : i = va_arg(arg, unsigned int);
					   if (pad == 0 || pad == 2)
						   padding(precision - ft_nbrsize_base(i, 10), pad);
					   if (!(precision == 0 && i == 0))
					   {
						   if (prefix)
							   ft_putchar('+');
						   ft_putnbr(i);
						   n = n + ft_strlen(ft_itoa_base(i, 10));
					   }
					   if (pad == 1 || pad == 3)
						   padding(precision - ft_nbrsize_base(i, 10), pad);
					   break;
			case 'n' : ntmp = va_arg(arg, int *);
					   *ntmp = n;
					   break;
		}
		if (*current)
			current++; /** May end up not being necessary. **/
	}
	va_end(arg);
	return (n);
}
