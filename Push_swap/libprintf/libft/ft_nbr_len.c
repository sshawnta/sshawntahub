/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:01:47 by sshawnta          #+#    #+#             */
/*   Updated: 2019/05/28 16:01:49 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbr_len(long long nbr, size_t base)
{
	size_t	len;

	len = 1;
	if (nbr < 0)
	{
		nbr = -nbr;
		++len;
	}
	while (nbr / base > 0)
	{
		nbr = (LL)(nbr / base);
		++len;
	}
	return (len);
}

size_t	ft_unbr_len(unsigned long long nbr, size_t base)
{
	size_t	len;

	len = 1;
	while (nbr / base > 0)
	{
		nbr = nbr / base;
		++len;
	}
	return (len);
}
