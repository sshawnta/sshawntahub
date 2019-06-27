/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:03:56 by sshawnta          #+#    #+#             */
/*   Updated: 2019/05/28 16:03:58 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, char c)
{
	const unsigned char	*ustr;
	unsigned char		uc;
	size_t				i;

	ustr = (CUC*)str;
	uc = (UC)c;
	i = ft_strlen((char*)ustr);
	while (i > 0)
	{
		if (ustr[i] == uc)
			return ((char*)(&(ustr[i])));
		--i;
	}
	if (ustr[i] == uc)
		return ((char*)(&(ustr[i])));
	return (NULL);
}
