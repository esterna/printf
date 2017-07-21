/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:08:42 by esterna           #+#    #+#             */
/*   Updated: 2017/07/20 15:44:35 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_format		parse_data(t_format format, va_list arg)
{
	if (format.specifier == 'p')
		format = sort_p(format, arg);
	else if (format.specifier == 'n')
		sort_n(format, arg);
	else if (ft_strchr(PRINT_S_VALS, format.specifier))
		format = sort_s(format, arg);
	else if (ft_strchr(PRINT_I_VALS, format.specifier))
		format = printi(sort_i(format, arg), format.specifier, format);
	else if (ft_strchr(PRINT_X_VALS, format.specifier))
		format = printi(sort_x(format, arg), format.specifier, format);
	else if (format.specifier == 'u' || format.specifier == 'U')
		format = printi(sort_u(format, arg), format.specifier, format);
	else if (ft_strchr(PRINT_D_VALS, format.specifier))
		format = printd(sort_d(format, arg), format.specifier, format);
	else
	{
		ft_putchar('%');
		ft_putchar(format.specifier);
		format.n += 2;
	}
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

int				ft_printf(const char *current, ...)
{
	t_format	format;
	va_list		arg;

	format.n = 0;
	va_start(arg, current);
	format = initialise_format(format);
	while (*current)
	{
		format = print_curr((char **)&current, format);
		if (!*current)
			break ;
		else if (*current == '%' && *(current + 1) == '\0')
		{
			format.n = -1;
			break ;
		}
		format = find_format((char **)&current, format);
		if (!*current)
			break ;
		format.specifier = *current;
		format = parse_data(format, arg);
	}
	va_end(arg);
	return (format.n);
}
