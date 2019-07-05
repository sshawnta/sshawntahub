/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:02:39 by sshawnta          #+#    #+#             */
/*   Updated: 2019/05/28 16:02:42 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *src1, const char *src2)
{
	char	*str;
	size_t	len;

	if (src1 == NULL && src2 == NULL)
		return (NULL);
	len = ft_strlen(src1) + ft_strlen(src2);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strncpy(str, src1, -1);
	len = ft_strlen(str);
	ft_strncpy(&(str[len]), src2, -1);
	return (str);
}
