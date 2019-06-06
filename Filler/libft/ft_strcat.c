/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:07:53 by sshawnta          #+#    #+#             */
/*   Updated: 2019/04/04 16:08:05 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *string1, const char *string2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (string1[i] != '\0')
		i++;
	while (string2[j] != '\0')
	{
		string1[i + j] = string2[j];
		j++;
	}
	string1[i + j] = '\0';
	return (string1);
}
