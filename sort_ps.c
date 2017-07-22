/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 15:32:23 by esterna           #+#    #+#             */
/*   Updated: 2017/07/21 18:27:42 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_format		sort_s(t_format format, va_list arg)
{
	if ((format.length == 1 && format.specifier == 'c')
			|| format.specifier == 'C')
		format = prints(NULL, va_arg(arg, wint_t), format);
	else if ((format.length == 1 && format.specifier == 's')
			|| format.specifier == 'S')
		format = prints((char *)va_arg(arg, wchar_t *), 'S', format);
	else if (format.specifier == '%')
		format = prints(NULL, format.specifier, format);
	else if (format.specifier == 'c')
		format = prints(NULL, va_arg(arg, int), format);
	else
		format = prints(va_arg(arg, char *), 's', format);
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
