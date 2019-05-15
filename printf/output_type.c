#include "ft_printf.h"

int is_it_varificated(t_string *string)
{
    int i;
    int j;
    char *str1;

    str1 = string->str;
    j = 0;
    i = 0;
    if (string->length <= 0)
        return (0);
    while (*(string->str)!='\0')
    {    
        if (is_valid(*(string->str++)))
                j = 1;
        else 
            j = 0;
        if (j == 0)
        {
            string->str = str1;
            return(0);
        }
    }
    string->str = str1;
    return (1);
}
//
//  VALIDNOST`
//

int zap_struct(t_string *string, t_pf_param *param, va_list list)
{
    char *str1;
    t_flags *flags;
    
    flags = (t_flags *)malloc(sizeof(t_flags));
    str1 = string->str;
    flags->minus = 0;//
    flags->slesh = 0;//
    flags->space = 0;//
    flags->plus = 0;//
    flags->zero = 0; //закинуть в другую функцию
    
    /* Отдельная функц */
    while (*(string->str++) != '\0')
        is_flag(string,param, flags); 
    param->flags = *flags; // param->str = * string; присвоение структуры структуре
    string->str = str1;
    if ((is_modifire(string->str, param)) == 0)
        param->error = 1;
    param->width = is_width(string, param);
    param->precision = ft_precision(string, param);
    param->conversion = ft_conversion(string, param);
    ft_value(param, list);
    /* */
    return (0);
}

int ft_value(t_pf_param *param, va_list list)
{
    return(0);
}

char ft_conversion(t_string *string, t_pf_param *param)
{
    char *str1;
    int i;

    i = 0;
    str1 = ft_strdup(string->str);
    while(str1[i] != '\0')
        i++;
    i -= 1;
    return (str1[i]);
}

int ft_precision(t_string *string, t_pf_param *param)
{
    char *str1;
    int i;
    int res;
    char *str2;

    i = 0;
    res = 0;
    str1 = ft_strdup(string->str);
    str2 = malloc(sizeof(str1));
    while (str1[i] != '\0')
    {
        if (str1[i] == '.')
        {
            i++;
            while(str1[i] >= '0' && str1[i] <= '9')
            {
                str2[res] = str1[i];
                res++;
                i++;
            }
        }
        i++;
    }
    res = ft_atoi(str2);
    free(str1);
    free(str2);
    return (res);
}

unsigned int is_width(t_string *string, t_pf_param *param)
{
    char *str1;
    int i;
    unsigned int res;
    char *str2;

    i = 0;
    res = 0;
    str1 = ft_strdup(string->str);
    str2 = malloc(sizeof(str1));
    while (str1[i] != '\0')
    {
        if(str1[i] >= '0' && str1[i] <= '9')
        {
            str2[res] = str1[i];
            res++;
        }
        if (str1[i] == '.')
            break ;
        i++;
    }
    res = ft_atoi(str2);
    free(str1);
    free(str2);
    return (res);
}

int is_flag(t_string *string, t_pf_param *param, t_flags *flags)
{
    if(*(string->str) == '#')
        flags->slesh = 1;
    else if (*(string->str) == '0')
        flags->zero = 1;
    else if (*(string->str)== '-')
        flags->minus = 1;
    else if (*(string->str) == '+')
        flags->plus = 1;
    else if(*(string->str) == ' ')
        flags->space = 1;
    return (0);
}

int is_modifire(char *str, t_pf_param *param)
{
    int i;

    i = 0;
    if (param->modifier > NONE)
        return (0);
    while (str[i] != '\0')
    {
        if (str[i] == 'l' && str[i + 1] =='l')
            param->modifier = LL;
        if (str[i] == 'h' && str[i + 1] =='h')
            param->modifier = HH;
        if (str[i] == 'l')
            param->modifier = L;
        if (str[i] == 'h')
            param->modifier = H;
        if (str[i] == 'H')
            param->modifier = J;
        i++;
    }
    return(1);
}

