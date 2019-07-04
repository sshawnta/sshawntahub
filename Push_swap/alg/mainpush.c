/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainpush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <sshawnta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 17:14:51 by sshawnta          #+#    #+#             */
/*   Updated: 2019/07/04 17:54:12 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		main(int argc, char **argv)
{
	t_env	point;
	int		i;

	if (argc == 1)
		return (1);
	i = check_err(&point, argc, argv);
	sort(&point);
	show_move(&point);
	free_point(&point);
	return (0);
}

void	free_point(t_env *point)
{
	t_move		*tmp_move;
	t_stack		*tmp_stack;

	if (point->move != NULL)
	{
		while (point->move->next != NULL)
		{
			tmp_move = point->move->next;
			free(point->move);
			point->move = tmp_move;
		}
		while (point->stack_a->next != NULL)
		{
			tmp_stack = point->stack_a->next;
			free(point->stack_a);
			point->stack_a = tmp_stack;
		}
		free(point->stack_end_a);
		free(point->move_end);
	}
}
