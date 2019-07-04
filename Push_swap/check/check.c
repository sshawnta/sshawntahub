/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <sshawnta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 17:17:29 by sshawnta          #+#    #+#             */
/*   Updated: 2019/07/04 17:19:20 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_env	point;
	int		i;

	if (argc == 1)
		return (1);
	i = check_err(&point, argc, argv);
	read_rule(&point);
	free_point(&point);
	return (0);
}

void	free_point(t_env *point)
{
	t_move		*tmp_move;
	t_stack		*tmp_stack;

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

int		read_rule(t_env *point)
{
	char *str;
	char *tmp;

	str = malloc(sizeof(char *) * 4);
	tmp = str;
	while (1)
	{
		get_next_line(0, &str);
		!ft_strcmp(str, "sa") ? swap_a(point, 1) : 0;
		!ft_strcmp(str, "sb") ? swap_b(point, 1) : 0;
		!ft_strcmp(str, "ss") ? swap_a_and_b(point) : 0;
		!ft_strcmp(str, "pa") ? push_a(point) : 0;
		!ft_strcmp(str, "pb") ? push_b(point) : 0;
		!ft_strcmp(str, "ra") ? rotate_a(point, 1) : 0;
		!ft_strcmp(str, "rb") ? rotate_b(point, 1) : 0;
		!ft_strcmp(str, "rr") ? rotate_a_and_b(point) : 0;
		!ft_strcmp(str, "rra") ? rev_rotate_a(point, 1) : 0;
		!ft_strcmp(str, "rrb") ? rev_rotate_b(point, 1) : 0;
		!ft_strcmp(str, "rrr") ? rev_rotate_a_and_b(point) : 0;
		!ft_strcmp(str, "check") ? check(point) : 0;
		free(str);
	}
	free(tmp);
	return (0);
}

int		check(t_env *point)
{
	while (point->stack_a->next != NULL)
	{
		if (point->stack_a->value < point->stack_a->next->value)
			point->stack_a = point->stack_a->next;
		else
		{
			ft_printf("%s\n", "KO");
			exit(0);
		}
	}
	ft_printf("%s\n", "OK");
	exit(0);
	return (0);
}
