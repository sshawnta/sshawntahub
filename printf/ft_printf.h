/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <sshawnta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:17:27 by sshawnta          #+#    #+#             */
/*   Updated: 2019/05/27 17:29:31 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <string.h>
# include "libft/libft.h"

typedef enum	e_pf_modifier
{
	NONE = 0, L = 1, H = 2, J = 3, LL = 4, HH = 5, Z = 6
}				t_pf_modifier;
typedef struct		s_flags
{
	int				slesh;
	int				minus;
	int				plus;
	int				space;
	int				zero;
}					t_flags;

typedef struct		s_string
{
	char			*str;
	size_t			length;
}					t_string;

typedef struct		s_value
{
	char			cha;
	char			*str;
	intmax_t		i;
	uintmax_t		u;
	float			f;
}					t_value;

typedef struct		s_param
{
	t_string		str;
	t_flags			flags;
	size_t			width;
	size_t			precision;
	int				flag_pre;
	t_pf_modifier	modifier;
	char			conversion;
	int				error;
	t_value			value;
	int				value_minus;
	int				flag_slesh;
}					t_pf_param;

int					ft_printf(const char *format, ...);
int					ft_parse_format(const char *str, va_list list);

int					is_modifire(char *str, t_pf_param *param);
int					is_flag(t_string *string, t_flags *flags);
int					is_it_varificated(t_string *stsring);
int					is_valid(const char c);
int					zap_struct(t_string *string, t_pf_param *param, va_list list);
unsigned int		is_width(t_string *string);
int					ft_precision(t_string *string, t_pf_param *param);
char				ft_conversion(t_string *string);
int					ft_value(t_pf_param *param, t_value *value, va_list list);

int					pars_struct(t_pf_param *param);

int					esli_d(t_pf_param *param);
int					go_precision(t_pf_param *param);
int					go_precision_s(t_pf_param *param);
int					go_width(t_pf_param *param);
int					go_flags(t_pf_param *param);

int					esli_c(t_pf_param *param);
int					esli_o(t_pf_param *param);
int					esli_u(t_pf_param *param);
int					esli_s(t_pf_param *param);
int					esli_x(t_pf_param *param);
int					esli_proc(t_pf_param *param);

int					is_it_modifier(const char c);
int			is_conversion(const char c);

char				*itoa_base(uintmax_t value, uintmax_t base, t_pf_param *param);
char				*ftt_itoa(intmax_t n);

#endif
