/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <sshawnta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 13:00:52 by twight            #+#    #+#             */
/*   Updated: 2019/06/19 15:16:33 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF_H
# define __FDF_H

# include <fcntl.h> // open function
# include <unistd.h> // write function
# include <mlx.h> // minilibx
# include <stdlib.h>
# include "libft/libft.h" // Libft funcs

# define WIDTH 1280
# define HEIGHT 720

# define abs(x)  ( (x<0) ? -(x) : x )

typedef struct  s_fdf
{
    int         fd;
    char        *name;
    void        *mlx;
    void        *window;
    char        *wtitle;
    int         line_count;
    int         num_count;
    int         **matrix;


    int				check;
	int				z;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	unsigned long	color;
}               t_fdf;              

int     parser(t_fdf *tab);
int draw_t(t_fdf *tab, int x0, int x1, int y0, int y1);

//void    draw(t_fdf *tab);
int hook_key(int key, t_fdf *mlx);


#endif