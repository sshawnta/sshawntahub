/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <sshawnta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:11:21 by sshawnta          #+#    #+#             */
/*   Updated: 2019/05/27 20:33:36 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*int main()
{
	//ft_printf("Bu %#-h15.2d eshe bukva %-4c cifra %s eshe cifra %d odin\n", d1, i, s, d1);
	//ft_printf("%#-d %d ", d1, d);
/*
	
	ft_printf("test0 %12.15d %+14.13d f\n", d1, d);
	printf("test0 %12.15d %+14.13d p\n", d1, d);
	ft_printf("test1 %+10.15d f\n", d1);
	printf("test1 %+10.15d p\n", d1);
	ft_printf("test2 % 10.15d f\n", d1);
	printf("test2 % 10.15d p\n", d1);
	ft_printf("test3 %10.15d f\n", d1);
	printf("test3 %10.15d p\n", d1);
	ft_printf("test4 %10.10d f\n", d1);
	printf("test4 %10.10d p\n", d1);
	ft_printf("test5 %+15.10d f\n", d1);
	printf("test5 %+15.10d p\n", d1);
	ft_printf("test6 % 15.10d f\n", d1);
	printf("test6 % 15.10d p\n", d1);
	ft_printf("test7 %15.10d f\n", d1);
	printf("test7 %15.10d p\n", d1);
	ft_printf("test8 %.10d f\n", d1);
	printf("test8 %.10d p\n", d1);
	ft_printf("test9 %-15d f\n", d1);
	printf("test9 %-15d p\n", d1);
	ft_printf("test 0 %012d f\n", d1);
	printf("test 0 %012d p\n", d1);*/
	
	//long long int lll = -9223372036854775808;
	//ft_printf("test");
	//printf("test");
	//ft_printf("%-5%\n");
	//printf("%-5%");
	//ft_printf("%0+5d\n", 42);
	//printf("%0+5d", 42);
	
	
	//ft_printf("%.0d",42);
	//printf("%20.15d %+14.13d\n", d1, d);
	//printf("Bukva %c eshe bukva %c cifra %d eshe cifra %d odin \n", i, s, d, d1, str1, str2, poi1, poi2);
	//tt_printf("adres1 %p adres2 %% %p\n", poi1, poi2);
	//printf("adres1 %p adres2 %% %p\n", poi1, poi2);
	//ft_printf("pv %#c d %-c %c f %c\n",i,s,i,s);
/*	printf("or933:%3.3d\n", -12345678); //211
   ft_printf("ft933:%3.3d\n", -12345678); //211


   printf("or993:%9.3d\n", -12345678); //221
   ft_printf("ft993:%9.3d\n", -12345678);

   ft_printf("ft963:%6.3d\n", -12345678);
   printf("or963:%6.3d\n", -12345678); //321

   ft_printf("ft936:%3.6d\n", -12345678);
   printf("or936:%3.6d\n", -12345678); //312

   ft_printf("ft333:%3.3d\n", -12); //111
   printf("or333:%3.3d\n", -12); //111


   ft_printf("ft393:%9.3d\n", -12); //121 X
   printf("or393:%9.3d\n", -12); //121./a	

   ft_printf("ft939:%3.9d\n", -12345678);
   printf("or939:%3.9d\n", -12345678); //212

   ft_printf("ft399:%9.9d\n", -12); //122
   printf("or399:%9.9d\n", -12); //122

   ft_printf("ft339:%3.9d\n", -12); //112
   printf("or339:%3.9d\n", -12); //112

   ft_printf("ft639:%3.9d\n", -12345); //213
   printf("or639:%3.9d\n", -12345); //213

   ft_printf("ft369:%6.9d\n", -12); //123 X
   printf("or369:%6.9d\n", -12); //123

   ft_printf("ft396:%9.6d\n", -12); //132 X
   printf("or396:%9.6d\n", -12); //132


   ft_printf("ft693:%9.3d\n", -12345); //231
   printf("or693:%9.3d\n", -12345); //231

  
	return (0);
}*/

int				main()
{
	ft_printf("%5.2s is a string", "");
	printf("%5.2s is a string", "");
  ft_printf("\\n");
  ft_printf("%%\\n");
  ft_printf("%d\\n", 42);
  ft_printf("%d%d\\n", 42, 41);
  ft_printf("%d%d%d\\n", 42, 43, 44);
  ft_printf("%ld\\n", 2147483647);
  ft_printf("%lld\\n", 9223372036854775807);
  ft_printf("%x\\n", 505);
  ft_printf("%X\\n", 505);
  ft_printf("%20.15d\\n", 54321);
  ft_printf("%-10d\\n", 3);
  ft_printf("% d\\n", 3);
  ft_printf("%+d\\n", 3);
  ft_printf("%010d\\n", 1);
  ft_printf("%hhd\\n", 0);
  ft_printf("%jd\\n", 9223372036854775807);
  ft_printf("%zd\\n", 4294967295);
  ft_printf("%\\n");
  ft_printf("%U\\n", 4294967295);
  ft_printf("%u\\n", 4294967295);
  ft_printf("%o\\n", 40);
  ft_printf("%%#08x\\n", 42);
  ft_printf("%x\\n", 1000);
  ft_printf("%#X\\n", 1000);
  ft_printf("%s\\n", NULL);
  ft_printf("%S\\n", L"ݗݜशব");
  ft_printf("%s%s\\n", "test", "test");
  ft_printf("%s%s%s\\n", "test", "test", "test");
  ft_printf("%C\\n", 15000);
  return (0);
}