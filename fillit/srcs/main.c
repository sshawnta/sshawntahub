/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:56:22 by sshawnta          #+#    #+#             */
/*   Updated: 2019/04/17 15:48:42 by twight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_list	*list;
	t_map	*map;

	if (argc == 2)
	{
		if ((list = read_tetri(open(argv[1], O_RDONLY))) == NULL)
		{
			ft_putstr("error\n");
			return (1);
		}
		map = solve(list);
		print_map(map);
		free_map(map);
		free_list(list);
	}
	else
	{
		ft_putstr("usage: fillit input_file\n");
		return (1);
	}
	return (0);
}
