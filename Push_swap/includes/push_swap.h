/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <sshawnta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 18:50:19 by sshawnta          #+#    #+#             */
/*   Updated: 2019/07/24 19:25:29 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PUSH_SWAP_H
# define __PUSH_SWAP_H

# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"

# define FALSE 0
# define TRUE 1

# define PUSH 0
# define CHECK 1

# define FT_MAX(X, Y) ((X) > (Y) ? (X) : (Y))

# define ERR_FILENAME "program terminated, error: could not find the file"
# define ERR_FILEREAD "program terminated, error: could not read the file"
# define ERR_MEMALLOC "program terminated, error: could not allocate memory"
# define ERR_NAN "program terminated, error: invalid values"
# define ERR_DUP "program terminated, error: duplicate values"
# define ERR_NO_NUMBERS "program terminated, error: not enough values"
# define ERR_WRONG_MV "program terminated, error: unknown or invalid command"
# define ERR_WR_FLAG "program terminated, error: unknown or invalid option(s)"

# define A_FIRST cont->a_start

# define A_SECOND cont->a_start->next

# define B_FIRST cont->b_start

# define B_SECOND cont->b_start->next

typedef struct		s_node
{
	int				value;
	int				index;
	short			keep;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct		s_opt
{
	short			f;
	short			c;
	short			t;
	short			v;
}					t_opt;

typedef struct		s_cont
{
	int				index;
	t_opt			opt;
	int				a_size;
	int				b_size;
	int				total;
	t_node			*a_start;
	t_node			*b_start;
	t_node			*a_end;
	int				fd;
	short			program;
	int				pairs;
	t_node			*index_start;
}					t_cont;

typedef struct		s_shift
{
	t_node			*a_node;
	t_node			*b_node;
	int				a_direction;
	int				b_direction;
	int				size;
	short			set;
}					t_shift;

typedef enum
{
	R,
	RR
}	t_direction;

/*
** add.c
*/

void				add(t_node **head, t_node **tail, int value);

/*
** parser.c
*/

t_cont				*parser(int argc, char **argv, short program);

/*
** push.c
*/

void				pa(t_cont *cont);
void				pb(t_cont *cont);

/*
** reverse_rotate.c
*/

void				rra(t_cont *cont, short rrr);
void				rrb(t_cont *cont, short rrr);
void				rrr(t_cont *cont);

/*
** rotate.c
*/

void				ra(t_cont *cont, short rr);
void				rb(t_cont *cont, short rr);
void				rr(t_cont *cont);

/*
** swap.c
*/

void				sa(t_cont *cont, t_node *first, t_node *second, short ss);
void				sb(t_cont *cont, t_node *first, t_node *second, short ss);
void				ss(t_cont *c);

/*
** terminate.c
*/

void				terminate(const char *str);

/*
** visualizer.c
*/

void				visualiser(t_cont *cont);

/*
** sort.c
*/

void				sort(t_cont *cont);

/*
** index.c
*/

void				get_index(t_cont *cont);

/*
** align.c
*/

void				move_b(t_cont *cont, t_shift *shift);
void				align_a(t_cont *cont);

/*
** order.c
*/

int					is_ordered(t_cont *cont);
int					check_index(t_cont *cont, t_node *ind_start);
void				order_stack(t_cont *cont);

/*
** shift.c
*/

void				opt_direction(t_cont *cont, t_shift *shift);

#endif
