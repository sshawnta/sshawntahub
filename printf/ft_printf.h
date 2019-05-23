/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <sshawnta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:17:27 by sshawnta          #+#    #+#             */
/*   Updated: 2019/05/23 19:59:52 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> //для вариативных функций
# include <limits.h> //константы лимитов
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h> //тип данных например: int_least8_t
# include <unistd.h>
# include <string.h>
# include "libft/libft.h"

typedef enum	e_pf_modifier
{
	NONE = 0, L = 1, H = 2, J = 3, LL = 4, HH = 5
}				t_pf_modifier;
typedef struct s_flags
{
	int slesh;
	int minus;
	int plus;
	int space;
	int zero;
}				t_flags;

typedef struct	s_string
{
	char	*str;
	size_t		length;
}				t_string;
typedef struct s_value
{
	char cha;
	char *str;
	//int i;
	intmax_t i;
	uintmax_t u;
	//unsigned int u;
	float f;
	//void *fi;
} t_value;

typedef struct	s_param
{
	t_string		str;
	t_flags			flags;
	unsigned int	width;
	int				precision;
	t_pf_modifier	modifier;
	char			conversion;
	int				error;
	t_value			value;
	int				value_minus;
	//void			*value;
}				t_pf_param;

int ft_printf(const char *format, ...);
int ft_parse_format(const char *str, va_list list);


int is_modifire(char *str, t_pf_param *param);
int is_flag(t_string *string, t_pf_param *param, t_flags *flags);
int is_it_varificated(t_string *stsring);
int	is_valid(const char c);
int zap_struct(t_string *string, t_pf_param *param, va_list list);
unsigned int is_width(t_string *string, t_pf_param *param);
int ft_precision(t_string *string, t_pf_param *param);
char ft_conversion(t_string *string, t_pf_param *param);
int ft_value(t_pf_param *param, t_value *value, va_list list);

int pars_struct(t_pf_param *param);

int esli_d(t_pf_param *param);
int go_precision(t_pf_param *param);
int go_precision_s(t_pf_param *param);
int go_width(t_pf_param *param);
int go_flags(t_pf_param *param);

int esli_c(t_pf_param *param);
int esli_o(t_pf_param *param);
int esli_u(t_pf_param *param);
int esli_s(t_pf_param *param);
int esli_x(t_pf_param *param);




char	*itoa_base(unsigned int value, unsigned int base, t_pf_param *param);
static int		conv_ex(unsigned int nb, t_pf_param *param);


static void	ft_itoa_is_negative(intmax_t *n, intmax_t *negative);
char		*ftt_itoa(intmax_t n);


#endif
