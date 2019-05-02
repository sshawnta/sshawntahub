/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 12:31:28 by twight            #+#    #+#             */
/*   Updated: 2019/04/17 15:05:39 by twight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_map(t_map *map)
{
	unsigned char	i;

	i = 0;
	while (i < map->size)
	{
		ft_memdel((void**)&(map->array[i]));
		i++;
	}
	ft_memdel((void**)&(map->array));
	ft_memdel((void**)&map);
}

void	print_map(t_map *map)
{
	unsigned char	i;

	i = 0;
	while (i < map->size)
	{
		ft_putstr(map->array[i]);
		ft_putchar('\n');
		i++;
	}
}

t_map	*map_new(unsigned char size)
{
	t_map			*map;
	unsigned char	i;
	unsigned char	j;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->size = size;
	map->array = (char**)ft_memalloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		map->array[i] = ft_strnew(size);
		j = 0;
		while (j < size)
		{
			map->array[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}
