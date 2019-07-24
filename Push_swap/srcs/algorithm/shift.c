/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <sshawnta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 19:02:50 by sshawnta          #+#    #+#             */
/*   Updated: 2019/07/24 19:06:55 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	t_node	*find_a_node(t_cont *cont, int index)
{
	t_node		*current;

	current = cont->index_start;
	if (index < current->index)
	{
		while (index < current->prev->index && \
		current->index > current->prev->index)
			current = current->prev;
	}
	else
	{
		while (index > current->index && \
		current->index < current->next->index)
			current = current->next;
		if (index > current->index && current->index > current->next->index)
			current = current->next;
	}
	return (current);
}

static void		est_dir(t_node *stack, int index, int *rx_size, int *rrx_size)
{
	t_node		*current;

	if (stack)
	{
		current = stack;
		while (current->index != index)
		{
			(*rx_size)++;
			current = current->next;
		}
		current = stack;
		while (current->index != index)
		{
			(*rrx_size)++;
			current = current->prev;
		}
	}
}

static void		set_direction(int size, t_shift *new_shift, t_shift *shift)
{
	if (!shift->set || size < shift->size)
	{
		shift->a_node = new_shift->a_node;
		shift->b_node = new_shift->b_node;
		shift->a_direction = new_shift->a_direction;
		shift->b_direction = new_shift->b_direction;
		shift->size = size;
		shift->set = TRUE;
	}
}

static void		optimal_direction(t_cont *cont, t_node *b_node, t_shift *shift)
{
	t_shift		new_shift;
	int			ra_size;
	int			rra_size;
	int			rb_size;
	int			rrb_size;

	ra_size = 0;
	rra_size = 0;
	rb_size = 0;
	rrb_size = 0;
	new_shift.a_node = find_a_node(cont, b_node->index);
	new_shift.b_node = b_node;
	est_dir(cont->a_start, new_shift.a_node->index, &ra_size, &rra_size);
	est_dir(cont->b_start, b_node->index, &rb_size, &rrb_size);
	new_shift.a_direction = R;
	new_shift.b_direction = R;
	set_direction(FT_MAX(ra_size, rb_size), &new_shift, shift);
	new_shift.a_direction = RR;
	set_direction(rra_size + rb_size, &new_shift, shift);
	new_shift.b_direction = RR;
	set_direction(FT_MAX(rra_size, rrb_size), &new_shift, shift);
	new_shift.a_direction = R;
	set_direction(ra_size + rrb_size, &new_shift, shift);
}

void			opt_direction(t_cont *cont, t_shift *shift)
{
	int		i;
	t_node	*current;

	if (cont->b_start)
	{
		i = 0;
		current = cont->b_start;
		while (i < cont->b_size)
		{
			optimal_direction(cont, current, shift);
			i++;
			current = current->next;
		}
	}
}
