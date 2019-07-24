/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <sshawnta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 19:02:32 by sshawnta          #+#    #+#             */
/*   Updated: 2019/07/24 19:06:25 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*next_min(t_cont *cont)
{
	int		i;
	short	has_min;
	t_node	*min;
	t_node	*current;

	min = NULL;
	if (cont->a_start)
	{
		i = 0;
		has_min = FALSE;
		current = cont->a_start;
		while (i < cont->a_size)
		{
			if ((current->index == -1)
				&& (!has_min || current->value < min->value))
			{
				has_min = TRUE;
				min = current;
			}
			i++;
			current = current->next;
		}
	}
	return (min);
}

void			get_index(t_cont *cont)
{
	t_node	*current;
	int		i;

	i = 0;
	while ((current = next_min(cont)))
		current->index = i++;
}
