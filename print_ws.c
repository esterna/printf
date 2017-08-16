/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ws.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 16:22:10 by esterna           #+#    #+#             */
/*   Updated: 2017/08/16 16:33:07 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** Prints all string and character specifiers with precision and width applied
*/

t_format				prints(char *str, char ch, t_format format)
{
	char wch;

	wch = ch;
	format.width = format.width - ((!str) ? 1 :
			((format.precision < 0 || format.precision > (int)ft_strlen(str))
			? ft_strlen(str) : format.precision));
	wch = (format.pad >= 2) ? '0' : ' ';
	while ((!format.pad || format.pad == 2) && format.width > 0)
	{
		char_repeat(wch, format.width);
		format.n += format.width;
		format.width = 0;
	}
	if (!str)
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
	if (format.width > 0)
	{
		char_repeat(wch, format.width);
		format.n += format.width;
	}
	return (format);
}

/*
**	Prints all wide characters and wide character strings
**	with width and precision applied
*/

t_format				printws(wchar_t *str, wchar_t ch, t_format format)
{
	wchar_t wch;

	format.width = format.width - ((!str) ? 1 :
			((format.precision < 0 || format.precision > (int)ft_wstrlen(str))
			? ft_wstrlen(str) : format.precision));
	wch = (format.pad >= 2) ? '0' : ' ';
	if ((!format.pad || format.pad == 2) && format.width > 0)
	{
		char_repeat(wch, format.width);
		format.n += format.width;
		format.width = 0;
	}
	if (!str)
	{
		ft_putwchar(ch);
		format.n++;
	}
	else
	{
		if (format.precision < 0)
		{
			ft_putwstr(str);
			format.n += ft_wstrlen(str);
		}
		else
		{
			while (format.precision && *str)
			{
				ft_putwchar(*str);
				str++;
				format.n++;
				format.precision--;
			}
		}
	}
	if (format.width > 0)
	{
		char_repeat(wch, format.width);
		format.n += format.width;
	}
	return (format);
}
