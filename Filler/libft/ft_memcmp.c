/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:06:18 by sshawnta          #+#    #+#             */
/*   Updated: 2019/04/05 16:32:15 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	int				i;

	if (!buf1 && !buf2 && !count)
		return (0);
	i = 0;
	ptr1 = (unsigned char*)buf1;
	ptr2 = (unsigned char*)buf2;
	while (count--)
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
