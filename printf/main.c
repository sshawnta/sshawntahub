/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <sshawnta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:11:21 by sshawnta          #+#    #+#             */
/*   Updated: 2019/05/14 14:33:33 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
	char i = 'g';
	char s = 'f';
	int d = 12;
	int d1 = 13;
	char *str1 = "stroka1";
	char *str2 = "stroka2";
	char *poi1 = "asd";
	int *poi2;
	
	poi2 = &d;
	ft_printf("Bukva %hhc eshe bukva %lc cifra %lld eshe cifra %d odin %Ls dva %s adres1 %p adres2 %p\n", i, s, d, d1, str1, str2, poi1, poi2);
	printf("Bukva %c eshe bukva %c cifra %d eshe cifra %d odin %s dva %s adres1 %p adres2 %p\n", i, s, d, d1, str1, str2, poi1, poi2);
	//ft_printf("adres1 %p adres2 %% %p\n", poi1, poi2);
	//printf("adres1 %p adres2 %% %p\n", poi1, poi2);
	return (0);
}
