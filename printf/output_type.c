#include "ft_printf.h"

/*int detect_types(const char *str, va_list list, const char a)
{

}

int types_c(const char *str, va_list list)
{


}

int types_d(const char *str, va_list list)
{

}

int types_s(const char *str, va_list list)
{

}

int types_proc(const char *str, va_list list)
{

}*/

int is_modifire(const char *a, t_pf_param *param)
{
    char *check;
    char *hh;
    char *ll;

    hh = "hh";
    ll = "ll";
    check = "hlL";
    if(!(ft_strcmp(a, hh)))
    {
        param->modifier = HH;
        printf("param %d ", param->modifier);
        return (1);
    }
    else if (!(ft_strcmp(a, ll)))
    {
        param->modifier = LL;
        printf("param %d ", param->modifier);
        return(1);
    }
    else if (ft_strchr(check, *a))
    {
        if (*a == 'h')
        {
            param->modifier = H;
            printf("param %d ", param->modifier);
        }
        else if (*a == 'l')
        {
            param->modifier = L;
            printf("param %d ", param->modifier);
        }
        else if (*a == 'L')
        {
           param->modifier = L;
           printf("param %d ", param->modifier);
        }
        return (1);
    }
    param->modifier = NONE;
    printf("param %d ", param->modifier);
    return(0);
}