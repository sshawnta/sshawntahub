/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:07:10 by sshawnta          #+#    #+#             */
/*   Updated: 2019/04/17 17:31:16 by twight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <string.h>
# include "../libft/libft.h"

/*
** X-Y structure
*/

typedef struct	s_point
{
	unsigned char	x;
	unsigned char	y;
}				t_point;

/*
** The structure which stores the properties of a specific tetromino which has
** been read in the course of reading the file
*/

typedef struct	s_etris
{
	char			**pos;
	unsigned char	width;
	unsigned char	height;
	char			value;
}				t_etris;

/*
** The structure which stores the properties of the map to be rendered
*/

typedef struct	s_map
{
	unsigned char	size;
	char			**array;
}				t_map;

/*
** The list of functions being used to read the file and store the identified
** tetrominoes in the singly linked list. Each nod of such list contains the
** pointer (*content) to the content (*t_etris)
*/

void			min_max(char *str, t_point *min, t_point *max);
t_etris			*get_piece(char *str, char value);
unsigned char	check_edge(char *str);
unsigned char	check_tetramino(char *str, char *bu, char *ch);
t_list			*read_tetri(int fd);

/*
** The list of functions being used to 1) write data in t_etris structure,
** s_point structure, 2) free t_etris structure and t_list singly linked list
*/

t_etris			*tetris_new(char **pos, unsigned char width, \
				unsigned char height, char value);
t_point			*point_new(unsigned char x, unsigned char y);
void			free_tetris(t_etris *tetri);
t_list			*free_list(t_list *list);

/*
** The functions which are used to arrange and print out the map
*/

void			free_map(t_map *map);
void			print_map(t_map *map);
t_map			*map_new(unsigned char size);

/*
** The functions used to solve the arrangement of tetrominoes
*/

unsigned char	place(t_etris *tetri, t_map *map, unsigned char x, \
unsigned char y);
void			set_piece(t_etris *tetri, t_map *map, t_point *point, char c);
unsigned char	solve_map(t_map *map, t_list *list);
unsigned char	h_sqrt(unsigned char n);
t_map			*solve(t_list *list);

#endif
