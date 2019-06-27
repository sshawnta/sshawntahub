/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:00:56 by sshawnta          #+#    #+#             */
/*   Updated: 2019/05/28 16:00:58 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *mem1, const void *mem2, size_t n)
{
	const char	*str1;
	const char	*str2;

	str1 = mem1;
	str2 = mem2;
	if (n == 0 || (str1 == NULL && str2 == NULL))
		return (1);
	if (str1 == NULL || str2 == NULL)
		return (0);
	--n;
	while (n > 0 && str1[n] && str2[n])
	{
		if (str1[n] != str2[n])
			return (0);
		--n;
	}
	if (str1[n] != str2[n])
		return (0);
	return (1);
}
