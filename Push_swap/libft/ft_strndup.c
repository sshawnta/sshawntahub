/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:03:23 by sshawnta          #+#    #+#             */
/*   Updated: 2019/05/28 16:03:25 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, long n)
{
	char	*dst;

	if (n < 0)
		n = ft_strlen(src);
	if (!(dst = ft_strnew((size_t)n)))
		return (NULL);
	dst = ft_strncpy(dst, src, n);
	return (dst);
}
