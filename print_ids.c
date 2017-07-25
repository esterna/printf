/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ids.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 22:00:55 by esterna           #+#    #+#             */
/*   Updated: 2017/07/24 17:26:24 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


static int				find_width(char *str, char ch, t_format format)
{
	int width;
	int	strlen;
	int prec;

	prec = format.precision - ft_strlen(str) + ((*str == '-') ? 1 : 0);	
	width = format.width;
	strlen = ft_strlen(str)
				+ ((prec > 0) ? prec : 0)
				+ (((ch == 'o' || ch == 'O') && format.prefix) ? 1 : 0)
				+ (((ch == 'x' || ch == 'X') && format.prefix) ? 2 : 0)
				- ((format.precision == 0 && *str == '0') ? 1 : 0)
				+ ((format.sign && *str != '-') ? 1 : 0);
	width = width - strlen;
	return (width);
}

/*
** Prints all number specifiers with precision and width applied.
*/

t_format				printi(char *str, char ch, t_format format)
{
	int		prec;
	int		width;
	char	wch;

	prec = format.precision - ft_strlen(str) + ((*str == '-') ? 1 : 0);
	width = find_width(str, ch, format);
	wch = (format.pad <= 1 || format.precision >= 0) ? ' ' : '0';
	format.n += ((prec > 0) ? prec : 0) +
				((width > 0) ? width : 0) + ft_strlen(str) -
				((format.precision == 0 && *str == '0') ? 1 : 0) +
				((format.sign && *str != '-' && ch != 'u') ? 1 : 0);
	if (format.pad == 0 || (format.pad == 2 && wch == ' '))
	{
		char_repeat(wch, width);
		width = 0;	
	}
	if (format.sign != 0 && *str != '-' && ch != 'u')
		ft_putchar((format.sign == 1) ? ' ' : '+');
	else if (*str == '-' && wch == '0')
	{
		ft_putchar(*str);
		str++;
	}
	if (format.prefix && ft_strchr(PRINT_X_VALS, ch) && *str != '0')
	{
		ft_putchar('0');
		format.n++;
		if (ch != 'o')
		{
			ft_putchar(ch);
			format.n++;
		}
	}
	if (*str == '-' && str++)
			ft_putchar('-');
	if ((format.pad == 2 || format.pad == 3) && width > 0)
	{
		char_repeat(wch, width);
		width = 0;
	}
	if (!(format.precision == 0 && *str == '0'))
	{
		char_repeat('0', prec);
		ft_putstr(str);
	}
	if ((format.specifier == 'o' || format.specifier == 'O') && format.prefix == 1 && format.precision == 0 && *str == '0')
	{
		ft_putstr(str);
		format.n++;
	}
	char_repeat(wch, width);
	return (format);
}

/*
** Prints all string and character specifiers with precision and width applied
*/

t_format				prints(char *str, char ch, t_format format)
{
	char wch;

	format.width = format.width - ((!str) ? 1 :
			((format.precision < 0 || format.precision > (int)ft_strlen(str))
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

/*
** Prints all double specifiers with precision and width applied.
*/

t_format				printd(char *str, char ch, t_format format)
{
	int		width;
	char	wch;

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
			ft_putnstr(str, (*str == '-') ? 3 : 2);
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
