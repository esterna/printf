/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 11:53:19 by esterna           #+#    #+#             */
/*   Updated: 2017/09/05 20:30:18 by esterna          ###   ########.fr       */
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


	ft_printf("%S\n", L"(◕‿‿◕｡)");
	ft_printf("%.2a\n", 1001.0);
	printf("%.2a\n", 1001.0);

	ft_printf("%*d\n", 5, 42);
	ft_printf("%.*d\n", 5, 42);

	ft_printf("%aKashim a %a histoires à raconterIl fait au moins %a\n%a%12a%a%a%a\n%%a %7a == |%a|\n%%a 	 == |%a|\n%%a Lydie == |%a|\n%%a 42.42 == |%a|\n%AKashim a %A histoires à raconterIl fait au moins %A\n%A%12A%A%A%A%%A %A == |%A|\n%%A 	 == |%A|\n%%A Lydie == |%A|\n%%A 42.42 == |%A|\n%%A 42.42 == |%A|\n", 42.0, 1001.0, -8000.0, 0.0, 2147480000.0, -2147480000.0, -2.14748e+09, 2.14748e+09, 42.0, 34.0, 9.0, 503.0, 42.42, 42.0, 1001.0, -8000.0, 0.0, 2147480000.0, -2147480000.0, -2.14748e+09, 2.14748e+09, 42.0, 34.0, 9.0, 503.0, 42.42);
*/
/*	ft_printf("%a\n", 0.0);
	ft_printf("%a\n", -0x1.f4p+12);

	long double dbl = 9223372036854775807.0;
	ft_printf("%.6Le\n", dbl);

	ft_printf("%b\n", 4261611616516);
	ft_printf("%b\n", -4261611616516);

	ft_printf("%G\n", 42.42);
	printf("%G\n", 42.42);

	ft_printf("%.0G\n", 42.42);
	printf("%.0G\n", 42.42);

	ft_printf("{red}Hi There!{eoc}\n");
	ft_printf("{cyan}%d{eoc} {magenta}%O{eoc}\n", 42, 42);

	ft_printf("%g\n", 2.54309870874520948209);
	ft_printf("%g\n", 0.905239);
	ft_printf("%g\n", 0.0001);
	ft_printf("%g\n", -0.00000000000000000069948213887727211); 
	ft_printf("%g\n", -0.0000000000000099999999999999999);*/ 

	ft_printf("%e\n", 9e-300);

	return 0;
}
