/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <sshawnta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 19:02:43 by sshawnta          #+#    #+#             */
/*   Updated: 2019/07/24 19:06:49 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_ordered(t_cont *cont)
{
	t_node	*tmp;
	int		i;

	tmp = A_FIRST;
	i = 0;
	while (i++ < cont->a_size && tmp->value < tmp->next->value)
		tmp = tmp->next;
	if (i == cont->a_size && cont->b_size == 0)
		return (1);
	else
		return (0);
}

int		check_index(t_cont *cont, t_node *ind_start)
{
	int		index;
	int		pairs;
	t_node	*current;

	pairs = 0;
	if (cont->a_start && ind_start)
	{
		index = ind_start->index;
		ind_start->keep = TRUE;
		current = ind_start->next;
		while (current != ind_start)
		{
			if (current->index > index)
			{
				pairs++;
				index = current->index;
				current->keep = TRUE;
			}
			else
				current->keep = FALSE;
			current = current->next;
		}
	}
	return (pairs);
}

void	order_stack(t_cont *cont)
{
	int		i;
	int		current_pairs;
	t_node	*current;

	if (cont->a_start)
	{
		i = 0;
		current = cont->a_start;
		while (i < cont->a_size)
		{
			current_pairs = check_index(cont, current);
			if (current_pairs > cont->pairs)
			{
				cont->index_start = current;
				cont->pairs = current_pairs;
			}
			else if (current_pairs == cont->pairs && \
			(!cont->index_start || current->value < cont->index_start->value))
				cont->index_start = current;
			i++;
			current = current->next;
		}
	}
	check_index(cont, cont->index_start);
}
