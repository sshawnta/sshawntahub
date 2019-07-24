/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <sshawnta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 19:05:12 by sshawnta          #+#    #+#             */
/*   Updated: 2019/07/24 19:23:00 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_container(t_cont *container)
{
	t_node	*tmp;
	int		i;

	tmp = container->a_start;
	i = 0;
	while (i < container->a_size)
	{
		tmp = container->a_start->next;
		free(container->a_start);
		container->a_start = tmp;
		i++;
	}
	free(container);
}

static void	file_options(t_cont *cont, short done)
{
	char	*value;

	if (cont->opt.f == TRUE && done == FALSE)
	{
		cont->fd = open("result.log", O_WRONLY | O_CREAT, 0644);
	}
	if (cont->opt.t == TRUE && done == TRUE)
	{
		cont->opt.c == TRUE ? ft_putstr("\e[38;5;46m") : 0;
		ft_putendl_fd("Total number of moves:", cont->fd);
		value = ft_itoa(cont->total);
		ft_putendl_fd(value, cont->fd);
		cont->opt.c == TRUE ? ft_putstr("\e[0m") : 0;
		free(value);
	}
	if (cont->fd != 1 && done == TRUE)
		close(cont->fd);
	cont->fd == 0 ? cont->fd = 1 : cont->fd;
}

int			main(int argc, char **argv)
{
	t_cont		*container;

	if (argc >= 2)
	{
		container = parser(argc, argv, PUSH);
		file_options(container, FALSE);
		if (container->opt.v == TRUE)
		{
			ft_putstr("\033[0;31m");
			ft_putendl("Initial state:");
			ft_putstr("\033[0m");
			visualiser(container);
		}
		sort(container);
		file_options(container, TRUE);
		free_container(container);
	}
	else
		terminate(ERR_NO_NUMBERS);
	return (0);
}
