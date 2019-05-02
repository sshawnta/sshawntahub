/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:50:45 by sshawnta          #+#    #+#             */
/*   Updated: 2019/04/17 14:58:28 by twight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_etris	*tetris_new(char **pos, unsigned char width, unsigned char height, \
char value)
{
	t_etris *tetris;

	tetris = ft_memalloc(sizeof(t_etris));
	tetris->pos = pos;
	tetris->width = width;
	tetris->height = height;
	tetris->value = value;
	return (tetris);
}

t_point	*point_new(unsigned char x, unsigned char y)
{
	t_point *point;

	point = ft_memalloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	return (point);
}

void	free_tetris(t_etris *tetri)
{
	unsigned char y;

	y = 0;
	while (y < tetri->height)
	{
		ft_memdel((void **)(&(tetri->pos[y])));
		y++;
	}
	ft_memdel((void **)(&(tetri->pos)));
	ft_memdel((void **)&tetri);
}

t_list	*free_list(t_list *list)
{
	t_etris	*tetris;
	t_list	*next;

	while (list)
	{
		tetris = (t_etris *)list->content;
		next = list->next;
		free_tetris(tetris);
		ft_memdel((void **)&list);
		list = next;
	}
	return (NULL);
}
