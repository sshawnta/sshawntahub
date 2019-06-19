/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twight <twight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 13:58:56 by twight            #+#    #+#             */
/*   Updated: 2019/06/17 16:17:56 by twight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    draw_line(t_fdf *tab, int x0, int x1, int y0, int y1)
{
    int deltax;
    int deltay;
    int error;
    int deltaerr;
    int x;
    int y;
    int diry;

    deltax = abs(x1 - x0);
    deltay = abs(y1 - y0);
    error = 0;
    deltaerr = deltay;
    x = x0;
    y = y0;
    diry = y1 - y0;
    if (diry > 0) 
        diry = 1;
    if (diry < 0) 
        diry = -1;
    while (x <= x1)
    {
        mlx_pixel_put(tab->mlx, tab->window, x, y, 255*65536+0*256+0);
        error = error + deltaerr;
        if (2 * error >= deltax)
        {
            y = y + diry;
            error = error - deltax;
        }
        x++;
    }
}

void    draw_grid(t_fdf *tab, int scale)
{
    int x;
    int y;
    int i;
    int j;
    
    i = 0;
    j = 0;
    x = tab->matrix[i][j]
    while (x * scale <= )
}

void    draw(t_fdf *tab)
{
    int margin;
    int i;
    int j;
    unsigned long color;
    
    i = 0;
    margin = 50;
    color = 255*65536+0*256+0;
    draw_grid(tab, margin)
    /*
    while (i < tab->line_count)
    {
        j = 0;
        while (j < tab->num_count)
        {
            draw_line(tab, i * margin, (i + 1) * margin, j * margin, (j + 1) * margin);
            j++;
        }
        i++;
    } 
    */ 
}