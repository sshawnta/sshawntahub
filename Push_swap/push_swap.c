/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <sshawnta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 17:15:14 by sshawnta          #+#    #+#             */
/*   Updated: 2019/07/04 17:18:46 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_err(t_env *point, int argc, char **argv)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	da_da(point);
	while (++j <= 2 && j < argc)
	{
		!ft_strcmp(argv[j], "-v") && (point->arg.name = 1) ? i++ : 0;
		!ft_strcmp(argv[j], "-c") && (point->arg.color = 1) ? i++ : 0;
		!ft_strcmp(argv[j], "-f") && (point->arg.file = 1) ? i++ : 0;
	}
	if ((point->arg.file == 1 && point->arg.name == 1)
		|| (point->arg.file == 1 && point->arg.color == 1) ||
			(point->arg.file == 1 && argc > 3))
		error(0);
	if (point->arg.file == 1 && argc == 3)
		file_read(point, argc, argv, i);
	else
		asdad(i, j, argc, argv);
	if (point->arg.file == 0)
		create_stacks(point, argc, argv);
	else
		return (1);
	return (0);
}

void	asdad(int i, int j, int argc, char **argv)
{
	int		k;
	double	val;

	while (++i < argc)
	{
		k = -1;
		while (argv[i][++k])
			error(!(!ft_isdigit(argv[i][k]) && argv[i][k] != '-'));
		j = i;
		val = ft_atof(argv[i]);
		while (++j < argc)
			error(!(val == ft_atof(argv[j])));
		error(!(val > MAX_INT || val < MIN_INT));
	}
}

void	da_da(t_env *point)
{
	point->arg.name = 0;
	point->arg.color = 0;
	point->arg.file = 0;
}

void	file_read(t_env *point, int argc, char **argv, int i)
{
	int		fd;
	char	*line;
	char	**arr;
	char	*tmp;
	double	val;

	arr = malloc(sizeof(char *) * 500);
	i = 0;
	line = malloc(sizeof(char *) * 500);
	tmp = line;
	if (argc == 3)
	{
		fd = open(argv[2], O_RDONLY);
		while ((get_next_line(fd, &line)))
		{
			error(!(!ft_isdigit(line[0]) && line[0] != '-'));
			val = ft_atof(line);
			error(!(val > MAX_INT || val < MIN_INT));
			arr[i++] = line;
			free(line);
		}
		argv = arr;
		create_stacks(point, i, arr);
		close_free(fd, arr, tmp);
	}
}

void	create_stacks(t_env *point, int argc, char **argv)
{
	int		i;
	t_stack	*current;

	point->move = NULL;
	point->stack_b = NULL;
	error((int)(current = (t_stack*)malloc(sizeof(t_stack))));
	point->stack_a = current;
	i = point->arg.name + point->arg.color;
	error(!(i >= argc - 1));
	while (++i < argc)
	{
		current->value = ft_atoi(argv[i]);
		current->next = NULL;
		if (i + 1 < argc)
		{
			current->next = (t_stack*)malloc(sizeof(t_stack));
			error((int)(current->next));
			current = current->next;
		}
	}
	point->stack_end_a = current;
}
