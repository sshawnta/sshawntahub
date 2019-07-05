/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <sshawnta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 17:18:27 by sshawnta          #+#    #+#             */
/*   Updated: 2019/07/05 13:41:58 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		rev_rotate_a(t_env *point, int mv)
{
	t_stack	*tmp;
	t_stack	*end;

	if (point->stack_a != NULL && point->stack_a->next != NULL)
	{
		tmp = point->stack_a;
		end = point->stack_end_a;
		while (tmp->next != point->stack_end_a)
			tmp = tmp->next;
		point->stack_end_a = tmp;
		point->stack_end_a->next = NULL;
		end->next = point->stack_a;
		point->stack_a = end;
		mv == 0 ? add_move(point, "rra") : 0;
		return (1);
	}
	return (0);
}

int		rev_rotate_b(t_env *point, int mv)
{
	t_stack	*tmp;
	t_stack	*end;

	if (point->stack_b != NULL && point->stack_b->next != NULL)
	{
		tmp = point->stack_b;
		end = point->stack_end_b;
		while (tmp->next != point->stack_end_b)
			tmp = tmp->next;
		point->stack_end_b = tmp;
		point->stack_end_b->next = NULL;
		end->next = point->stack_b;
		point->stack_b = end;
		mv == 0 ? add_move(point, "rrb") : 0;
		return (1);
	}
	return (0);
}

void	rev_rotate_a_and_b(t_env *point)
{
	int		opachki;

	opachki = 0;
	opachki += rev_rotate_a(point, 1);
	opachki += rev_rotate_b(point, 1);
	opachki != 0 ? add_move(point, "rrr") : 0;
}
