/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <sshawnta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 17:17:00 by sshawnta          #+#    #+#             */
/*   Updated: 2019/07/05 13:41:57 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a(t_env *point)
{
	t_stack	*tmp;

	if (point->stack_b != NULL)
	{
		tmp = point->stack_b;
		point->stack_b = point->stack_b->next;
		tmp->next = point->stack_a;
		point->stack_a = tmp;
		point->stack_a->next == NULL ? point->stack_end_a = point->stack_a : 0;
		point->stack_b == NULL ? point->stack_end_b = NULL : 0;
		add_move(point, "pa");
	}
}

void	push_b(t_env *point)
{
	t_stack *tmp;

	if (point->stack_a != NULL)
	{
		tmp = point->stack_a;
		point->stack_a = point->stack_a->next;
		tmp->next = point->stack_b;
		point->stack_b = tmp;
		point->stack_b->next == NULL ? point->stack_end_b = point->stack_b : 0;
		point->stack_a == NULL ? point->stack_end_a = NULL : 0;
		add_move(point, "pb");
	}
}
