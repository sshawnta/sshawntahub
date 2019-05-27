/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <sshawnta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 13:28:53 by sshawnta          #+#    #+#             */
/*   Updated: 2019/05/27 18:03:45 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				is_it_varificated(t_string *string)
{
	int				i;
	int				j;
	char			*str1;

	str1 = string->str;
	j = 0;
	i = 0;
	if (string->length <= 0)
		return (0);
	while (*(string->str) != '\0')
	{
		if (is_valid(*(string->str++)))
			j = 1;
		else
			j = 0;
		if (j == 0)
		{
			string->str = str1;
			return (0);
		}
	}
	string->str = str1;
	return (1);
}

int		zap_struct(t_string *string, t_pf_param *param, va_list list)
{
	char			*str1;
	t_flags			*flags;
	t_value			*value;

	value = (t_value *)ft_memalloc(sizeof(t_value));
	flags = (t_flags *)ft_memalloc(sizeof(t_flags));
	str1 = string->str;
	param->str = *string;
	flags->minus = 0;
	flags->slesh = 0;
	flags->space = 0;
	flags->plus = 0;
	flags->zero = 0;
	param->modifier = NONE;
	param->width = is_width(string);
	is_flag(string, flags);
	param->flags = *flags;
	string->str = str1;
	if ((is_modifire(string->str, param)) == 0)
		param->error = 1;
	param->precision = ft_precision(string, param);
	param->conversion = ft_conversion(string);
	ft_value(param, value, list);
	param->value = *value;
	pars_struct(param);
	free(string->str);
	string->str = NULL;
	string->length = 0;
	free(string);
	string = NULL;
	//free(value->str);
	//value->str = NULL;
	free(value);
	value = NULL;
	if (flags != NULL)
	{
		free(flags);
		//param->flags = NULL;
	}
	free(param);
	param = NULL;
	return (0);
}

int		ft_value(t_pf_param *param, t_value *value, va_list list)
{
	intmax_t n;
	if (param->conversion == 'c' || param->conversion == 'C')
		value->cha = va_arg(list, long);
	if (param->conversion == 's' || param->conversion == 'S')
		value->str = va_arg(list, char *);
	if (param->conversion == 'd' || param->conversion == 'D' || param->conversion == 'i')
	{
		if (param->modifier == LL)
			value->i = va_arg(list, long long int);
		else if (param->modifier == L)
			value->i = va_arg(list, long int);
		else if (param->modifier == HH)
			value->i = (signed char)va_arg(list, long);
		else if (param->modifier == H)
		{
			n = va_arg(list, long);
			n = (short)n;
			value->i = n;
		}
		else if (param->modifier == J)
			value->i = va_arg(list, uintmax_t);
		else if (param->modifier == Z)
		{
			value->i = va_arg(list, long);
			value->i =(size_t)value->i;
		}
		else
			value->i = va_arg(list, int);
	}
	if (param->conversion == '%')
		value->cha = '%';
	if (param->conversion == 'U' || param->conversion == 'u' || param->conversion == 'o' || param->conversion == 'O' || param->conversion == 'x' || param->conversion == 'X')
	{
		if (param->conversion == 'U')
			value->u = va_arg(list, unsigned long int);
		else if (param->modifier == LL)
			value->u = va_arg(list, unsigned long long int);
		else if (param->modifier == L || param->conversion == 'O')
			value->u = va_arg(list, unsigned long int);
		else if (param->modifier == HH)
			value->u = (unsigned char)va_arg(list, long);
		else if (param->modifier == H)
			value->u = (unsigned short int)va_arg(list, long);
		else if (param->modifier == J)
			value->u = va_arg(list, uintmax_t);
		else
			value->u = va_arg(list, unsigned int);
	}
	return (0);
}

char	ft_conversion(t_string *string)
{
	char			*str1;
	int				i;
	char			c;
	i = 0;
	str1 = ft_strdup(string->str);
	while (str1[i] != '\0')
		i++;
	i -= 1;
	c = str1[i];
	free((void *)str1);
	return (c);
}

int		ft_precision(t_string *string, t_pf_param *param)
{
	char			*str1;
	int				i;
	int				res;
	char			*str2;

	i = 0;
	res = 0;
	str1 = ft_strdup(string->str);
	str2 = ft_memalloc(sizeof(str1));
	while (str1[i] != '\0')
	{
		if (str1[i] == '.')
		{
			i++;
			while (str1[i] >= '0' && str1[i] <= '9')
			{
				str2[res] = str1[i];
				res++;
				i++;
			}
			param->flag_pre = 1;
		}
		i++;
	}
	res = ft_atoi(str2);
	free(str1);
	free(str2);
	return (res);
}

unsigned int	is_width(t_string *string)
{
	char			*str1;
	int				i;
	unsigned int	res;
	char			*str2;

	i = 0;
	res = 0;
	str1 = ft_strdup(string->str);
	str2 = ft_memalloc(sizeof(str1));
	while (str1[i] != '\0')
	{
		if (str1[i] >= '0' && str1[i] <= '9')
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

int		is_flag(t_string *string, t_flags *flags)
{
	char			*str1;
	int				i;

	str1 = ft_strdup(string->str);
	i = 0;
	while (str1[i] != '\0')
	{
		if (str1[i] == '#')
			flags->slesh = 1;
		if (str1[i] == '0' && (str1[i - 1] < '0' || str1[i - 1] > '9') && str1[i - 1] != '.')
			flags->zero = 1;
		if (str1[i] == '-')
			flags->minus = 1;
		if (str1[i] == '+')
			flags->plus = 1;
		if (str1[i] == ' ')
			flags->space = 1;
		i++;
	}
	free(str1);
	return (0);
}

int		is_modifire(char *str, t_pf_param *param)
{
	int				i;

	i = 0;
	if (param->modifier > NONE)
		return (0);
	while (str[i] != '\0')
	{
		if (is_it_modifier(str[i + 3]))
		{
			if (str[i] == 'l' && str[i + 1] == 'l')
			{
				param->modifier = LL;
				break ;
			}
			else if (str[i] == 'l')
			{
				param->modifier = L;
				break ;
			}
			else if (str[i] == 'h' && str[i + 1] == 'h')
			{
				param->modifier = HH;
				break ;
			}
			else if (str[i] == 'h')
			{
				param->modifier = H;
				break ;
			}
			else if (str[i] == 'z')
			{
				param->modifier = Z;
				break ;
			}
			else if (str[i] == 'j')
			{
				param->modifier = J;
				break ;
			}
		}
		i++;
	}
	return (1);
}
