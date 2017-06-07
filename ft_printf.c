/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:08:42 by esterna           #+#    #+#             */
/*   Updated: 2017/06/06 18:36:57 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		setup_format(t_format f)
{
	f.pad = 0;
	f.sign = 0;
	f.width = 0;
	f.prefix = 0;
	f.precision = -1;
	f.n = 0;
	f.size = 0;
}

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

/**
 ** Checks for both format and width. Updates format struct.
 ** sign:	 0	: no sign
 **			 1	: preface with a space for positive numbers 
 **			 2	: sign all numbers, '+' in front of positives, etc.
 **	prefix:  0	: no prefix
 ** 		 1	: prefix all numbers
 **	pad:	 0	: no padding
 **			 1	: left-justify the object
 **		 	 2  : pads the number with zeroes instead of spaces
 ** width:	 #	: Minimum number of characters to be printed.
 **				  If the value to be printed is shorter than this number,
 **				  the result is padded with blank spaces.
 **				  The value is not truncated even if the result is larger. 
 **/
void			format_width(const char **current, t_format format)
{
	while (ft_strchr(FLAGS, **current))
	{
		switch(**current)
		{
			case '-' : format.pad = 1;
					   break;
			case '0' : format.pad |= 2;
					   while (**current == '0')
						   (*current)++;
					   break;
			case ' ' : if (!format.sign)
						   format.sign = 1;
					   break;
			case '+' : format.sign = 2;
					   break;
			case '#' : format.prefix = 1;
					   break;
		}
		(*current)++;
	}
	while ('0' <= **current && **current <= '9')
	{
		format.width = (format.width * 10) + (**current - '0');
		(*current)++;
	}
}

/**
** For integer specifiers (d, i, o, u, x, X) − 
** precision specifies the minimum number of digits to be written.
** If the value to be written is shorter than this number, the result is padded with leading zeros.
** The value is not truncated even if the result is longer.
** A precision of 0 means that no character is written for the value 0.
** For e, E and f specifiers − this is the number of digits to be printed after the decimal point.
** For g and G specifiers − This is the maximum number of significant digits to be printed.
** For s − this is the maximum number of characters to be printed.
** By default all characters are printed until the ending null character is encountered.
** For c type − it has no effect. When no precision is specified, the default is 1.
** If the period is specified without an explicit value for precision, 0 is assumed.
**/
void			format_precision(const char **current, t_format format)
{
	(*current)++;
	format.precision = 0;
	while ('0' <= **current && **current <= '9')
	{
		format.precision = (format.precision * 10) + (**current - '0');
		(*current)++;
	}
}

int				printi(long long n, char ch, t_format format)
{
	int p;
	int w;

	p = format.precision - ft_nbrsize(n);
	if (n > 0 &&
	while (p > 0)
	{
		
	}
	switch (ch)
	{
		case 'i':
		case 'd':
		case 'D':
		case 'u':
		case 'x':
		case 'X':
	}
}

int				ft_printf(const char *current, ...)
{
	unsigned int u;
	char *tmp;
	int *ntmp;
	int i;
	t_format format;
	void (*equ[127]) (void);
	va_list arg;
	
	va_start(arg, current);
	setup_format(format);
/**	equ['i'] = equ['d'] = printi((void)(i = va_arg(arg, int)), format); Don't remember what this line does **/
	while(*current)
	{
		while(*current != '%' && *current)
		{
			ft_putchar(*current);
			current++;
			format.n++;
		}
		if (!*current)
			break;
		current++;
		if (ft_strchr(FLAGS, *current))
			format_width(&current, format);
		if (*current == '.')
			format_precision(&current, format);
		if (!*current)
			break;
		switch(*current)
		{
			case '\0' : break;
			case 'h' : 
			case '%' : ft_putchar('%');
					   format.n++;
					   break;
			case 'c' : i = va_arg(arg, int);
					   ft_putchar(i);
					   format.n++;
					   break;
			case 'D' : i = va_arg(arg, long int);
					   if (format.pad == 0 || format.pad == 2)
						   padding(format.precision - ft_nbrsize_base(i, 10), format.pad);
					   if (!(format.precision == 0 && i == 0))
					   {
						   if (format.sign && i > 0)
							   ft_putchar((format.sign > 0) ? '+' : ' ');
						   ft_putnbr(i);
						   format.n = format.n + ft_strlen(ft_itoa_base(i, 10)) + ((format.sign) ? 1 : 0);
					   }
					   if (format.pad == 1 || format.pad == 3)
						   padding(format.precision - ft_nbrsize_base(i, 10), format.pad);
					   break;
			case 'i' :
			case 'd' : i = va_arg(arg, int);
					   if (format.pad == 0 || format.pad == 2)
						   padding(format.precision - ft_nbrsize_base(i, 10), format.pad);
					   if (!(format.precision == 0 && i == 0))
					   {
						   if (format.sign && i > 0)
							   ft_putchar((format.sign > 0) ? '+' : ' ');
						   ft_putnbr(i);
						   format.n = format.n + ft_strlen(ft_itoa_base(i, 10)) + ((format.sign) ? 1 : 0);
					   }
					   if (format.pad == 1 || format.pad == 3)
						   padding(format.precision - ft_nbrsize_base(i, 10), format.pad);
					   break;
			case 'o' : i = va_arg(arg, unsigned int);
					   if (format.pad == 0 || format.pad == 2)
						   padding(format.precision - ft_nbrsize_base(i, 8), format.pad);
					   if (!(format.precision == 0 && i == 0))
					   {
						   if (format.prefix && i)
							   ft_putchar('0');
						   ft_putstr(ft_itoa_base(i, 8));
						   format.n = format.n + ft_strlen(ft_itoa_base(i, 8)) + ((format.prefix) ? 1 : 0);
					   }
					   if (format.pad == 1 || format.pad == 3)
						   padding(format.precision - ft_nbrsize_base(i, 8), format.pad);
					   break;
			case 's' : tmp = va_arg(arg, char *);
					   if (!tmp)
					   {
						   ft_putstr("(null)");
						   format.n += 6;
					   }
					   else if (format.precision == 1)
					   {
						   ft_putstr(tmp);
						   format.n += ft_strlen(tmp);
					   }
					   else if (format.precision)
					   {
						   ft_putnstr(tmp, format.precision);
						   format.n += format.precision;
					   }
					   break;
			case 'x' : i = va_arg(arg, unsigned int);
					   if (format.pad == 0 || format.pad == 2)
						   padding(format.precision - ft_nbrsize_base(i, 16), format.pad);
					   if (!(format.precision == 0 && i == 0))
					   {
						   if (format.prefix && i)
							   ft_putstr("0x");
						   ft_putstr(ft_str_tolower(ft_itoa_base(i, 16)));
						   format.n = format.n + ft_strlen(ft_itoa_base(i, 16)) + ((format.prefix) ? 2 : 0);
					   }
					   if (format.pad == 1 || format.pad == 3)
						   padding(format.precision - ft_nbrsize_base(i, 16), format.pad);
					   break;
			case 'X' : i = va_arg(arg, unsigned int);
					   if (format.pad == 0 || format.pad == 2)
						   padding(format.precision - ft_nbrsize_base(i, 16), format.pad);
					   if (!(format.precision == 0 && i == 0))
					   {
						   if (format.prefix && i)
							   ft_putstr("0X");
						   ft_putstr(ft_itoa_base(i, 16));
						   format.n = format.n + ft_strlen(ft_itoa_base(i, 16)) + ((format.prefix) ? 2 : 0);
					   }
					   if (format.pad == 1 || format.pad == 3)
						   padding(format.precision - ft_nbrsize_base(i, 16), format.pad);
					   break;
			case 'u' : u = va_arg(arg, unsigned int);
					   if (format.pad == 0 || format.pad == 2)
						   padding(format.precision - ft_nbrsize_base(u, 10), format.pad);
					   if (!(format.precision == 0 && u == 0))
					   {
						   if (format.prefix)
							   ft_putchar('+');
						   ft_putnbr(u);
						   format.n = format.n + ft_strlen(ft_itoa_base(u, 10));
					   }
					   if (format.pad == 1 || format.pad == 3)
						   padding(format.precision - ft_nbrsize_base(u, 10), format.pad);
					   break;
			case 'n' : ntmp = va_arg(arg, int *);
					   *ntmp = format.n;
					   break;
		}
		if (*current)
			current++; /** May end up not being necessary. **/
	}
	va_end(arg);
	return (format.n);
}
