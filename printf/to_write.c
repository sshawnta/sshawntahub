#include "ft_printf.h"

int pars_struct(t_pf_param *param)
{   
    if (param->conversion == 'd' || param->conversion == 'D' || param->conversion == 'i'   )
        esli_d(param);
    if (param->conversion == 'c' || param->conversion == 'C')
        esli_c(param);
    if (param->conversion == 's' || param->conversion == 'S')
        esli_s(param);
    return (0);
}


int esli_c(t_pf_param *param)
{
    param->str.str = ft_strdup(&param->value.cha);
    if (param->value.cha == 0)
    {
        param->str.length = 1;
        param->str.str = "\0";
    }
    else  
        param->str.length = ft_strlen(param->str.str);
    if (param->width > 0)
        go_width(param);
    param->str.length = ft_strlen(param->str.str);
    ft_putstr(param->str.str);
    return (0);
}

int esli_s(t_pf_param *param)
{
    return (0);
}


int esli_d(t_pf_param *param)
{
    int i;

    i = 0;
    param->str.str = ft_itoa(param->value.i);
    param->str.length = ft_strlen(param->str.str);
    if (param->value.i < 0)
        param->str.length -= 1;    
    if (param->precision >= param->width)// && param->precision > param->str.length)
        go_precision(param);
    if (param->width > param->precision && param->width >= param->str.length)
        go_width(param);
    go_flags(param);
    while(param->str.str[i] != '\0')
        i++;
    param->str.str[i] = '\0';
    ft_putstr(param->str.str);
    param->str.length = ft_strlen(param->str.str);
   // ft_putstr(ft_itoa(param->str.length));

    return (0);
}

int go_flags(t_pf_param *param)
{
    char *str;
    int i;

    str = ft_strdup(param->str.str);
    i = ft_strlen(str);
    if (param->flags.plus == 1)
        param->flags.space = 0;
    if (param->flags.space == 1 && param->value.i >= 0 && (param->width <= param->str.length || param->precision >= param->width))
        param->str.str = ft_strjoin(" ", param->str.str);
    free(str);
    return (0);
}

int go_precision(t_pf_param *param)
{
    char *str;
    int i;
    int j;
    char tmp;

    j = 0;
    i = 0;
    str = malloc(sizeof(char *) * param->precision);
    if(param->precision > param->str.length)
    {
        while (i < param->precision - param->str.length)
            str[i++] = '0';
    }
    str = ft_strjoin(str, param->str.str);
    if (param->value.i < 0)
    {
        i = 0;
        j = 0;
        while (str[i] != '-')
            i++;
        tmp = str[j];
        str[j] = str[i];
        str[i] = tmp;
    }
    i = 0;
    if (param->value.i > 0 && param->flags.plus == 1)
    {
        str = ft_strjoin("+", str);
    }
    param->str.str = ft_strdup(str);
    free(str);
    return (0);
}

int go_width(t_pf_param *param)
{
    char *str;
    int i;
    char zero;

    i = 0;
    str = malloc(sizeof(char *) * param->width);
    if (param->flags.zero == 0)
        zero = ' ';
    else 
        zero = '0';
    if (param->precision > param->str.length)
    {
        if (param->value.i < 0)
            param->width -= 1;
        else if (param->value.i >= 0 && param->flags.plus == 1)
            param->width -= 1;    
        if (param->precision > 0)
        {
            while (i < param->width - param->precision)
            str[i++] = zero;
        }
        go_precision(param);
    }
    else
    {
        if (param->flags.plus == 1 || param->value.i < 0)
            param->width -= 1;
        while (i < param->width - param->str.length)
            str[i++] = zero;
        if (param->flags.plus == 1 && param->value.i >= 0)
            str = ft_strjoin(str, "+");
    }
    i = 0;
    if (param->flags.zero == 1 && param->precision != 0 && param->precision < param->width)
    {
        while (i < param->width - param->precision)
            str[i++] = ' ';
    }
    if (param->flags.minus == 0)
        str = ft_strjoin(str, param->str.str);
    else 
        str = ft_strjoin(param->str.str, str);
    param->str.str = str;
    free(str);
    return (0);
}