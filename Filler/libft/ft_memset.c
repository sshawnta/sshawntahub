/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 15:36:58 by sshawnta          #+#    #+#             */
/*   Updated: 2019/04/05 10:24:25 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *destination, int c, size_t n)
{
	unsigned char *cur;

	if (n == 0)
		return (destination);
	cur = (unsigned char *)destination;
	while (n--)
	{
		*cur = (unsigned char)c;
		if (n)
			cur++;
	}
	return (destination);
}
