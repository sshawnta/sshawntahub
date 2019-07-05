/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <sshawnta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 17:14:19 by sshawnta          #+#    #+#             */
/*   Updated: 2019/07/05 13:41:44 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		minax(t_env *point)
{
	int		count;
	int		count_min;
	t_stack	*stack;

	point->min = MAX_INT;
	point->max = MIN_INT;
	count = 1;
	count_min = 1;
	stack = point->stack_a;
	while (stack != NULL)
	{
		point->min > stack->value ? count_min = count : 0;
		point->min > stack->value ? point->min = stack->value : 0;
		point->max < stack->value ? point->max = stack->value : 0;
		stack = stack->next;
		count++;
	}
	point->count_min = count_min;
	count_min > (count / 2) ?
		point->count_min = ABS((count - count_min + 1)) : 0;
	count /= 2;
	return (count_min > count ? 1 : -1);
}

int		sort(t_env *point)
{
	if (point->stack_a->next == NULL)
		return (0);
	while (proverka_prav(point->stack_a, 0) != 0 || point->stack_b == NULL)
	{
		point->m = minax(point);
		if (point->min == point->stack_a->next->value)
			swap_a(point, 0);
		else
			while (point->count_min-- - 1 > 0)
				point->m == -1 ? rotate_a(point, 0) : rev_rotate_a(point, 0);
		if (proverka_prav(point->stack_a, 0) == 0 && point->stack_b == NULL)
			break ;
		if (point->stack_b != NULL &&
			proverka_prav(point->stack_a, 0) == 0 &&
			proverka_prav(point->stack_b, 1) == 0)
			break ;
		push_b(point);
	}
	while (point->stack_b != NULL)
		push_a(point);
	return (0);
}

int		proverka_prav(t_stack *stack, int md)
{
	t_stack		*st;

	st = stack;
	while (st->next != NULL)
	{
		if (md == 0 && st->value > st->next->value)
			return (-1);
		if (md == 1 && st->value < st->next->value)
			return (-1);
		st = st->next;
	}
	return (0);
}
