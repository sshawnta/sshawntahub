/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <sshawnta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 12:50:40 by twight            #+#    #+#             */
/*   Updated: 2019/07/24 19:00:18 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*nod;

	if (!(nod = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		nod->content = NULL;
		nod->content_size = 0;
	}
	else
	{
		if (!(nod->content = malloc(content_size)))
			return (NULL);
		ft_memcpy((nod->content), content, content_size);
		nod->content_size = content_size;
	}
	nod->next = NULL;
	return (nod);
}
