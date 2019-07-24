/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <sshawnta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 12:24:12 by twight            #+#    #+#             */
/*   Updated: 2019/07/24 19:00:13 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	if (len == 0)
		return (b);
	ptr = (unsigned char*)b;
	while (len)
	{
		*ptr = (unsigned char)c;
		if (len)
			ptr++;
		len--;
	}
	return (b);
}
