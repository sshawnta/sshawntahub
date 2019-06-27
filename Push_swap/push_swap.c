#include "ft_printf/ft_printf.h"
#include "push_swap.h"

int main(int argc, char **argv)
{
	t_env point;

	if (argc == 1)
		return (1);
	check_err(&point, argc, argv);
	create_stacks(&point, argc, argv);
	sort(&point);
	disp_moves(&point);
	return (0);
}

void check_err(t_env *point, int argc, char **argv)
{
	int i;
	int j;
	int k;
	double val;

	i = 0;
	j = 0;

	point->arg.name = 0;
	point->arg.color = 0;

	while (++j <= 2 && j < argc)
	{
		!ft_strcmp(argv[j], "-v") && (point->arg.name = 1) ? i++: 0;
		!ft_strcmp(argv[j], "-c") && (point->arg.color = 1) ? i++: 0;
	}
	while (++i < argc)
	{
		k = -1;
		while (argv[i][++k])
			error(!(!ft_isdigit(argv[i][k]) && argv[i][k] != '-'));
		j = i;
		val = atof(argv[i]); // заменить на функцию из либы
		while (++j < argc)
			error(!(val == ft_atof(argv[j])));
			error(!(val > MAX_INT || val < MIN_INT));
	}
}

void create_stacks(t_env *point, int argc, char **argv)
{
	int i;
	t_stack *current;

	point->move = NULL;
	point->stack_b = NULL;
	error((int)(current = (t_stack*)malloc(sizeof(t_stack))));
	point->stack_a = current;
	i = point->arg.name + point->arg.color;
	error(!(i >= argc - 1));
	while (++i < argc)
	{
		current->value = atoi(argv[i]); // заменить на функц из либы
		current->next = NULL;
		if (i + 1 < argc)
		{
			error((int)(current->next = (t_stack*)malloc(sizeof(t_stack))));
			current = current->next;		
		}
	}
	point->stack_end_a = current;
} 

void	error(int err)
{
	if (err == 0 || err == -1)
	{
		ft_putstr("Error\n");
		exit(0);
	}
	return ;
}


/*
НоВыЙ ФаЙл
 */

int swap_a(t_env *point, int mv)
{
	int tmp;

	if (point->stack_a != NULL && point->stack_a->next != NULL)
	{
		tmp = point->stack_a->value;
		point->stack_a->value = point->stack_a->next->value;
		point->stack_a->next->value = tmp;
		mv == 0 ? add_move(point, "sa") : 0; // NEt takoi funkc;
		return (1);
	}
	return (0);
}

int swap_b(t_env *point, int mv)
{
	int tmp;

		if (point->stack_b != NULL && point->stack_b->next != NULL)
	{
		tmp = point->stack_b->value;
		point->stack_b->value = point->stack_b->next->value;
		point->stack_b->next->value = tmp;
		mv == 0 ? add_move(point, "sb") : 0; // NEt takoi funkc;
		return (1);
	}
	return (0);	
}

int swap_a_and_b(t_env *point)
{
	int opachki;

	opachki = 0;
	opachki += swap_a(point, 1);
	opachki += swap_b(point, 1);
	opachki != 0 add_move(point, "ss") : 0;
}

/*
NOVIY FAIL
*/

int rotate_a(t_env *point, int mv)
{
	t_stack *tmp;

	if (point->stack_a != NULL && point->stack_a->next != NULL)
	{
		tmp = point->stack_a;
		point->stack_a = point->stack_a->next;
		tmp->next = NULL;
		point->stack_end_a->next = tmp;
		point->stack_end_a = tmp;
		mv == 0 ? add_move(point, "ra") : 0;
		return (1);
	}
	return (0);
}

int rotate_b(t_env *point, int mv)
{
	t_stack *tmp;

	if (point->stack_b != NULL && point->stack_b->next != NULL)
	{
		tmp = point->stack_b;
		point->stack_b = point->stack_b->next;
		tmp->next = NULL;
		point->stack_end_b->next = tmp;
		point->stack_end_b = tmp;
		mv == 0 ? add_move(point, "rb") : 0;
		return (1);
	}
	return (0);
}

void rotate_a_and_b(t_env *point)
{
	int opachki;

	opachki = 0;
	opachki += rotate_a(point, 1);
	opachki += rotate_b(point, 1);
	opachki != 0 add_move(point, "rr") : 0;
}

/*
NOVIY FAIl
*/
int rev_rotate_a(t_env *point, int mv)
{
	t_stack *tmp;
	t_stack *end;

	if (point->stack_a != NULL && point->stack_a->next != NULL)
	{
		tmp = point->stack_a;
		end = point->stack_end_a;
		while (tmp->next != point->stack_end_a)
			tmp = tmp->next;
		point->stack_end_a = tmp;
		point->stack_end_a->next != NULL;
		end->next = point->stack_a;
		point->stack_a = end;
		mv = 0 ? add_move (point, "rra") : 0;
		return (1);
	}
	return (0);
}

int rev_rotate_b(t_env *point, int mv)
{
	t_stack *tmp;
	t_stack *end;

	if (point->stack_b != NULL && point->stack_b->next != NULL)
	{
		tmp = point->stack_b;
		end = point->stack_end_b;
		while (tmp->next != point->stack_end_b)
			tmp = tmp->next;
		point->stack_end_b = tmp;
		point->stack_end_b->next != NULL;
		end->next = point->stack_b;
		point->stack_b = end;
		mv = 0 ? add_move (point, "rra") : 0;
		return (1);
	}
	return (0);
}

void rev_rotate_a_and_b(t_env *point)
{
	int opachki;

	opachki = 0;
	opachki += rev_rotate_a(point, 1);
	opachki += rev_rotate_b(point, 1);
	opachki != 0 ? add_move(point, "rrr") : 0;
}

/*
NOVIY FAIL
*/

void push_a(t_env *point)
{
	t_stack *tmp;

	if (point->stack_b != NULL)
	{
		tmp = point->stack_b;
		point->stack_b = point->stack_b->next;
		tmp->next = point->stack_a;
		point->stack_a = tmp;
		point->stack_a->next == NULL ? point->stack_end_a = point->stack_a : 0;
		point->stack_b == NULL ? point->stack_end_b = NULL : 0;
		add_move(point, "pa");
	}
}

void push_b(t_env *point)
{
	t_stack *tmp;

	if(point->stack_a != NULL)
	{
		tmp = point->stack_a;
		point->stack_a = point->stack_a->next;
		tmp->next = point->stack_b;
		point->stack_b = tmp;
		point->stack_b->next == NULL ? point->stack_end_b = point->stack_b : 0;
		point->stack_a == NULL ? point->stack_end_a = NULL : 0;
		add_move(point, "pb");
	}
}

/*
NOVIY FAIL
*/

void add_move(t_env *point, char *mv)
{
	if (point->move == NULL)
	{
		error((int)(point->move = (t_move *)malloc(sizeof(t_move))));
		point->move_end = point->move;
		point->count = 1;
	}
}
