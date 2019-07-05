/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <sshawnta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 17:15:40 by sshawnta          #+#    #+#             */
/*   Updated: 2019/07/05 13:41:59 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		rotate_a(t_env *point, int mv)
{
	t_stack	*tmp;

	if (point->stack_a != NULL && point->stack_a->next != NULL)
	{
		tmp = point->stack_a;
		point->stack_a = point->stack_a->next;
		tmp->next = NULL;
		point->stack_end_a->next = tmp;
		point->stack_end_a = tmp;
		mv == 0 ? add_move(point, "ra") : 0;
		return (1);
	}
	return (0);
}

int		rotate_b(t_env *point, int mv)
{
	t_stack	*tmp;

	if (point->stack_b != NULL && point->stack_b->next != NULL)
	{
		tmp = point->stack_b;
		point->stack_b = point->stack_b->next;
		tmp->next = NULL;
		point->stack_end_b->next = tmp;
		point->stack_end_b = tmp;
		mv == 0 ? add_move(point, "rb") : 0;
		return (1);
	}
	return (0);
}

void	rotate_a_and_b(t_env *point)
{
	int		opachki;

	opachki = 0;
	opachki += rotate_a(point, 1);
	opachki += rotate_b(point, 1);
	opachki != 0 ? add_move(point, "rr") : 0;
}
