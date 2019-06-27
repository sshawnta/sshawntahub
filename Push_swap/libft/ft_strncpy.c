/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:03:11 by sshawnta          #+#    #+#             */
/*   Updated: 2019/05/28 16:03:15 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, long n)
{
	long	i;

	i = 0;
	if (n < 0)
		n = ft_strlen(src);
	while (i < n && src[i])
	{
		dst[i] = src[i];
		++i;
	}
	while (i <= n)
	{
		dst[i] = '\0';
		++i;
	}
	return (dst);
}
