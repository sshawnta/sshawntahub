/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <sshawnta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 17:14:31 by sshawnta          #+#    #+#             */
/*   Updated: 2019/07/04 16:49:13 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	color(char *name)
{
	!ft_strcmp(name, "sa") ? ft_printf(COLOR_RED) : 0;
	!ft_strcmp(name, "sb") ? ft_printf(COLOR_GREEN) : 0;
	!ft_strcmp(name, "pa") ? ft_printf(COLOR_YELLOW) : 0;
	!ft_strcmp(name, "pb") ? ft_printf(COLOR_BLUE) : 0;
	!ft_strcmp(name, "ra") ? ft_printf(COLOR_MAJ) : 0;
	!ft_strcmp(name, "rb") ? ft_printf(COLOR_CYAN) : 0;
	!ft_strcmp(name, "rra") ? ft_printf(COLOR_MAJ) : 0;
	!ft_strcmp(name, "rrb") ? ft_printf(COLOR_GREY) : 0;
}

void	show_move(t_env *point)
{
	t_move	*st;
	int		fd;

	st = point->move;
	if (point->arg.file == 1)
	{
		fd = open("result.txt", O_WRONLY);
		while (st != NULL)
		{
			ft_strfd(fd, st->name);
			st->next != NULL ? ft_strfd(fd, "\n") : 0;
			st = st->next;
		}
		close(fd);
	}
	else
	{
		while (st != NULL)
		{
			st = inache(point, st);
		}
		ft_printf("\n");
	}
}

t_move	*inache(t_env *point, t_move *st)
{
	point->arg.color ? color(st->name) : 0;
	ft_printf("%s", st->name);
	st->next != NULL ? ft_printf("\n") : 0;
	st = st->next;
	ft_printf(COLOR);
	return (st);
}

void	show_stack(t_env *point, t_stack *stack, char c)
{
	t_stack *st;

	st = stack;
	c == 'a' && point->arg.color ? ft_putstr(COLOR_GREEN) : 0;
	c == 'b' && point->arg.color ? ft_putstr(COLOR_BLUE) : 0;
	ft_printf("%c%s", c, ": ");
	while (st != NULL)
	{
		ft_printf("%d", st->value);
		st->next != NULL ? ft_printf("%s", ", ") : 0;
		st = st->next;
	}
	ft_printf("\n");
	ft_printf(COLOR);
}

void	add_move(t_env *point, char *mv)
{
	if (point->move == NULL)
	{
		error((int)(point->move = (t_move *)malloc(sizeof(t_move))));
		point->move_end = point->move;
		point->count = 1;
	}
	else
	{
		error((int)(point->move_end->next =
		(t_move*)malloc(sizeof(t_move))));
		point->move_end = point->move_end->next;
		point->count++;
	}
	point->move_end->name = mv;
	point->move_end->next = NULL;
	if (point->arg.name)
	{
		show_stack(point, point->stack_a, 'a');
		show_stack(point, point->stack_b, 'b');
		point->arg.color == 0 ? ft_printf("%s%s\n", "Use -> ", mv) :
			ft_printf("\e[93m%s%s\n", "Use - ", mv);
	}
}
