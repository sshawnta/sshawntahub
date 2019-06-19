/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:06:43 by twight            #+#    #+#             */
/*   Updated: 2019/04/09 12:52:28 by twight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest_tmp;
	char	*src_tmp;

	dest_tmp = (char*)dst;
	src_tmp = (char*)src;
	if (src_tmp == dest_tmp)
		return (dst);
	if (src_tmp < dest_tmp)
	{
		src_tmp = (char*)src + len - 1;
		dest_tmp = (char*)dst + len - 1;
		while (len--)
			*dest_tmp-- = *src_tmp--;
	}
	else
	{
		while (len--)
			*dest_tmp++ = *src_tmp++;
	}
	return (dst);
}
