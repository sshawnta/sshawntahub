/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <sshawnta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:17:27 by sshawnta          #+#    #+#             */
/*   Updated: 2019/05/14 14:58:31 by sshawnta         ###   ########.fr       */
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
# include "libft/libft.h"

typedef enum	e_pf_modifier
{
	NONE = 0, L = 1, H = 2, J = 3, LL = 4, HH = 5
}				t_pf_modifier;

typedef struct	s_pf_param
{
	int				flags;
	unsigned int	width;
	int				precision;
	t_pf_modifier	modifier;
	char			conversion;
	int				error;
	void			*value;
}				t_pf_param;

int ft_printf(const char *format, ...);
int ft_parse_format(const char *str, va_list list);
int is_modifire(const char *a, t_pf_param *param);


#endif
