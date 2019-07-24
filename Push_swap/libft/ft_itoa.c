/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <sshawnta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:04:40 by twight            #+#    #+#             */
/*   Updated: 2019/07/24 19:00:23 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	itoa_is_negative(int *n, int *negative)
{
	if (*n < 0)
	{
		*n = *n * (-1);
		*negative = 1;
	}
}

char		*ft_itoa(int n)
{
	int		tmp_n;
	int		len;
	int		negative;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tmp_n = n;
	len = 2;
	negative = 0;
	itoa_is_negative(&n, &negative);
	while (tmp_n /= 10)
		len++;
	len = len + negative;
	if (!(str = (char*)malloc(len)))
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (negative)
		str[0] = '-';
	return (str);
}
