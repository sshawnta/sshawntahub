/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetramino.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:54:03 by twight            #+#    #+#             */
/*   Updated: 2019/04/17 19:18:49 by twight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			min_max(char *str, t_point *min, t_point *max)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i % 5 < min->x)
				min->x = i % 5;
			if (i / 5 < min->y)
				min->y = i / 5;
			if (i % 5 > max->x)
				max->x = i % 5;
			if (i / 5 > max->y)
				max->y = i / 5;
		}
		i++;
	}
}

t_etris			*get_piece(char *str, char value)
{
	t_point			*min;
	t_point			*max;
	char			**pos;
	unsigned char	i;
	t_etris			*tetri;

	min = point_new(3, 3);
	max = point_new(0, 0);
	min_max(str, min, max);
	pos = ft_memalloc(sizeof(char*) * (max->y - min->y + 1));
	i = 0;
	while (i < max->y - min->y + 1)
	{
		pos[i] = ft_strnew(max->x - min->x + 1);
		ft_strncpy(pos[i], str + (min->x) + (min->y + i) * 5, max->x - min->x \
		+ 1);
		i++;
	}
	tetri = tetris_new(pos, max->x - min->x + 1, max->y - min->y + 1, value);
	ft_memdel((void **)&min);
	ft_memdel((void **)&max);
	return (tetri);
}

unsigned char	check_edge(char *str)
{
	unsigned char	i;
	unsigned char	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (i > 3 && str[i - 5] == '#')
				count++;
			if (i % 5 > 0 && str[i - 1] == '#')
				count++;
			if (i % 5 != 3 && str[i + 1] == '#')
				count++;
			if (i < 15 && str[i + 5] == '#')
				count++;
		}
		i++;
	}
	return (count == 6 || count == 8);
}

unsigned char	check_tetramino(char *str, char *bu, char *ch)
{
	unsigned char	i;
	unsigned char	count;

	if (!str)
		return (1);
	i = 0;
	count = 0;
	  if ((str[4] != '\n' || str[9] != '\n' || str[14] != '\n' || str[19] != '\n' || str[20] != '\n') && (*bu != 20 && *ch != 1))
		return (1);
	while (str[i])
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n' && str[i] != 127)
			return (1);
		if (str[i] == '#')
			count++;
		i++;
	}
	if (count != 4)
		return (1);
	if (!check_edge(str))
		return (1);
	return (0);
}

t_list			*read_tetri(int fd)
{
	char	*buf;
	char	count[3];
	t_list	*list;
	t_etris	*tetris;
	char	letter;

	buf = ft_memalloc(22);
	list = NULL;
	letter = 'A';
	count[2] = 0;
	while ((count[0] = read(fd, buf, 21)) >= 20)
	{
	  count[2] =  count[2] + 1;
	  if (check_tetramino(buf, &count[1], &count[2]) != 0 || !(tetris = get_piece(buf, letter++)))
		{
			ft_memdel((void **)&buf);
			return (free_list(list));
		}
		ft_lstadd(&list, ft_lstnew(tetris, sizeof(t_etris)));
		ft_memdel((void **)&tetris);
		count[1] = count[0];
	}
	ft_memdel((void **)&buf);
	if (count[0] != 0 || count[1] != 20)
		return (free_list(list));
	ft_lstrev(&list);
	return (list);
}
