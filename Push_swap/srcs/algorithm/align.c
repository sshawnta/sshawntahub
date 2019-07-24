/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <sshawnta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 19:02:24 by sshawnta          #+#    #+#             */
/*   Updated: 2019/07/24 19:06:31 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_b(t_cont *cont, t_shift *shift)
{
	while (shift->a_node != cont->a_start || \
	shift->b_node != cont->b_start)
	{
		if (shift->a_direction == shift->b_direction && \
		shift->a_node != cont->a_start && shift->b_node != cont->b_start)
			(shift->a_direction == R) ? rr(cont) : rrr(cont);
		else if (shift->a_node != cont->a_start)
			(shift->a_direction == R) ? ra(cont, FALSE) : rra(cont, FALSE);
		else if (shift->b_node != cont->b_start)
			(shift->b_direction == R) ? rb(cont, FALSE) : rrb(cont, FALSE);
	}
}

void	align_a(t_cont *cont)
{
	t_node	*current;
	int		ra_size;
	int		rra_size;

	if (cont->a_start)
	{
		ra_size = 0;
		current = cont->a_start;
		while (current->index != 0)
		{
			ra_size++;
			current = current->next;
		}
		rra_size = 0;
		current = cont->a_start;
		while (current->index != 0)
		{
			rra_size++;
			current = current->prev;
		}
		while (cont->a_start->index != 0 && (ra_size < rra_size))
			ra(cont, FALSE);
		while (cont->a_start->index != 0 && (!(ra_size < rra_size)))
			rra(cont, FALSE);
	}
}
