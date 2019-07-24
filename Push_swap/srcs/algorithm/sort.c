/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <sshawnta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 19:02:57 by sshawnta          #+#    #+#             */
/*   Updated: 2019/07/24 19:24:46 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static short	pb_required(t_cont *cont)
{
	int		i;
	t_node	*current;

	if (cont->a_start)
	{
		i = 0;
		current = cont->a_start;
		while (i < cont->a_size)
		{
			if (current->keep == FALSE)
				return (TRUE);
			i++;
			current = current->next;
		}
	}
	return (FALSE);
}

static short	sa_required(t_cont *cont)
{
	int		current_pairs;

	if (cont->a_start && cont->a_size >= 2)
	{
		sa(cont, A_FIRST, A_SECOND, TRUE);
		current_pairs = check_index(cont, cont->index_start);
		sa(cont, A_FIRST, A_SECOND, TRUE);
		check_index(cont, cont->index_start);
		if (current_pairs > cont->pairs)
			return (TRUE);
	}
	return (FALSE);
}

static t_shift	*init_shift(void)
{
	t_shift	*shift;

	if (!(shift = (t_shift *)ft_memalloc(sizeof(t_shift))))
		terminate(ERR_MEMALLOC);
	shift->a_node = NULL;
	shift->b_node = NULL;
	shift->a_direction = R;
	shift->b_direction = R;
	shift->size = 0;
	shift->set = FALSE;
	return (shift);
}

static void		solve(t_cont *cont, t_shift *shift)
{
	while (pb_required(cont))
	{
		if (sa_required(cont))
		{
			sa(cont, A_FIRST, A_SECOND, FALSE);
			cont->pairs = check_index(cont, cont->index_start);
		}
		else if (cont->a_start->keep == FALSE)
			pb(cont);
		else
			ra(cont, FALSE);
	}
	while (cont->b_size)
	{
		shift->set = FALSE;
		opt_direction(cont, shift);
		move_b(cont, shift);
		pa(cont);
	}
}

void			sort(t_cont *cont)
{
	t_shift	*shift;

	get_index(cont);
	order_stack(cont);
	shift = init_shift();
	solve(cont, shift);
	align_a(cont);
	free(shift);
}
