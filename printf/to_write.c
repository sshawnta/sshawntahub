#include "ft_printf.h"

int				pars_struct(t_pf_param *param)
{
	if (param->conversion == 'd' || param->conversion == 'D' || param->conversion == 'i')
		esli_d(param);
	if (param->conversion == 'c' || param->conversion == 'C')
		esli_c(param);
	if (param->conversion == 's' || param->conversion == 'S')
		esli_s(param);
	if (param->conversion == 'o' || param->conversion == 'O')
		esli_o(param);
	if (param->conversion == 'u' || param->conversion == 'U')
		esli_u(param);
	if (param->conversion == 'x' || param->conversion == 'X')
		esli_x(param);
	if (param->conversion == '%')
		esli_proc(param);
	return (0);
}

int					esli_proc(t_pf_param *param)
{
	if (param->flags.minus == 1)
		param->flags.zero = 0;
	free(param->str.str);
	param->str.str = ft_strdup("%");
	param->str.length = ft_strlen(param->str.str);
	if (param->width > 0)
		go_width(param);
	param->str.length = ft_strlen(param->str.str);
	ft_putstr(param->str.str);
	return (0);
}

int					esli_x(t_pf_param *param)
{
	if (param->value.u == 0)
		param->str.str = "0";
	if (param->flag_pre == 1 && param->value.u == 0)
		param->str.str = " ";
	else
		param->str.str = itoa_base(param->value.u, 16, param);
	if (param->flags.minus == 1)
		param->flags.zero = 0;
	if (param->value.u > 0 && param->flags.zero == 0)
	{
		if (param->flags.slesh == 1 && param->conversion == 'x')
			param->str.str = ft_strjoin("0x", param->str.str);
		else if (param->flags.slesh == 1 && param->conversion == 'X')
			param->str.str = ft_strjoin("0X", param->str.str);
	}
	esli_d(param);
	return (0);
}

int					esli_o(t_pf_param *param)
{
	param->str.str = itoa_base(param->value.u, 8, param);
	if (param->flag_pre == 1 && param->precision == 0)
		param->str.str = "";
	if (param->width > 0 && param->flag_pre == 1 && param->precision == 0 && param->value.u == 0)
		param->str.str = " ";
	if (param->flags.slesh == 1 && param->value.u != 0)
		param->str.str = ft_strjoin("0", param->str.str);
	if (param->flags.slesh == 1 && param->value.u == 0)
		param->flag_slesh = 1;
	param->flags.slesh = 0;
	esli_d(param);
	return (0);
}

int					esli_c(t_pf_param *param)
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
		write(1, "\0", 1);
		param->str.length = ft_strlen(param->str.str) + 1;
	}
	return (0);
}

int					esli_s(t_pf_param *param)
{
	if (param->flags.minus == 1)
		param->flags.zero = 0;
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

int					esli_u(t_pf_param *param)
{
	if (param->flags.space == 1)
		param->flags.space = 0;
	if (param->flags.plus == 1)
		param->flags.plus = 0;
	param->str.str = ftt_itoa(param->value.u);
	esli_d(param);
	return (0);
}

inline static void	ft_itoa_is_negative(intmax_t *n, intmax_t *negative)
{
	if (*n < 0)
	{
		*n = *n * (-1);
		*negative = 1;
	}
}

char				*ftt_itoa(intmax_t n)
{
	intmax_t			tmp_n;
	intmax_t			len;
	intmax_t			negative;
	char				*str;

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

int					esli_d(t_pf_param *param)
{
	int				i;
	char			tmp;

	i = 0;
	if (param->conversion == 'd' || param->conversion == 'D' || param->conversion == 'i')
		param->str.str = ftt_itoa(param->value.i);
	param->str.length = ft_strlen(param->str.str);
	if (param->precision > 0)
		param->flags.zero = 0;
	if (param->value.i < 0)
		param->str.length -= 1;
	if (param->flags.minus == 1)
		param->flags.zero = 0;
	if (param->conversion != 'o' || param->conversion == 'O')
	{
		if (param->flag_pre == 1 && param->precision == 0 && param->value.i == 0 && param->value.u == 0)
			param->str.str = "";
		if (param->width > 0 && param->flag_pre == 1 && param->precision == 0 && param->value.u == 0 && param->value.i == 0)
			param->str.str = " ";
	}
	else
	{
		if (param->flag_slesh == 1 && param->value.u == 0)
			param->str.str = "0";
	}
	if (param->precision >= param->width)
		go_precision(param);
	if (param->width > param->precision && param->width >= param->str.length)
		go_width(param);
	go_flags(param);
	if (param->conversion == 'x' && param->value.u > 0 && param->flags.zero == 1 && param->width >= param->str.length)
	{
		if (param->flags.slesh == 1 && param->conversion == 'x')
		{
			while (param->str.str[i] != '0')
				i++;
			param->str.str[i + 1] = 'x';
		}
		else if (param->flags.slesh == 1 && param->conversion == 'X')
		{
			while (param->str.str[i] != '0')
				i++;
			param->str.str[i + 1] = 'X';
		}
	}
	if (param->value.i < 0 && param->flags.zero == 1)
	{
		while (param->str.str[i] != '-')
			i++;
		tmp = param->str.str[i];
		param->str.str[i] = param->str.str[0];
		param->str.str[0] = tmp;
	}
	i = 0;
	while (param->str.str[i] != '\0')
		i++;
	param->str.str[i] = '\0';
	i = 0;
	ft_putstr(param->str.str);
	param->str.length = ft_strlen(param->str.str);
	return (0);
}

int						go_precision_s(t_pf_param *param)
{
	char			*str;
	size_t			i;

	i = 0;
	str = ft_memalloc(sizeof(char *) * param->precision);
	while (i < param->precision)
	{
		str[i] = param->str.str[i];
		i++;
	}
	ft_strcpy(param->str.str, str);
	param->str.length = param->precision;
	free(str);
	return (0);
}

int					go_flags(t_pf_param *param)
{
	char			*str;
	size_t			i;

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

int					go_precision(t_pf_param *param)
{
	char			*str;
	size_t			i;
	int				j;
	char			tmp;
	char			zero;
	char			*temp;
	j = 0;
	i = 0;
	str = ft_memalloc(sizeof(char *) * param->precision);
	if (param->conversion == 's' || param->conversion == 'S')
		zero = ' ';
	else
		zero = '0';
	if (param->precision > param->str.length)// && param->str.length != 0)
	{
		while (i < param->precision - param->str.length)
			str[i++] = zero;
	}
	temp = str;
	str = ft_strjoin(str, param->str.str);
	free(temp);
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
		temp = str;
		str = ft_strjoin("+", str);
		free(temp);
	}
	temp = str;
//	if (param->str.str != NULL)//1 убирает			тьму		но 			тесты
//		free(param->str.str);//2			хуеву		памяти		ломает
//	free(param->str.str);
//	param->str.str = ft_memalloc(strlen(str)+1);
//	ft_strcpy(param->str.str, str);
	param->str.str = str;
//	if (temp != NULL)
//		free(temp);
	//free(str);
	return (0);
}

int				go_width(t_pf_param *param)
{
	char			*str;
	size_t			i;
	char			zero;
	char			*temp;
	char			*temp2;

	i = 0;
	str = ft_memalloc(sizeof(char *) * param->width);
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
		if (param->precision > 0 && (param->precision <= param->width))
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
		if (param->width >= param->str.length)
		{while (i < param->width - param->str.length)
			str[i++] = zero;
		}
		temp = str;
		if (param->flags.plus == 1 && param->value.i >= 0)
		{	
			str = ft_strjoin("+", str);
			free(temp);
		}
	}
	i = 0;
	if (param->flags.zero == 1 && param->precision != 0 && param->precision < param->width)
	{
		while (i < param->width - param->precision)
			str[i++] = ' ';
	}
	temp = str;
	temp2 = param->str.str;
	if (param->flags.minus == 0)
		str = ft_strjoin(str, param->str.str);
	else
		str = ft_strjoin(param->str.str, str);
	free((char*)str);
	param->str.str = ft_strdup(str);
	free(temp);
	//free((char *)temp2);
	return (0);
}

inline static int	conv_ex(uintmax_t nb, t_pf_param *param)
{
	if (nb >= 10)
	{
		if (param->conversion == 'X')
			return (nb - 10 + 'A');
		else
			return (nb - 10 + 'a');
	}
	else
		return (nb + '0');
}

char				*itoa_base(uintmax_t value, uintmax_t base, t_pf_param *param)
{
	int					i;
	char				*str;
	uintmax_t			tmp;

	i = 0;
	tmp = value;
	while (tmp >= base)
	{
		tmp = tmp / base;
		i++;
	}
	if (!(str = (char *)ft_memalloc(sizeof(char) * (i + 1))))
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
