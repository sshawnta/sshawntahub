/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <sshawnta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 19:04:17 by sshawnta          #+#    #+#             */
/*   Updated: 2019/07/24 19:07:08 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_a(t_cont *cont, t_node *node)
{
	t_node	*end;

	if (node)
	{
		if (!A_FIRST)
		{
			A_FIRST = node;
			A_FIRST->prev = A_FIRST;
			A_FIRST->next = A_FIRST;
		}
		else
		{
			end = A_FIRST->prev;
			node->prev = end;
			end->next = node;
			node->next = A_FIRST;
			A_FIRST->prev = node;
			A_FIRST = node;
		}
		cont->a_size++;
		cont->total++;
		cont->opt.c == TRUE ? ft_putstr("\e[38;5;137m") : 0;
		ft_putendl_fd("pa", cont->fd);
		cont->opt.c == TRUE ? ft_putstr("\e[0m") : 0;
	}
}

void		pa(t_cont *cont)
{
	t_node	*node;

	node = NULL;
	if (cont->b_size)
	{
		if (cont->b_size == 1)
		{
			node = B_FIRST;
			B_FIRST = NULL;
			node->prev = NULL;
			node->next = NULL;
		}
		else
		{
			node = B_FIRST;
			B_FIRST = B_FIRST->next;
			node->prev->next = node->next;
			node->next->prev = node->prev;
			node->prev = NULL;
			node->next = NULL;
		}
		cont->b_size--;
	}
	push_a(cont, node);
	cont->opt.v == TRUE ? visualiser(cont) : 0;
}

static void	push_b(t_cont *cont, t_node *node)
{
	t_node	*end;

	if (node)
	{
		if (!B_FIRST)
		{
			B_FIRST = node;
			B_FIRST->prev = B_FIRST;
			B_FIRST->next = B_FIRST;
		}
		else
		{
			end = B_FIRST->prev;
			node->prev = end;
			end->next = node;
			node->next = B_FIRST;
			B_FIRST->prev = node;
			B_FIRST = node;
		}
		cont->b_size++;
		cont->total++;
		cont->opt.c == TRUE ? ft_putstr("\e[38;5;138m") : 0;
		ft_putendl_fd("pb", cont->fd);
		cont->opt.c == TRUE ? ft_putstr("\e[0m") : 0;
	}
}

void		pb(t_cont *cont)
{
	t_node	*node;

	node = NULL;
	if (cont->a_size)
	{
		if (cont->a_size == 1)
		{
			node = A_FIRST;
			A_FIRST = NULL;
			node->prev = NULL;
			node->next = NULL;
		}
		else
		{
			node = A_FIRST;
			A_FIRST = A_FIRST->next;
			node->prev->next = node->next;
			node->next->prev = node->prev;
			node->prev = NULL;
			node->next = NULL;
		}
		cont->a_size--;
	}
	push_b(cont, node);
	cont->opt.v == TRUE ? visualiser(cont) : 0;
}
