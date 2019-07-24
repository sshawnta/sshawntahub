/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <sshawnta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 19:05:28 by sshawnta          #+#    #+#             */
/*   Updated: 2019/07/24 19:25:22 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		add(t_node **head, t_node **tail, int value)
{
	t_node	*new;
	t_node	*tmp;

	if (!(new = (t_node *)ft_memalloc(sizeof(t_node))))
		terminate(ERR_MEMALLOC);
	new->next = NULL;
	new->value = value;
	new->prev = *tail;
	new->index = -1;
	*tail = new;
	if (*head)
	{
		tmp = *head;
		while (tmp->next && tmp->value != value && tmp != *tail)
			tmp = tmp->next;
		if (tmp->value == value)
		{
			free(new);
			new = NULL;
			terminate(ERR_DUP);
		}
		tmp->next = new;
	}
	else
		*head = new;
}
