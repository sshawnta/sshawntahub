/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <sshawnta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:16:32 by sshawnta          #+#    #+#             */
/*   Updated: 2019/05/25 13:00:33 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_parse_format(const char *str, va_list list)
{
    int k;
    char *a;
    t_pf_param *param;
    t_string *string;
    char *str1;
    int j;
    int len;
    int len2;
    int h;

    
    len = 0;
    len2 = 0;
    //str1 = malloc(sizeof(char *) * 100);
    //param = (t_pf_param *)malloc(sizeof(t_pf_param));
    //string = (t_string *)malloc(sizeof(t_string));
    a = ft_memalloc(sizeof(char *) * 3);
    k = 0;
    j = 0;
    while(str[k] != '\0')
    {
    while (str[k] != '\0')
   {
        if (str[k] == '%')
        {
            h = 0;
            str1 = malloc(sizeof(char *) * 100);
            while (str[k] != '\0')
            {
                if (str[k] == '%')
                    h++;
                if (str[k] == 'c' || str[k] == 's' || str[k] == 'p' || str[k] == 'd'
                    || str[k] == 'i' || str[k] == 'o' || str[k] == 'x' || str[k] == 'f'
                    || str[k] == 'X' || str[k] == 'D' || str[k] == 'u' || str[k] == 'U' || h == 2)
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
                if (is_valid(str[k]) && str[k] != is_conversion(str[k]))
                {
                    str1[j] = str[k];
                    k++;
                    j++;
                }
                else
                {
                   // k -= j;
                    break;
                }
            }
            //
            if (param != NULL)
                len += param->str.length;

            j = 0;
        }
        if(str[k] == '%')
            break;
        if (str[k] != '\0')// && str[k] != '%')
            write(1, &str[k], 1);
        if (str[k] == '\0')
            break ;
        len2++;
        k++;
   }
   }
   //len = 0;
   if (param != NULL)
       param->str.length = ft_strlen(param->str.str);
    len = len + len2;
    return (len);
}
