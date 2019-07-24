/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <sshawnta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 19:04:43 by sshawnta          #+#    #+#             */
/*   Updated: 2019/07/24 19:07:28 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_cont *cont, t_node *first, t_node *second, short ss)
{
	t_node	*prev;
	t_node	*next;

	if (first && second)
	{
		prev = first->prev;
		next = second->next;
		prev->next = second;
		second->prev = prev;
		first->next = next;
		next->prev = first;
		second->next = first;
		first->prev = second;
		A_FIRST = second;
		if (ss == FALSE)
		{
			cont->total++;
			cont->opt.c == TRUE ? ft_putstr("\e[38;5;214m") : 0;
			ft_putendl_fd("sa", cont->fd);
			cont->opt.c == TRUE ? ft_putstr("\e[0m") : 0;
			cont->opt.v == TRUE ? visualiser(cont) : 0;
		}
	}
}

void	sb(t_cont *cont, t_node *first, t_node *second, short ss)
{
	t_node	*prev;
	t_node	*next;

	if (first && second)
	{
		prev = first->prev;
		next = second->next;
		prev->next = second;
		second->prev = prev;
		first->next = next;
		next->prev = first;
		second->next = first;
		first->prev = second;
		B_FIRST = second;
		if (ss == FALSE)
		{
			cont->total++;
			cont->opt.c == TRUE ? ft_putstr("\e[38;5;215m") : 0;
			ft_putendl_fd("sb", cont->fd);
			cont->opt.c == TRUE ? ft_putstr("\e[0m") : 0;
			cont->opt.v == TRUE ? visualiser(cont) : 0;
		}
	}
}

void	ss(t_cont *cont)
{
	sa(cont, A_FIRST, A_SECOND, TRUE);
	sb(cont, B_FIRST, B_SECOND, TRUE);
	cont->total++;
	cont->opt.c == TRUE ? ft_putstr("\e[38;5;216m") : 0;
	ft_putendl_fd("ss", cont->fd);
	cont->opt.c == TRUE ? ft_putstr("\e[0m") : 0;
	cont->opt.v == TRUE ? visualiser(cont) : 0;
}
