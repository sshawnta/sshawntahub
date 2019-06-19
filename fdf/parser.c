/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twight <twight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 16:01:48 by twight            #+#    #+#             */
/*   Updated: 2019/06/15 21:39:10 by twight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		count_nums(char *line)
{
	char	**line_numbers;
	int		count;

	line_numbers = ft_strsplit(line, ' ');
	count = 0;
	while (line_numbers[count])
	{
		free(line_numbers[count]);
		count++;
	}
	free(line_numbers);
	return (count);
}

int		count_lines(t_fdf *tab)
{
	char	*line;

	line = NULL;
	while (get_next_line(tab->fd, &line) > 0)
	{
		if (tab->line_count == 0)
			tab->num_count = count_nums(line);
		else if (tab->num_count != count_nums(line))
			return (-1);
		tab->line_count++;
	}
	close(tab->fd);
	tab->fd = open(tab->name, O_RDONLY);
	return ((tab->line_count <= 1) ? -1 : 0);
}

int		populate_matrix(t_fdf *tab)
{
	int		i;
	int		j;
	char	*line;
	char	**line_nums;

	i = 0;
	j = 0;
	line = NULL;
	while (get_next_line(tab->fd, &line) > 0)
	{
		j = 0;
		line_nums = ft_strsplit(line, ' ');
		while (line_nums[j])
		{
			tab->matrix[i][j] = ft_atoi(line_nums[j]);
			free(line_nums[j]);
			j++;
		}
		free(line_nums);
		i++;
	}
	return (0);
}

int		parser(t_fdf *tab)
{
	int		i;

	i = 0;
	tab->line_count = 0;
	tab->num_count = 0;
	if (count_lines(tab) == -1)
		return (-1);
	tab->matrix = ft_memalloc(sizeof(int *) * tab->line_count);
	while (i <= tab->line_count)
	{
		tab->matrix[i] = ft_memalloc(sizeof(int) * tab->num_count);
		i++;
	}
	if (populate_matrix(tab) == -1)
		return (-1);
	return (0);
}
