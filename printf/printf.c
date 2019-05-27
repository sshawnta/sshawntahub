/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <sshawnta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:12:43 by sshawnta          #+#    #+#             */
/*   Updated: 2019/05/27 18:20:46 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list			list;
	int				result;

	va_start(list, format);
	result = ft_parse_format(format, list);
	va_end(list);
	//printf("%d\n", result);
	return (result);
}
