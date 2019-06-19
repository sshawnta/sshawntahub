/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:01:53 by twight            #+#    #+#             */
/*   Updated: 2019/04/07 13:47:22 by twight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	int				i;

	if (!s1 && !s2 && !n)
		return (0);
	i = 0;
	ptr1 = (unsigned char*)s1;
	ptr2 = (unsigned char*)s2;
	while (n--)
	{
		if (ptr1[i] != ptr2[i])
		{
			if (ptr1[i] != ptr2[i])
				return (ptr1[i] - ptr2[i]);
		}
		i++;
	}
	return (0);
}
