/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_toupper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 18:46:53 by esterna           #+#    #+#             */
/*   Updated: 2017/06/21 12:40:03 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char			*ft_str_toupper(char *str)
{
	char *tmp;

	tmp = str;
	while(*str)
	{
		*str = ft_toupper(*str);
		str++;
	}
	return (tmp);
}
