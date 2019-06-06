/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:15:49 by sshawnta          #+#    #+#             */
/*   Updated: 2019/04/05 16:18:28 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countchars(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	else if (n < 0)
		i++;
	else
	{
		while (n > 0)
		{
			i++;
			n /= 10;
		}
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int				i;
	unsigned int	j;
	int				s;
	char			*b;

	if (!(b = ft_strnew(ft_countchars(n))))
		return (NULL);
	j = n;
	if ((s = n) < 0)
		j = -n;
	i = 0;
	if (j == 0)
		b[i++] = '0';
	while (j > 0)
	{
		b[i++] = j % 10 + '0';
		j /= 10;
	}
	if (s < 0)
		b[i++] = '-';
	b[i] = '\0';
	ft_strrev(b);
	return (b);
}
