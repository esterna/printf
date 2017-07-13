/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:08:42 by esterna           #+#    #+#             */
/*   Updated: 2017/07/12 16:52:23 by esterna          ###   ########.fr       */
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
** Specifies how the argument is to interpreted.
** See: http://www.cplusplus.com/reference/cstdio/printf/
** hh : -2
** h  : -1
** l  :  1
** ll :  2
** j  :  3
** z  :  4
** Length is intitialized as 0, representing no length modification.
** How the length changes the argument representation will depend on 
** on the specifier and will be sorted appropriately.
**/
t_format				format_length(const char **current, t_format format)
{
	if (**current == 'h' && *(*current + 1) == 'h')
		format.size = -2;
	else if (**current == 'h')
		format.size = -1;
	else if (**current == 'l' && *(*current + 1) == 'l')
		format.size = 2;
	else if (**current == 'l')
		format.size = 1;
	else if (**current == 'j')
		format.size = 3;
	else if (**current == 'z')
		format.size = 4;
	while (ft_strchr(LENGTH, **current))
	   (*current)++;
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
	if (format.prefix && (*str != '0' || ch == 'p'))
	{
		switch(ch)
		{
			case 'o' : ft_putchar('0');
					   format.n++;
					   break;
			case 'p' :
			case 'x' : ft_putstr("0x");
					   format.n += 2;
					   break;
			case 'X' : ft_putstr("0X");
					   format.n += 2;
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

t_format		printd(char *str, char ch, t_format format)
{
	int width;
	char wch;

	width = format.width - ft_strlen(str);
	wch = (format.pad <= 1) ? ' ' : '0';
	format.n += ((width > 0) ? width : 0) + ft_strlen(str)
				+ ((format.prefix && !format.precision) ? 1 : 0);
	if (!format.pad && width > 0 && wch == ' ')
	{
		char_repeat(wch, width);
		width = 0;
	}
	if (format.sign && *str != '-')
		ft_putchar((format.sign == 1) ? ' ' : '+');
	else if (wch == '0')
	{
		if (ch == 'a' || ch == 'A')
		{
			ft_putnchar(str, (*str == '-') ? 3 : 2);
			str = str + ((*str == '-') ? 3 : 2);
		}
		else if (*str == '-')
		{
			ft_putchar(*str);
			str++;
		}
	}
	if (width > 0 && wch == '0')
	{
		char_repeat(wch, width);
		width = 0;
	}
	if (ch == 'e' || ch == 'E')
	{
		ft_putchar(*str);
		str++;
	}
	else if (ch == 'a' || ch == 'A')
	{
		ft_putnstr(str, 3);
		str += 3;
	}
	else if (ch == 'f' || ch == 'F')
		ft_putstr(str);
	if (format.prefix && *str != '.' && format.precision == 0)
		ft_putchar('.');
	if (ch != 'f' && ch != 'F')
		ft_putstr(str);
	if (width > 0)
		char_repeat(wch, width);
	return (format);
}

int				ft_printf(const char *current, ...)
{
	unsigned long int u;
	const void *ptr;
	char *tmp;
	wchar_t *wtmp;
	int *ntmp;
	long int i;
	wint_t ch;
	double dbl;
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
		if (ft_strchr(LENGTH, *current))
			format = format_length(&current, format);
		if (!*current)
			break;
		switch(*current)
		{
			case '\0' : break;
			case 'h' : 
			case '%' : format = prints(NULL, '%', format);
					   break;
			case 'C' : ch = va_arg(arg, wint_t);
					   format = prints(NULL, ch, format);
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
			case 'a' : dbl = va_arg(arg, double);
						tmp = ft_dtosf_base(dbl, 16, format.precision);
					   format = printd(tmp, 'a', format);
					   break;
			case 'A' : dbl = va_arg(arg, double);
						tmp = ft_str_toupper(ft_dtosf_base(dbl, 16, format.precision));
					   format = printd(tmp, 'A', format);
					   break;
			case 'e' : dbl = va_arg(arg, double);
						format.precision = format.precision >= 0 ? format.precision : 6;
						tmp = ft_dtosf_base(dbl, 10, format.precision);
					   format = printd(tmp, 'e', format);
					   break;
			case 'E' : dbl = va_arg(arg, double);
						format.precision = format.precision >= 0 ? format.precision : 6;
						tmp = ft_str_toupper(ft_dtosf_base(dbl, 10, format.precision));
					   format = printd(tmp, 'E', format);
					   break;
			case 'F' :
			case 'f' : dbl = va_arg(arg, double);
						format.precision = format.precision >= 0 ? format.precision : 6;
					   tmp = ft_dtoa_base(dbl, 10, format.precision);
					   format = printd(tmp, 'f', format);
					   break;
			case 'g' : dbl = va_arg(arg, double);
						format.precision = format.precision >= 0 ? format.precision : 6;
						if (find_exponent(dbl, 10) < -4 || find_exponent(dbl, 10) >= format.precision)
						{
							tmp = ft_dtosf_base(dbl, 10, format.precision);
							format = printd(tmp, 'e', format);
						}
						else
						{
							tmp = ft_dtoa_base(dbl, 10, format.precision);
							format = printd(tmp, 'f', format);
						}
					   break;
			case 'G' : dbl = va_arg(arg, double);
						format.precision = format.precision >= 0 ? format.precision : 6;
						if (find_exponent(dbl, 10) < -4 || find_exponent(dbl, 10) >= format.precision)
						{
							tmp = ft_str_toupper(ft_dtosf_base(dbl, 10, format.precision));
							format = printd(tmp, 'E', format);
						}
						else
						{
							tmp = ft_dtoa_base(dbl, 10, format.precision);
							format = printd(tmp, 'F', format);
						}
					   break;
			case 'O' : u = va_arg(arg, unsigned long int);
					   tmp = ft_ulltoa_base(u, 'p', 8);
					   format = printi(tmp, 'o', format);
					   break;
			case 'o' : u = va_arg(arg, unsigned int);
					   tmp = ft_ulltoa_base(u, 'p', 8);
					   format = printi(tmp, 'o', format);
					   break;
			case 's' : tmp = va_arg(arg, char *);
					   format = prints(tmp, 's', format);
					   break;
			case 'S' : wtmp = va_arg(arg, wchar_t *);
					   format = prints(wtmp, 'S', format);
					   break;
			case 'x' : u = va_arg(arg, unsigned int);
					   tmp = ft_str_tolower(ft_ulltoa_base(u, 'p', 16));
					   format = printi(tmp, 'x', format);
					   break;
			case 'X' : u = va_arg(arg, unsigned int);
					   tmp = ft_ulltoa_base(u, 'p', 16);
					   format = printi(tmp, 'X', format);
					   break;
			case 'U' : u = va_arg(arg, unsigned long int);
					   tmp = ft_ulltoa_base(u, 'p', 10);
					   format = printi(tmp, 'u', format);
					   break;
			case 'u' : u = va_arg(arg, unsigned int);
					   tmp = ft_ulltoa_base(u, 'p', 10);
					   format = printi(tmp, 'u', format);
					   break;
			case 'p' : ptr = va_arg(arg, void *);
					   format.prefix = 1;
					   if (!ptr)
						   format = printi("0", 'p', format);
					   else
					   {
						   tmp = ft_str_tolower(ft_ulltoa_base((unsigned long int)ptr, 'p', 16));
						   format = printi(tmp, 'p', format);
					   }
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

t_format		initialise_format(t_format format)
{
	format.pad = 0;
	format.sign = 0;
	format.width = 0;
	format.prefix = 0;
	format.precision = -1;
	format.size = 0;
	return (format);
}

t_format		print_curr(char **current, t_format format)
{
	while (**current != '%' && **current)
	{
		ft_putchar(**current);
		(*current)++;
		format.n++;
	}
	return (format);
}

t_format		find_format(char **current, t_format format)
{
	if (ft_strchr(FLAGS, **current) || ft_isdigit(**current))
		format = format_width(current, format);
	if (*current == '.')
		format = format_precision(current, format);
	if (ft_strchr(LENGTH, **current))
		format = format_length(current, format);
	return (format);
}

t_format		parse_data(t_format format, va_list arg)
{
	char *tmp;
	void *ptr;

	if (format.specifier == 'p')
	{
		ptr = va_arg(arg, void *);
		format.prefix = 1;
		if (!ptr)
			format = printi("0", 'p', format);
		else
			format = printi(ft_str_tolower(
						ft_ulltoa_base((unsigned long int)ptr, 'p', 16)), 'p', format);	
	}
	else if (ft_strchr(PRINT_S_VALS, format.specifier))
	{
		if ((format.length == 1 && format.specifier == 'c') || format.specifier == 'C')
			format = prints(NULL, va_arg(arg, wint_t), format);
		else if ((format.length == 1 && format.specifier == 's') || format.specifier == 'S')
			format = prints(va_arg(arg, wchar_t *), 'S', format);
		else if (format.specifier == '%' || format.specifier == 'c')
			format = prints(NULL, format.specifier, format);
		else
			format = prints(va_arg(arg, char *), 's', format);
	}
	else if (ft_strchr(PRINT_I_VALS, format.specifier))
	{
		tmp = (format.specifier == 'd' || format.specifier == 'i' || format.specifier == 'D') ? sort_d(format, arg) : sort_x(format, arg);
		format = printi(tmp, format.specifier, format);
	}
	else if (ft_strchr(PRINT_D_VALS, format.specifier))
		something
	else
	{
		ft_putchar('%');
		ft_putchar(format.specifier);
		format.n += 2;
	}
	return (format);	
}

char			*sort_d(t_format format, va_list arg)
{
	long long	i;
	intmax_t	j;
	size_t		s;

	if (format.length == 1 || format.specifier == 'D')
	{
		i = va_arg(arg, long int); 
		return (ft_ulltoa_base(((i >= 0) ? i : i * -1), ((i >= 0) ? 'p' : 'n'), 10));
	}
	else if (format.length == -2)
		return (ft_itoa((int)va_arg(arg, signed char)));
	else if (format.length == -1)
		return (ft_itoa((int)va_arg(arg, short int)));
	else if (format.length == 0)
	{
		i = va_arg(arg, int);
		return (ft_ulltoa_base(((i >= 0) ? i : i * -1), ((i >= 0) ? 'p' : 'n'), 10));
	}
	else if (format.length == 2)
	{
		i = va_arg(arg, long long);
		return (ft_ulltoa_base(((i >= 0) ? i : i * -1), ((i >= 0) ? 'p' : 'n'), 10));
	}
	else if (format.length == 3)
	{
		j = va_arg(arg, intmax_t);
		return (ft_ulltoa_base(((j >= 0) ? j : j * -1), ((j >= 0) ? 'p' : 'n'), 10));
	}
	else if (format.length == 4)
	{
		s = va_arg(arg, size_t);
		return (ft_ulltoa_base(((s >= 0) ? s : s * -1), ((s >= 0) ? 'p' : 'n'), 10));
	}
}

char			*sort_x(t_format format, va_list arg)
{

}

int				ft_printf(const char *current, ...)
{
	t_format format;
	va_list arg;

	format.n = 0;
	va_start(arg, current);
	format = initialise_format(format);
	while (*current)
	{
		format = print_curr(&current, format);
		if (!*current)
			break;
		else if (*current == '%' && *(current + 1) == '\0')
		{
			format.n = -1;
			break;
		}
		format = find_format(&current, format);
		if (!*current)
			break;
		format.specifier = *current;
		format = parse_data(format, arg);
	}
	va_end(arg);
	return (format.n);
}
