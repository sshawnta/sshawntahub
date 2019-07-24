/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <sshawnta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 13:01:48 by twight            #+#    #+#             */
/*   Updated: 2019/07/24 19:00:22 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*nod;
	t_list	*nod_next;

	if (!*alst || !alst || !del)
		return ;
	nod = *alst;
	while (nod)
	{
		nod_next = nod->next;
		del(nod->content, nod->content_size);
		free(nod);
		nod = nod_next;
	}
	*alst = NULL;
}
