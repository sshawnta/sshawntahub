/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:07:13 by sshawnta          #+#    #+#             */
/*   Updated: 2019/04/04 16:07:31 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	char *dest_tmp;
	char *src_tmp;

	dest_tmp = (char*)dest;
	src_tmp = (char*)src;
	if (src_tmp == dest_tmp)
		return (dest);
	if (src_tmp < dest_tmp)
	{
		src_tmp = (char*)src + count - 1;
		dest_tmp = (char*)dest + count - 1;
		while (count--)
			*dest_tmp-- = *src_tmp--;
	}
	else
	{
		while (count--)
			*dest_tmp++ = *src_tmp++;
	}
	return (dest);
}
