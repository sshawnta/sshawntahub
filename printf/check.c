/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <sshawnta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 13:18:52 by sshawnta          #+#    #+#             */
/*   Updated: 2019/05/25 13:22:06 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline extern int			is_conversion(const char c)
{
	return (ft_strchr("dDioOuUxXeEfFgGaAcCsSpn%", c) != NULL);
}

int							is_it_modifier(const char c)
{
	return (ft_strchr("hljz", c) != NULL);
}

inline extern int			is_it_flag(const char c)
{
	return (ft_strchr("#0-+' ", c) != NULL);
}

inline extern int			is_precision(const char c)
{
	return (ft_strchr("$*.1234567890", c) != NULL);
}

int							is_valid(const char c)
{
	return (is_conversion(c) || is_it_modifier(c) || is_it_flag(c)
			|| is_precision(c));
}
