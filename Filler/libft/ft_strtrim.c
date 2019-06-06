/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:06:09 by sshawnta          #+#    #+#             */
/*   Updated: 2019/04/05 16:14:19 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i[2];
	char	*result;

	if (s == NULL)
		return (NULL);
	i[0] = 0;
	if (!(result = ft_memalloc(ft_strlen(s))))
		return (NULL);
	ft_memcpy(result, s, ft_strlen(s));
	while (result[i[0]] && (result[i[0]] == ' ' ||
							result[i[0]] == '\n' || result[i[0]] == '\t'))
		i[0]++;
	i[1] = ft_strlen(s) - 1;
	while (i[1] > 0)
	{
		if (result[i[1]] == ' ' || result[i[1]] == '\n' || result[i[1]] == '\t')
			i[1]--;
		else
		{
			result[i[1] + 1] = '\0';
			break ;
		}
	}
	return (ft_strdup(&result[i[0]]));
}
