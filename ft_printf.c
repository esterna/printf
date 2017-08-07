/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:08:42 by esterna           #+#    #+#             */
/*   Updated: 2017/08/06 21:15:35 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*t_format	(*pr[2]) (char *str, char ch, t_format format);

char*		(*sort[4]) (t_format format, va_list arg);*/

t_format		parse_data(t_format format, va_list arg)
{
/*	pr[0] = printi;
	pr[1] = printd;
	sort[0] = sort_i;
	sort[1] = sort_x;
	sort[2] = sort_u;
	sort[3] = sort_d;*/
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
	while (**current != '%' && **current != '\0')
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
	while (*current)
	{
		format = initialise_format(format);
		format = print_curr((char **)&current, format);
		if (!*current || (*current == '%' && *(current + 1) == '\0'))
			break ;
		current++;
		format = find_format((char **)&current, format);
		if (!*current)
			break ;
		format.specifier = *current;
		if (ft_strchr(SPECS, *current) && *current != '\0')
		{
			format = parse_data(format, arg);
			current++;
		}
	}
	va_end(arg);
	return (format.n);
}
