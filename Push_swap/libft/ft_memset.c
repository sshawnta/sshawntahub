/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:01:34 by sshawnta          #+#    #+#             */
/*   Updated: 2019/05/28 16:01:37 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *memptr, unsigned char c, size_t len)
{
	char	*ptr;

	ptr = memptr;
	while (len > 0)
	{
		--len;
		ptr[len] = c;
	}
	return (ptr);
}
