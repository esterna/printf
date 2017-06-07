/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 11:53:19 by esterna           #+#    #+#             */
/*   Updated: 2017/06/02 11:53:22 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
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
//	ft_printf("signed %d = unsigned %u = hex %x\n", -3, -3, -3);
	ft_printf("%d %s(s)%", 0, "message");
	ft_printf("\n");
	ft_printf("%d %s(s) with %%\n", 0, "message"); /** Works but need to fix precision. **/
/**	ft_printf("justif: \"%-10s\"\n", "left");
	ft_printf("justif: \"%10s\"\n", "right");
	ft_printf(" 3: %04d zero padded\n", 3);
	ft_printf(" 3: %-4d left justif.\n", 3);
	ft_printf(" 3: %4d right justif.\n", 3);
	ft_printf("-3: %04d zero padded\n", -3);
	ft_printf("-3: %-4d left justif.\n", -3);
	ft_printf("-3: %4d right justif.\n", -3);**/
	
	return 0;
}
