/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 15:32:23 by esterna           #+#    #+#             */
/*   Updated: 2017/08/05 17:43:18 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_format		sort_s(t_format format, va_list arg)
{
	wchar_t		*wstr;
	char		*str;

	if ((format.length == 1 && format.specifier == 'c')
			|| format.specifier == 'C')
		format = printws(NULL, va_arg(arg, wchar_t), format);
	else if ((format.length == 1 && format.specifier == 's')
			|| format.specifier == 'S')
	{
		wstr = va_arg(arg, wchar_t *);
		format = printws((!wstr) ? (wchar_t *)"(null)" : wstr, 'S', format);
	}
	else if (format.specifier == '%')
		format = prints(NULL, format.specifier, format);
	else if (format.specifier == 'c')
		format = prints(NULL, va_arg(arg, int), format);
	else
	{
		str = va_arg(arg, char *);
		format = prints((!str) ? "(null)" : str, 's', format);
	}
	return (format);
}

t_format		sort_p(t_format format, va_list arg)
{
	void *ptr;

	ptr = va_arg(arg, void *);
	format.prefix = 1;
	if (!ptr)
		format = printi("0", 'p', format);
	else
		format = printi(ft_str_tolower(ft_ulltoa_base(
						(unsigned long int)ptr, 'p', 16)), 'p', format);
	return (format);
}
