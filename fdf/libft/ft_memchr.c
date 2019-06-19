/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:51:16 by twight            #+#    #+#             */
/*   Updated: 2019/04/04 13:59:27 by twight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	ch;
	unsigned char	*ptr;

	i = 0;
	ch = (unsigned char)c;
	ptr = (unsigned char *)s;
	while (n)
	{
		if (ptr[i] == ch)
			return (ptr + i);
		i++;
		n--;
	}
	return (NULL);
}
