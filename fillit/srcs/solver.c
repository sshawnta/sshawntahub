/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 12:06:41 by sshawnta          #+#    #+#             */
/*   Updated: 2019/04/17 18:34:55 by twight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned char	place(t_etris *tetri, t_map *map, unsigned char x, \
unsigned char y)
{
	unsigned char	i;
	unsigned char	j;

	i = 0;
	while (i < tetri->width)
	{
		j = 0;
		while (j < tetri->height)
		{
			if (tetri->pos[j][i] == '#' && map->array[y + j][x + i] != '.')
				return (0);
			j++;
		}
		i++;
	}
	set_piece(tetri, map, point_new(x, y), tetri->value);
	return (1);
}

void			set_piece(t_etris *tetri, t_map *map, t_point *point, char c)
{
	unsigned char	i;
	unsigned char	j;

	i = 0;
	while (i < tetri->width)
	{
		j = 0;
		while (j < tetri->height)
		{
			if (tetri->pos[j][i] == '#')
				map->array[point->y + j][point->x + i] = c;
			j++;
		}
		i++;
	}
	ft_memdel((void **)&point);
}

unsigned char	solve_map(t_map *map, t_list *list)
{
	unsigned char	x;
	unsigned char	y;
	t_etris			*tetri;

	if (list == NULL)
		return (1);
	y = 0;
	tetri = (t_etris *)(list->content);
	while (y < map->size - tetri->height + 1)
	{
		x = 0;
		while (x < map->size - tetri->width + 1)
		{
			if (place(tetri, map, x, y))
			{
				if (solve_map(map, list->next))
					return (1);
				else
					set_piece(tetri, map, point_new(x, y), '.');
			}
			x++;
		}
		y++;
	}
	return (0);
}

unsigned char	h_sqrt(unsigned char n)
{
	unsigned char	size;

	size = 2;
	while (size * size < n)
		size++;
	return (size);
}

t_map			*solve(t_list *list)
{
	t_map			*map;
	unsigned char	size;

	size = h_sqrt(ft_lstcount(list) * 4);
	map = map_new(size);
	while (!solve_map(map, list))
	{
		size++;
		free_map(map);
		map = map_new(size);
	}
	return (map);
}
