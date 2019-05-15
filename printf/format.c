/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <sshawnta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:16:32 by sshawnta          #+#    #+#             */
/*   Updated: 2019/05/15 19:02:15 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_parse_format(const char *str, va_list list)
{
    int i;
    char *a;
    int  c;
    t_pf_param *param;
    t_string *string;
    char *str1;
    int j;

    //str1 = malloc(sizeof(char *) * 100);
    param = (t_pf_param *)malloc(sizeof(t_pf_param));
    string = (t_string *)malloc(sizeof(t_string));
    a = malloc(sizeof(char *) * 3);
    i = 0;
    j = 0;
    while (str[i] != '\0')
   {
        if (str[i] == '%')
        {
            str1 = malloc(sizeof(char *) * 100);
            while (str[i] != '\0')
            {
                if (str[i] == 'c' || str[i] == 's' || str[i] == 'p' || str[i] == 'd'
                    || str[i] == 'i' || str[i] == 'o' || str[i] == 'x' || str[i] == 'f'
                    || str[i] == 'X')
                {
                    str1[j] = str[i];
                    i++;
                    string->str = ft_strdup(str1);
                    string->length = j;
                    j++;
                    if(is_it_varificated(string))
                        zap_struct(string, param, list);
                    else
                        i -= j - 1;
                    break;
                }
                str1[j] = str[i];
                i++;
                j++;
            }
            //
            j = 0;
        }
        write(1, &str[i], 1);
        i++;
   }
    return (0);
}
