/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 11:53:19 by esterna           #+#    #+#             */
/*   Updated: 2017/08/07 19:25:16 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
/*
	char *ptr = "Hello world!";
	char *np = 0;
	int i = 5;
	unsigned int bs = sizeof(int)*8;
	int mi;

	mi = (1 << (bs-1)) + 1;
	ft_printf("%s\n", ptr);//
	ft_printf("ft_printf test\n");//
	ft_printf("%s is a null pointer\n", np);// 
	ft_printf("%d = 5\n", i);
	ft_printf("%d = - max int\n", mi);
	ft_printf("char %c = 'a'\n", 'a');
	ft_printf("hex %x = ff\n", 0xff);
	ft_printf("hex %02x = 00\n", 0); 
	ft_printf("signed %d = unsigned %u = hex %x\n", -3, -3, -3);
	ft_printf("%d %s(s)%", 0, "message");// Returns -1 because of extra % 
	ft_printf("\n");
	ft_printf("%d %s(s) with %%\n", 0, "message");
	ft_printf("justif: \"%-10s\"\n", "left");
	ft_printf("justif: \"%10s\"\n", "right");
	ft_printf(" 3: %04d zero padded\n", 3);
	ft_printf(" 3: %-4d left justif.\n", 3);
	ft_printf(" 3: %4d right justif.\n", 3);
	ft_printf("-3: %04d zero padded\n", -3);
	ft_printf("-3: %-4d left justif.\n", -3);
	ft_printf("-3: %4d right justif.\n", -3);


	int n1 = 0, n2 = 0;

	if ((n1 = ft_printf("-3: %4d right justif.\n", -3)) != (n2 = printf("-3: %4d right justif.\n", -3)))
		ft_printf("Error: mine: %d actual: %d\n", n1, n2);
	
	ft_printf("*Kashim a �  histoires à raconterIl fait au moins �\n�\nc\n\n\nly es%ct fantas%ctique!\n\n\n", '\0', '\0');

    int *p;
	p = &i;
    *p=5;
	int *n = NULL;
    ft_printf("%p\n", p);
	printf("%p\n", p);
	ft_printf("%p\n", n);
	printf("%p\n", n);

	if ((n1 = ft_printf("%p\n", p)) != (n2 = printf("%p\n", p)))
		ft_printf("Error: mine: %d actual: %d\n", n1, n2);


	ft_printf("%-15.4e hi\n", 1200.0);
	ft_printf("%-15.4E hi\n\n", 1200.0);

	ft_printf("%-15.4f hi\n", 1200.0);
	ft_printf("%-15.4F hi\n\n", 1200.0);

	ft_printf("%-15.4g hi\n", 1200.0);
	ft_printf("%-15.4G hi\n\n", 1200.0);

	ft_printf("%-15.4a hi\n", 1200.0);
	ft_printf("%-15.4A hi\n\n", 1200.0);
*/
	
	ft_printf("%S\n", L"(◕‿‿◕｡)");
	ft_printf("%E\n", 1001.0);
	printf("%E\n", 1001.0);


	return 0;
}
