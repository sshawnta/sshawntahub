/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <sshawnta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:16:32 by sshawnta          #+#    #+#             */
/*   Updated: 2019/05/14 15:02:15 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_parse_format(const char *str, va_list list)
{
    int i;
    char *a;
    int  c;
    t_pf_param *param;
    
    param = (t_pf_param *)malloc(sizeof(t_pf_param));
    a = malloc(sizeof(char *) * 3);
    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '%')
        {
            if (str[++i] != 'c' && str[i] != 's' && str[i] != 'p' && str[i] != 'd'
                && str[i] != 'i' && str[i] != 'o' && str[i] != 'u' && str[i] != 'c'
                && str[i] != 'X' && str[i] != 'h'
                && str[i] != 'L' && str[i] != '%' && str[i] != '#' && str[i] != '0'
                && str[i] != '-' && str[i] != '+' && str[i] != ' ' && str[i] != '.')
            {
                write(1, &str[i], 1);
            }
            if (str[i] == 'h' && str[i + 1] == 'h')
            {
                a[0] = str[i];
                a[1] = str[i + 1];
                if (is_modifire(a, param))
                {
                    printf("D ");
                    i += 2;
                }
            }
            else if (str[i] == 'l' && str[i + 1] == 'l')
            {
                a[0] = str[i];
                a[1] = str[i + 1];
                if (is_modifire(a, param))
                    printf("D ");
            }     
            else if (is_modifire(&str[i], param))
                printf("D ");
            else 
                printf("N ");
            
            /*if (str[i] == 'c')
            {   
                a = va_arg(list, char *);
                write(1, &a, 1);
            }
            if (str[i] == 'd')
            {
                c = va_arg(list, int);
                ft_putnbr(c); 
            }
            if (str[i] == 's')
            {
                a = va_arg(list, char *);
                ft_putstr(a);
            }
            if (str[i] == '%')
            {
                write(1,"%",1);   
            }
            i++;*/
        }
        if (str[i] != '\0')
            write(1, &str[i],1);
        else
            break ;
        i++;
    }
    return (0);
}
