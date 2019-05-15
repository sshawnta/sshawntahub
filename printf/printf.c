/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <sshawnta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:12:43 by sshawnta          #+#    #+#             */
/*   Updated: 2019/05/15 19:02:17 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	va_list list;
	int result;

	va_start(list, format);
	//printf(format, list);
	result = ft_parse_format(format, list);
	va_end(list);
	return (result);
}
