/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:08:42 by esterna           #+#    #+#             */
/*   Updated: 2017/08/15 20:01:35 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_format	(*pr[127]) (char *str, char ch, t_format format) =
{
	['i'] = printi,
	['d'] = printi,
	['D'] = printi,
	['O'] = printi,
	['o'] = printi,
	['x'] = printi,
	['X'] = printi,
	['u'] = printi,
	['U'] = printi,
	['p'] = printi,
	['a'] = printd,
	['A'] = printd,
	['e'] = printd,
	['E'] = printd,
	['f'] = printd,
	['F'] = printd,
	['g'] = printd,
	['G'] = printd
};

char*		(*sort[127]) (t_format format, va_list arg) =
{
	['i'] = sort_i,
	['d'] = sort_i,
	['D'] = sort_i,
	['O'] = sort_x,
	['o'] = sort_x,
	['x'] = sort_x,
	['X'] = sort_x,
	['u'] = sort_u,
	['U'] = sort_u,
	['a'] = sort_d,
	['A'] = sort_d,
	['e'] = sort_d,
	['E'] = sort_d,
	['f'] = sort_d,
	['F'] = sort_d,
	['g'] = sort_d,
	['G'] = sort_d
};

t_format	(*sort_pns[127]) (t_format format, va_list arg) =
{
	['p'] = sort_p,
	['C'] = sort_s,
	['c'] = sort_s,
	['s'] = sort_s,
	['S'] = sort_s,
	['n'] = sort_n
};

t_format		parse_data(t_format format, va_list arg)
{
	if (sort[(int)format.specifier] != NULL)
		format = (*pr[(int)format.specifier]) ((*sort[(int)format.specifier]) (format, arg), format.specifier, format);
	else if (sort_pns[(int)format.specifier] != NULL)
		format = (*sort_pns[(int)format.specifier]) (format, arg);
/*	if (format.specifier == 'p')
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
		format = printd(sort_d(format, arg), format.specifier, format);*/
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
