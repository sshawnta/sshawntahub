/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:02:02 by sshawnta          #+#    #+#             */
/*   Updated: 2019/05/28 16:02:05 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, char c)
{
	const unsigned char	*ustr;
	unsigned char		uc;
	size_t				i;

	uc = (UC)c;
	ustr = (CUC*)str;
	i = 0;
	while (ustr[i])
	{
		if (ustr[i] == uc)
			return ((char*)(&(ustr[i])));
		++i;
	}
	if (ustr[i] == uc)
		return ((char*)(&(ustr[i])));
	return (NULL);
}

size_t	ft_strchr_i(const char *str, char c)
{
	const unsigned char	*ustr;
	unsigned char		uc;
	size_t				i;

	ustr = (CUC*)str;
	uc = (UC)c;
	i = 0;
	while (ustr[i])
	{
		if (ustr[i] == uc)
			return (i);
		++i;
	}
	return (i);
}
