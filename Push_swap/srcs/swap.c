/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <sshawnta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 17:17:18 by sshawnta          #+#    #+#             */
/*   Updated: 2019/07/05 13:42:00 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		swap_a(t_env *point, int mv)
{
	int		tmp;

	if (point->stack_a != NULL && point->stack_a->next != NULL)
	{
		tmp = point->stack_a->value;
		point->stack_a->value = point->stack_a->next->value;
		point->stack_a->next->value = tmp;
		mv == 0 ? add_move(point, "sa") : 0;
		return (1);
	}
	return (0);
}

int		swap_b(t_env *point, int mv)
{
	int		tmp;

	if (point->stack_b != NULL && point->stack_b->next != NULL)
	{
		tmp = point->stack_b->value;
		point->stack_b->value = point->stack_b->next->value;
		point->stack_b->next->value = tmp;
		mv == 0 ? add_move(point, "sb") : 0;
		return (1);
	}
	return (0);
}

void	swap_a_and_b(t_env *point)
{
	int		opachki;

	opachki = 0;
	opachki += swap_a(point, 1);
	opachki += swap_b(point, 1);
	opachki != 0 ? add_move(point, "ss") : 0;
}
