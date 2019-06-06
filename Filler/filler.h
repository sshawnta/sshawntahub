#ifndef FILLER_H
#define FILLER_H
#include "get_next_line.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

typedef struct	s_player
{
	char		id;
	t_point		start;
}				t_player;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_token
{
	int			width;
	int			height;
	int			size;
	char		**data;
}				t_token;

typedef struct	s_filler
{
	int			inited;
	t_player	player;
	t_player	enemy;
	t_point		target;
	t_token		board;
	t_token		token;
	t_point		*buf_p;
	int			p_count;
	t_point		*buf_e;
	int			e_count;
}				t_filler;

#endif