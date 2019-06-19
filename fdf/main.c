/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <sshawnta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 13:00:33 by twight            #+#    #+#             */
/*   Updated: 2019/06/19 16:21:12 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h> // To delete

/*
** Error processing
*/

int hook_key(int key, t_fdf *mlx)
{
	(void)mlx;
	if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}
int		show_error(char *str)
{
	int i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (0);
}

/*
** GUI initialization; TBA
*/

int draw_t(t_fdf *tab, int x0, int x1, int y0, int y1)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tab->matrix[i][j])
	{
		
	}
	return (0);
}
void	mlx(t_fdf *tab)
{
	tab->mlx = mlx_init();
	tab->window = mlx_new_window(tab->mlx, WIDTH, HEIGHT, tab->wtitle);
	mlx_clear_window(tab->mlx, tab->window);
	//draw(tab);
	draw_t(tab, 400, 800, 400, 800);
	mlx_key_hook(tab->window, hook_key, tab->mlx);
	//mlx_hook(tab->window, 17, (1L << 17), cross, tab);
	mlx_loop(tab->mlx);
}

int		main(int argc, char **argv)
{
	t_fdf	tab;

	if (argc != 2)
		return (show_error("Wrong number of arguments\n"));
	tab.fd = open(argv[1], O_RDONLY);
	if (tab.fd < 0)
		return (show_error("Could not open the file\n"));
	tab.name = argv[1];
	if (!(tab.wtitle = ft_strjoin("FdF - ", tab.name)))
		return (show_error("Could not initialize the window title"));
	if (parser(&tab))
		return (show_error("The file is invalid. Please check the source file\n"));
	mlx(&tab);
	return (0);
}
