/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:14:43 by twight            #+#    #+#             */
/*   Updated: 2019/04/05 15:44:49 by twight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t s1_size;

	i = 0;
	s1_size = 0;
	while (s1[s1_size])
		s1_size++;
	while (i < n && s2[i])
	{
		s1[s1_size] = s2[i];
		i++;
		s1_size++;
	}
	s1[s1_size] = '\0';
	return (s1);
}
