/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <sshawnta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 19:04:36 by sshawnta          #+#    #+#             */
/*   Updated: 2019/07/24 19:07:19 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_cont *cont, short rr)
{
	if (A_FIRST)
	{
		A_FIRST = A_SECOND;
		if (rr == FALSE)
		{
			cont->total++;
			cont->opt.c == TRUE ? ft_putstr("\e[38;5;70m") : 0;
			ft_putendl_fd("ra", cont->fd);
			cont->opt.c == TRUE ? ft_putstr("\e[0m") : 0;
			cont->opt.v == TRUE ? visualiser(cont) : 0;
		}
	}
}

void	rb(t_cont *cont, short rr)
{
	if (B_FIRST)
	{
		B_FIRST = B_SECOND;
		if (rr == FALSE)
		{
			cont->total++;
			cont->opt.c == TRUE ? ft_putstr("\e[38;5;71m") : 0;
			ft_putendl_fd("rb", cont->fd);
			cont->opt.c == TRUE ? ft_putstr("\e[0m") : 0;
			cont->opt.v == TRUE ? visualiser(cont) : 0;
		}
	}
}

void	rr(t_cont *cont)
{
	ra(cont, TRUE);
	rb(cont, TRUE);
	cont->total++;
	cont->opt.c == TRUE ? ft_putstr("\e[38;5;72m") : 0;
	ft_putendl_fd("rr", cont->fd);
	cont->opt.c == TRUE ? ft_putstr("\e[0m") : 0;
	cont->opt.v == TRUE ? visualiser(cont) : 0;
}
