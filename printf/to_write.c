#include "ft_printf.h"

int pars_struct(t_pf_param *param)
{   
    if (param->conversion == 'd' || param->conversion == 'D' || param->conversion == 'i'   )
        esli_d(param);
    if (param->conversion == 'c' || param->conversion == 'C')
        esli_c(param);
    if (param->conversion == 's' || param->conversion == 'S')
        esli_s(param);
    if (param->conversion == 'o')
        esli_o(param);
    if (param->conversion == 'u')
        esli_u(param);
    if (param->conversion == 'x' || param->conversion == 'X')
        esli_x(param);

    return (0);
}
int esli_x(t_pf_param *param)
{
    param->str.str = itoa_base(param->value.u, 16, param);
    if (param->flags.slesh == 1 && param->conversion == 'x')
        param->str.str = ft_strjoin("0x", param->str.str);
    else if (param->flags.slesh == 1 && param->conversion == 'X')
        param->str.str = ft_strjoin("0X", param->str.str);
    esli_d(param);
    return (0);
}

int esli_o(t_pf_param *param)
{
    param->str.str = itoa_base(param->value.u, 8, param);
    //param->value.i = ft_atoi(param->str.str);
    esli_d(param);
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
    if (param->value.cha == 0)
    {
        write(1,"\0", 1);        
        param->str.length = 1;
    }
    return (0);
}

int esli_s(t_pf_param *param)
{
    if (param->value.str == NULL)
        param->str.str = ft_strdup("(null)");
    else    
        param->str.str = ft_strdup(param->value.str);
    param->str.length = ft_strlen(param->str.str);
    if (param->precision > 0 && param->precision < param->str.length)
        go_precision_s(param);
    if (param->width > 0)
        go_width(param);
    param->str.length = ft_strlen(param->str.str);
    ft_putstr(param->str.str);
    return (0);
}

int esli_u(t_pf_param *param)
{
    //ft_putstr(ft_itoa(param->value.u));
    //param->value.i = param->value.u;
    //param->str.str = ftt_itoa_base(param->value.u, 10, param);
    if (param->flags.space == 1)
        param->flags.space = 0;
    param->str.str = ftt_itoa(param->value.u);
    //ft_putstr(param->str.str);
    esli_d(param);
    return (0);
}

static void	ft_itoa_is_negative(intmax_t *n, intmax_t *negative)
{
	if (*n < 0)
	{
		*n = *n * (-1);
		*negative = 1;
	}
}

char		*ftt_itoa(intmax_t n)
{
	intmax_t		tmp_n;
	intmax_t		len;
	intmax_t		negative;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tmp_n = n;
	len = 2;
	negative = 0;
	ft_itoa_is_negative(&n, &negative);
	while (tmp_n /= 10)
		len++;
	len = len + negative;
	if (!(str = (char*)malloc(len)))
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (negative)
		str[0] = '-';
	return (str);
}
int esli_d(t_pf_param *param)
{
    int i;

    i = 0;
    if(param->conversion == 'd' || param->conversion == 'D')
        param->str.str = ftt_itoa(param->value.i);
    param->str.length = ft_strlen(param->str.str);
    if (param->precision > 0)
        param->flags.zero = 0;
    if (param->value.i < 0)
        param->str.length -= 1;
    if (param->flags.minus == 1)
        param->flags.zero = 0;    
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

int go_precision_s(t_pf_param *param)
{
    char *str;
    int i;

    i = 0;
    str = malloc(sizeof(char *) * param->precision);
    while (i < param->precision)
    {
        str[i] = param->str.str[i];
        i++;
    }
    //ft_putstr(str);
    ft_strcpy(param->str.str, str);
    param->str.length = param->precision;
    free(str);
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
    if (param->flags.slesh == 1 && param->conversion == 'o')
        param->str.str = ft_strjoin("0", param->str.str);
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
    if (param->value.i >= 0 && param->flags.plus == 1)
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
            str = ft_strjoin("+", str); // менял местами аргументы  
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

static int		conv_ex(unsigned int nb, t_pf_param *param)
{
	if (nb >= 10)
    {
        if(param->conversion == 'X')
		    return (nb - 10 + 'A');
        else
            return (nb - 10 + 'a');
        
    }
    else
		return (nb + '0');
}

char	*itoa_base(unsigned int value, unsigned int base, t_pf_param *param)
{
	int					i;
	char				*str;
	unsigned int				tmp;
	
	i = 0;
	tmp = value;
	while (tmp >= base)
	{
		tmp = tmp / base;
		i++;
	}	
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i + 1] = '\0';
	while (i >= 0)
	{
		tmp = value % base;
		str[i] = conv_ex(tmp, param);
		value /= base;
		i--;
	}
	return (str);
}