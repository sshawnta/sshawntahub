/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualiser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <sshawnta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 19:05:47 by sshawnta          #+#    #+#             */
/*   Updated: 2019/07/24 19:08:20 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_row(t_node *node)
{
	short	value_len;
	short	i;

	i = 0;
	value_len = ft_strlen(ft_itoa(node->value));
	ft_putchar('|');
	if (value_len % 2 == 0)
	{
		while (i++ <= ((13 - value_len) / 2))
			ft_putchar(' ');
	}
	else
	{
		while (i++ < ((13 - value_len) / 2))
			ft_putchar(' ');
	}
	ft_putstr(ft_itoa(node->value));
	while (i++ <= 13 - value_len)
		ft_putchar(' ');
}

void		visualiser(t_cont *cont)
{
	t_node	*tmp_a;
	t_node	*tmp_b;
	int		i;
	int		j;

	tmp_a = cont->a_start;
	tmp_b = cont->b_start;
	i = 0;
	j = 0;
	ft_putendl("|   Stack A   |   Stack B   |");
	while (i < cont->a_size || j < cont->b_size)
	{
		if (i++ < cont->a_size)
			print_row(tmp_a);
		else
			ft_putstr("|             ");
		if (j++ < cont->b_size)
			print_row(tmp_b);
		else
			ft_putstr("|             ");
		ft_putendl("|");
		tmp_a ? tmp_a = tmp_a->next : 0;
		tmp_b ? tmp_b = tmp_b->next : 0;
	}
}
