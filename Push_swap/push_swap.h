#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

# define ABS(x) (x < 0 ? -(x) : x)
# define MAX_INT 2147483647
# define MIN_INT -2147483648

enum { ONE, BOTH };
enum { INC, DECd };

typedef struct	s_stack
{
	int				value;
	struct s_stack	*next;
}				t_stack;

typedef struct	s_move
{
	char			*name;
	struct s_move	*next;
}				t_move;


typedef struct	s_arg
{
	short	name;
	short	color;
}				t_arg;

typedef struct	s_env
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*stack_end_a;
	t_stack	*stack_end_b;
	t_move	*move;
	t_move	*move_end;
	t_arg	arg;
	int		count_min;
	int		count;
	int		min;
	int		max;
	int		m;
}				t_env;
/*Glavnaya tema*/
void check_err(t_env *point, int argc, char **argv);
void create_stacks(t_env *point, int argc, char **argv);
void	error(int err);
/*swap*/
int swap_a(t_env *point, int mv);
int swap_b(t_env *point, int mv);
int swap_a_and_b(t_env *point);
/*rotate*/
int rotate_a(t_env *point, int mv);
int rotate_b(t_env *point, int mv);
void rotate_a_and_b(t_env *point);
/*rev rotate*/
int rev_rotate_a(t_env *point, int mv);
int rev_rotate_b(t_env *point, int mv);
void rev_rotate_a_and_b(t_env *point);
/*push*/
void push_a(t_env *point);
void push_b(t_env *point);

#endif