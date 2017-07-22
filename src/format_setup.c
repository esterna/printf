/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 21:55:32 by esterna           #+#    #+#             */
/*   Updated: 2017/07/21 18:08:36 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** Checks for both format and width. Updates format struct.
** sign:	 0	: no sign
**			 1	: preface with a space for positive numbers
**			 2	: sign all numbers, '+' in front of positives, etc.
**	prefix:  0	: no prefix
** 		 	 1	: prefix all numbers
**	pad:	 0	: default right-justification and padding with spaces
**			 1	: left-justify the object
**		 	 2  : pads the number with zeroes instead of spaces
**			 3+ : Both
** width:	 #	: Minimum number of characters to be printed.
**				  If the value to be printed is shorter than this number,
**				  the result is padded with blank spaces.
**				  The value is not truncated even if the result is larger.
*/

t_format			format_width(char **current, t_format format)
{
	while (ft_strchr(FLAGS, **current))
	{
		if (**current == '-')
			format.pad = 1;
		if (**current == '0' && format.pad == 0)
			format.pad = 2;
		if (**current == ' ')
			if (!format.sign)
				format.sign = 1;
		if (**current == '+')
			format.sign = 2;
		if (**current == '#')
			format.prefix = 1;
		(*current)++;
	}
	while ('0' <= **current && **current <= '9')
	{
		format.width = (format.width * 10) + (**current - '0');
		(*current)++;
	}
	return (format);
}

/*
** For integer specifiers (d, i, o, u, x, X) −
** precision specifies the minimum number of digits to be written.
** If the value to be written is shorter than
** this number, the result is padded with leading zeros.
** The value is not truncated even if the result is longer.
** A precision of 0 means that no character is written for the value 0.
**
** For e, E and f specifiers − this is the number of
** digits to be printed after the decimal point.
**
** For g and G specifiers − This is the maximum
** number of significant digits to be printed.
**
** For s − this is the maximum number of
** characters to be printed.
** By default all characters are printed
** until the ending null character is encountered.
**
** For c type − it has no effect. When no
** precision is specified, the default is 1.
**
** If the period is specified without
** an explicit value for precision, 0 is assumed.
*/

t_format			format_precision(char **current, t_format format)
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

/*
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
*/

t_format			format_length(char **current, t_format format)
{
	if (**current == 'h' && *(*current + 1) == 'h')
		format.length = -2;
	else if (**current == 'h')
		format.length = -1;
	else if (**current == 'l' && *(*current + 1) == 'l')
		format.length = 2;
	else if (**current == 'l' || **current == 'L')
		format.length = 1;
	else if (**current == 'j')
		format.length = 3;
	else if (**current == 'z')
		format.length = 4;
	while (ft_strchr(LENGTH, **current))
		(*current)++;
	return (format);
}

t_format			initialise_format(t_format format)
{
	format.pad = 0;
	format.sign = 0;
	format.width = 0;
	format.prefix = 0;
	format.precision = -1;
	format.length = 0;
	format.ptr = NULL;
	return (format);
}

t_format			find_format(char **current, t_format format)
{
	if (ft_strchr(FLAGS, **current) || ft_isdigit(**current))
		format = format_width(current, format);
	if (**current == '.')
		format = format_precision(current, format);
	if (ft_strchr(LENGTH, **current))
		format = format_length(current, format);
	return (format);
}
