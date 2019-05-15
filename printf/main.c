/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <sshawnta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:11:21 by sshawnta          #+#    #+#             */
/*   Updated: 2019/05/15 19:02:17 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
	char i = 'g';
	char *s = "ffg";
	int d = 1;
	int d1 = 13;
	char *str1 = "stroka1";
	char *str2 = "stroka2";
	char *poi1 = "asd";
	int *poi2;
	
	poi2 = &d;
	ft_printf("Bu %#-h15.2c eshe bukva %-4c cifra %d eshe cifra %d odin\n", 1.423, s, d, d1, str1, str2, poi1, poi2);
	//printf("Bukva %c eshe bukva %c cifra %d eshe cifra %d odin \n", i, s, d, d1, str1, str2, poi1, poi2);
	//ft_printf("adres1 %p adres2 %% %p\n", poi1, poi2);
	//printf("adres1 %p adres2 %% %p\n", poi1, poi2);
	//ft_printf("pv %#c d %-c %c f %c\n",i,s,i,s);
	return (0);
}