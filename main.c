/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 11:44:42 by esterna           #+#    #+#             */
/*   Updated: 2017/06/01 22:33:30 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"
#include <stdio.h>

int main(void)
{
	char *ptr = "Hello world!";
	char *np = 0;
	int i = 5;
	unsigned int bs = sizeof(int)*8;
	int mi;

	mi = (1 << (bs-1)) + 1;
	ft_printf("%s\n", ptr);
	ft_printf("ft_printf test\n");
	ft_printf("%s is a null pointer\n", np);
	ft_printf("%d = 5\n", i);
	ft_printf("%d = - max int\n", mi);
	ft_printf("char %c = 'a'\n", 'a');
	ft_printf("hex %x = ff\n", 0xff);
	ft_printf("hex %02x = 00\n", 0); 
	ft_printf("signed %d = unsigned %u = hex %x\n", -3, -3, -3);
	ft_printf("%d %s(s)%", 0, "message");
	ft_printf("\n");
	ft_printf("%d %s(s) with %%\n", 0, "message"); /** Works but need to fix precision. **/
	
	return 0;
}
