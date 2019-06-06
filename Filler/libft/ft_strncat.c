/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:10:38 by sshawnta          #+#    #+#             */
/*   Updated: 2019/04/06 13:22:53 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *string1, const char *string2, size_t count)
{
	size_t i;
	size_t string1_size;

	i = 0;
	string1_size = 0;
	while (string1[string1_size])
		string1_size++;
	while (i < count && string2[i])
	{
		string1[string1_size] = string2[i];
		i++;
		string1_size++;
	}
	string1[string1_size] = '\0';
	return (string1);
}
