/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <sshawnta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:16:32 by sshawnta          #+#    #+#             */
/*   Updated: 2019/05/22 16:42:04 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_parse_format(const char *str, va_list list)
{
    int k;
    char *a;
    int  c;
    t_pf_param *param;
    t_string *string;
    char *str1;
    int j;
    int len;
    
    len = 0;
    //str1 = malloc(sizeof(char *) * 100);
    //param = (t_pf_param *)malloc(sizeof(t_pf_param));
    //string = (t_string *)malloc(sizeof(t_string));
    a = malloc(sizeof(char *) * 3);
    k = 0;
    j = 0;
    while(str[k] != '\0')
    {
    while (str[k] != '\0')
   {
        if (str[k] == '%')
        {
            str1 = malloc(sizeof(char *) * 100);
            while (str[k] != '\0')
            {
                if (str[k] == 'c' || str[k] == 's' || str[k] == 'p' || str[k] == 'd'
                    || str[k] == 'i' || str[k] == 'o' || str[k] == 'x' || str[k] == 'f'
                    || str[k] == 'X' || str[k] == 'D')
                {
                    param = (t_pf_param *)malloc(sizeof(t_pf_param));
                    string = (t_string *)malloc(sizeof(t_string));
                    str1[j] = str[k];
                    k++;
                    string->str = ft_strdup(str1);
                    string->length = j;
                    j++;
                    if(is_it_varificated(string))
                       zap_struct(string, param, list);
                    else
                        k -= j - 1;
                    break;
                }
                str1[j] = str[k];
                k++;
                j++;
            }
            //
            j = 0;
        }
        if(str[k] == '%')
            break;
        write(1, &str[k], 1);
        if (str[k] == '\0')
            break ;
        len++;
        k++;
   }
   }
   param->str.length = ft_strlen(param->str.str);
    return (len + param->str.length);
}
