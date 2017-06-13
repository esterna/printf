/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:08:42 by esterna           #+#    #+#             */
/*   Updated: 2017/06/12 17:02:07 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/**
 ** Checks for both format and width. Updates format struct.
 ** sign:	 0	: no sign
 **			 1	: preface with a space for positive numbers 
 **			 2	: sign all numbers, '+' in front of positives, etc.
 **	prefix:  0	: no prefix
 ** 		 1	: prefix all numbers
 **	pad:	 0	: default right-justification and padding with spaces
 **			 1	: left-justify the object
 **		 	 2  : pads the number with zeroes instead of spaces
 **			 3+ : Both
 ** width:	 #	: Minimum number of characters to be printed.
 **				  If the value to be printed is shorter than this number,
 **				  the result is padded with blank spaces.
 **				  The value is not truncated even if the result is larger. 
 **/
t_format			format_width(const char **current, t_format format)
{
	while (ft_strchr(FLAGS, **current))
	{
		switch(**current)
		{
			case '-' : format.pad += 1;
						(*current)++;
					   break;
			case '0' : format.pad += 2;
					   while (**current == '0')
						   (*current)++;
					   break;
			case ' ' : if (!format.sign)
						   format.sign = 1;
						(*current)++;
					   break;
			case '+' : format.sign = 2;
					   (*current)++;
					   break;
			case '#' : format.prefix = 1;
					   (*current)++;
					   break;
		}
			}
	while ('0' <= **current && **current <= '9')
	{
		format.width = (format.width * 10) + (**current - '0');
		(*current)++;
	}
	return (format);
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
t_format			format_precision(const char **current, t_format format)
{
	(*current)++;
	format.precision = 0;
	while ('0' <= **current && **current <= '9')
	{
		format.precision = (format.precision * 10) + (**current - '0');
		(*current)++;
	}
	return (format);
}

/**
** Prints all number specifiers with precision and width applied.
**/
t_format				printi(char *str, char ch, t_format format)
{
	int prec;
	int width;
	char wch;

	prec = format.precision - ft_strlen(str);
	width = format.width - (ft_strlen(str) + ((prec > 0) ? prec : 0));
	wch = (format.pad <= 1) ? ' ' : '0';
	format.n += ((prec > 0) ? prec : 0) + ((width > 0) ? width : 0) + ft_strlen(str);
	if (format.sign && *str != '-')
		ft_putchar((format.sign == 1) ? ' ' : '+');
	else if (*str == '-' && wch == '0')
	{
		ft_putchar(*str);
		str++;
	}
	while ((!format.pad || format.pad == 2) && width > 0)
	{
		ft_putchar(wch);
		width--;
	}
	if (prec > 0 &&	*str != '0')
	{
		while (prec)
		{
			ft_putchar('0');
			prec--;
		}
	}
	if (format.prefix && *str != '0')
	{
		switch(ch)
		{
			case 'o' : ft_putchar('0');
					   break;
			case 'x' : ft_putstr("0x");
					   break;
			case 'X' : ft_putstr("0X");
					   break;
		}
	}
	if (!(prec == 0 && *str != '0'))
		ft_putstr(str);
	while (width > 0)
	{
		ft_putchar(wch);
		width--;
	}
	return (format);
}

/**
** Prints all string and character specifiers with precision and width applied
**/
t_format			prints(char *str, char ch, t_format format)
{
	char wch;
	
	format.width = format.width - ((!str) ? 6 : ((format.precision < 0 || format.precision > (int)ft_strlen(str))
													? ft_strlen(str) : format.precision));
	wch = (format.pad <= 1) ? ' ' : '0';
	while ((!format.pad || format.pad == 2) && format.width > 0)
	{
		ft_putchar(wch);
		format.width--;
		format.n++;
	}
	if (!str && ch == 's')
	{
		ft_putstr("(null)");
		format.n += 6;
	}
	else if (!str)
	{
		ft_putchar(ch);
		format.n++;
	}
	else
	{
		if (format.precision < 0)
		{
			ft_putstr(str);
			format.n += ft_strlen(str);
		}
		else
		{
			while (format.precision && *str)
			{
				ft_putchar(*str);
				str++;
				format.n++;
				format.precision--;
			}
		}
	}
	while (format.width > 0)
	{
		ft_putchar(wch);
		format.width--;
		format.n++;
	}
	return (format);
}

int				ft_printf(const char *current, ...)
{
	unsigned int u;
	char *tmp;
	int *ntmp;
	long int i;
	t_format format;
/**	void (*equ[127]) (void);**/
	va_list arg;
	
	va_start(arg, current);
	format.n = 0;
	/**equ['i'] = equ['d'] = equ['o'] = equ['x'] = equ['X'] = equ['u'] = &printi;**/
	while(*current)
	{
		format.pad = 0;
		format.sign = 0;
		format.width = 0;
		format.prefix = 0;
		format.precision = -1;
		format.size = 0;
		while(*current != '%' && *current)
		{
			ft_putchar(*current);
			current++;
			format.n++;
		}
		if (!*current)
			break;
		else if (*current == '%' && *(current + 1) == '\0')
		{
			format.n = -1;
			break;
		}
		current++;
		if (ft_strchr(FLAGS, *current) || ft_isdigit(*current))
			format = format_width(&current, format);
		if (*current == '.')
			format = format_precision(&current, format);
		if (!*current)
			break;
		switch(*current)
		{
			case '\0' : break;
			case 'h' : 
			case '%' : format = prints(NULL, '%', format);
					   break;
			case 'c' : i = va_arg(arg, int);
					   format = prints(NULL, i, format);
					   break;
			case 'D' : i = va_arg(arg, long int);
					   tmp = ft_ulltoa_base(((i >= 0) ? i : i * -1), ((i >= 0) ? 'p' : 'n'), 10);
					   format = printi(tmp, 'D', format);
					   break;
			case 'i' :
			case 'd' : i = va_arg(arg, int);
					   tmp = ft_ulltoa_base(((i >= 0) ? i : i * -1), ((i >= 0) ? 'p' : 'n'), 10);
					   format = printi(tmp, 'd', format);
					   break;
			case 'o' : u = va_arg(arg, unsigned int);
					   tmp = ft_ulltoa_base(u, 'p', 8);
					   format = printi(tmp, 'o', format);
					   break;
			case 's' : tmp = va_arg(arg, char *);
					   format = prints(tmp, 's', format);
					   break;
			case 'x' : u = va_arg(arg, unsigned int);
					   tmp = ft_str_tolower(ft_ulltoa_base(u, 'p', 16));
					   format = printi(tmp, 'x', format);
					   break;
			case 'X' : u = va_arg(arg, unsigned int);
					   tmp = ft_ulltoa_base(u, 'p', 16);
					   format = printi(tmp, 'X', format);
					   break;
			case 'u' : u = va_arg(arg, unsigned int);
					   tmp = ft_ulltoa_base(u, 'p', 10);
					   format = printi(tmp, 'u', format);
					   break;
			case 'n' : ntmp = va_arg(arg, int *);
					   *ntmp = format.n;
					   break;
			default  : ft_putchar('%');
					   ft_putchar(*current);
					   format.n += 2;
		}
		if (*current)
			current++;
	}
	va_end(arg);
	return (format.n);
}
