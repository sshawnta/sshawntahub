/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:11:09 by sshawnta          #+#    #+#             */
/*   Updated: 2019/04/06 13:21:27 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *string1, const char *string2, size_t count)
{
	size_t i;

	i = 0;
	while (string2[i] != '\0' && i < count)
	{
		string1[i] = string2[i];
		i++;
	}
	while (i < count)
	{
		string1[i] = '\0';
		i++;
	}
	return (string1);
}
