#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_env	point;
	int		i;

	if (argc == 1)
		return (1);
	i = check_err(&point, argc, argv);
	sort(&point);
	show_move(&point);
	return (0);
}

int		check_err(t_env *point, int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	double	val;

	i = 0;
	j = 0;
	point->arg.name = 0;
	point->arg.color = 0;
	point->arg.file = 0;
	while (++j <= 2 && j < argc)
	{
		!ft_strcmp(argv[j], "-v") && (point->arg.name = 1) ? i++ : 0;
		!ft_strcmp(argv[j], "-c") && (point->arg.color = 1) ? i++ : 0;
		!ft_strcmp(argv[j], "-f") && (point->arg.file = 1) ? i++ : 0;
	}
	if ((point->arg.file == 1 && point->arg.name == 1)
		|| (point->arg.file == 1 && point->arg.color == 1) || (point->arg.file == 1 && argc > 3))
		error(0);
	if (point->arg.file == 1)
		file_read(point, argc, argv, i);
	else
	{
		while (++i < argc)
		{
			k = -1;
			while (argv[i][++k])
				error(!(!ft_isdigit(argv[i][k]) && argv[i][k] != '-'));
			j = i;
			val = ft_atof(argv[i]); // заменить на функцию из либы
			while (++j < argc)
				error(!(val == ft_atof(argv[j])));
			error(!(val > MAX_INT || val < MIN_INT));
		}
	}
	if (point->arg.file == 0)
		create_stacks(point, argc, argv);
	else
		return (1);
	return (0);
}

void	file_read(t_env *point, int argc, char **argv, int i)
{
	int		fd;
	char	*line;
	int		res;
	char	**arr;
	double	val;

	arr = malloc(sizeof(char *) * 500);
	i = 0;
	line = malloc(sizeof(char *) * 500);
	if (argc == 3)
	{
		fd = open(argv[2], O_RDONLY);
		while ((res = get_next_line(fd, &line)) == 1)
		{
			error(!(!ft_isdigit(line[0]) && line[0] != '-'));
			val = ft_atof(line);
			error(!(val > MAX_INT || val < MIN_INT));
			arr[i] = line;
			i++;
		}
		argv = arr;
		argc = i;
		close(fd);
		create_stacks(point, i, arr);
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
		ft_printf("%s\n", "Error");
		exit(0);
	}
	return ;
}

/* НоВыЙ ФаЙл */
int		swap_a(t_env *point, int mv)
{
	int		tmp;

	if (point->stack_a != NULL && point->stack_a->next != NULL)
	{
		tmp = point->stack_a->value;
		point->stack_a->value = point->stack_a->next->value;
		point->stack_a->next->value = tmp;
		mv == 0 ? add_move(point, "sa") : 0;
		return (1);
	}
	return (0);
}

int		swap_b(t_env *point, int mv)
{
	int		tmp;

	if (point->stack_b != NULL && point->stack_b->next != NULL)
	{
		tmp = point->stack_b->value;
		point->stack_b->value = point->stack_b->next->value;
		point->stack_b->next->value = tmp;
		mv == 0 ? add_move(point, "sb") : 0;
		return (1);
	}
	return (0);
}

void	swap_a_and_b(t_env *point)
{
	int		opachki;

	opachki = 0;
	opachki += swap_a(point, 1);
	opachki += swap_b(point, 1);
	opachki != 0 ? add_move(point, "ss") : 0;
}
/*NOVIY FAIL*/

int		rotate_a(t_env *point, int mv)
{
	t_stack	*tmp;

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

int		rotate_b(t_env *point, int mv)
{
	t_stack	*tmp;

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

void	rotate_a_and_b(t_env *point)
{
	int		opachki;

	opachki = 0;
	opachki += rotate_a(point, 1);
	opachki += rotate_b(point, 1);
	opachki != 0 ? add_move(point, "rr") : 0;
}
/*NOVIY FAIl*/

int		rev_rotate_a(t_env *point, int mv)
{
	t_stack	*tmp;
	t_stack	*end;

	if (point->stack_a != NULL && point->stack_a->next != NULL)
	{
		tmp = point->stack_a;
		end = point->stack_end_a;
		while (tmp->next != point->stack_end_a)
			tmp = tmp->next;
		point->stack_end_a = tmp;
		point->stack_end_a->next = NULL;
		end->next = point->stack_a;
		point->stack_a = end;
		mv == 0 ? add_move(point, "rra") : 0;
		return (1);
	}
	return (0);
}

int		rev_rotate_b(t_env *point, int mv)
{
	t_stack	*tmp;
	t_stack	*end;

	if (point->stack_b != NULL && point->stack_b->next != NULL)
	{
		tmp = point->stack_b;
		end = point->stack_end_b;
		while (tmp->next != point->stack_end_b)
			tmp = tmp->next;
		point->stack_end_b = tmp;
		point->stack_end_b->next = NULL;
		end->next = point->stack_b;
		point->stack_b = end;
		mv == 0 ? add_move(point, "rrb") : 0;
		return (1);
	}
	return (0);
}

void	rev_rotate_a_and_b(t_env *point)
{
	int		opachki;

	opachki = 0;
	opachki += rev_rotate_a(point, 1);
	opachki += rev_rotate_b(point, 1);
	opachki != 0 ? add_move(point, "rrr") : 0;
}
/*NOVIY FAIL*/

void	push_a(t_env *point)
{
	t_stack	*tmp;

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

void	push_b(t_env *point)
{
	t_stack *tmp;

	if (point->stack_a != NULL)
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
/*NOVIY FAIL*/

void	add_move(t_env *point, char *mv)
{
	if (point->move == NULL)
	{
		error((int)(point->move = (t_move *)malloc(sizeof(t_move))));
		point->move_end = point->move;
		point->count = 1;
	}
	else
	{
		error((int)(point->move_end->next = (t_move*)malloc(sizeof(t_move))));
		point->move_end = point->move_end->next;
		point->count++;
	}
	point->move_end->name = mv;
	point->move_end->next = NULL;
	if (point->arg.name)
	{
		show_stack(point, point->stack_a, 'a');
		show_stack(point, point->stack_b, 'b');
		point->arg.color == 0 ? ft_printf("%s%s\n", "Use -> ", mv) : ft_printf("\e[93m%s%s\n", "Use - ", mv);
	}
}

void	show_stack(t_env *point, t_stack *stack, char c)
{
	t_stack *st;

	st = stack;
	c == 'a' && point->arg.color ? ft_putstr(COLOR_GREEN) : 0;
	c == 'b' && point->arg.color ? ft_putstr(COLOR_BLUE) : 0;
	ft_printf("%c%s", c, ": ");
	while (st != NULL)
	{
		ft_printf("%d", st->value);
		st->next != NULL ? ft_printf("%s", ", ") : 0;
		st = st->next;
	}
	ft_printf("\n");
	ft_printf(COLOR);
}

void	show_move(t_env *point)
{
	t_move	*st;
	int		fd;

	st = point->move;
	if (point->arg.file == 1)
	{
		fd = open("result.txt", O_WRONLY);
		while (st != NULL)
		{
			ft_strfd(fd, st->name);
			st->next != NULL ? ft_strfd(fd, "\n") : 0;
			st = st->next;
		}
		close(fd);
	}
	else
	{
		while (st != NULL)
		{
			point->arg.color ? color(st->name) : 0;
			ft_printf("%s", st->name);
			st->next != NULL ? ft_printf("\n") : 0;
			st = st->next;
			ft_printf(COLOR);
		}
		ft_printf("\n");
	}
}

void	ft_strfd(int fd, char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(fd, &str[i], 1);
		i++;
	}
}

void	color(char *name)
{
	!ft_strcmp(name, "sa") ? ft_printf(COLOR_RED) : 0;
	!ft_strcmp(name, "sb") ? ft_printf(COLOR_GREEN) : 0;
	!ft_strcmp(name, "pa") ? ft_printf(COLOR_YELLOW) : 0;
	!ft_strcmp(name, "pb") ? ft_printf(COLOR_BLUE) : 0;
	!ft_strcmp(name, "ra") ? ft_printf(COLOR_MAJ) : 0;
	!ft_strcmp(name, "rb") ? ft_printf(COLOR_CYAN) : 0;
	!ft_strcmp(name, "rra") ? ft_printf(COLOR_MAJ) : 0;
	!ft_strcmp(name, "rrb") ? ft_printf(COLOR_GREY) : 0;
}

/*
novyi fail LIBA
*/
double	ft_atof(const char *str)
{
	int		sign;
	double	i;
	double	value;

	i = 1;
	sign = 0;
	value = 0;
	while (ft_isblank(*str))
		str++;
	*str == '-' ? sign = 1 : 0;
	*str == '-' || *str == '+' ? str++ : 0;
	while ('0' <= *str && *str <= '9')
		value = value * 10 + (*str++ - '0');
	if (*str == '.' && (str++))
		while ('0' <= *str && *str <= '9')
			value += (*str++ - '0') / (i *= 10);
	return (sign == 1 && value > 0 ? -value : value);
}

int		ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int		ft_isblank(char c)
{
	return ((c == ' ' || c == '\n' || c == '\v' ||
			c == '\t' || c == '\r' || c == '\f'));
}

int		ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_putstr(char const *s)
{
	write(1, s, ft_strlen(s));
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (s == NULL || start > ft_strlen(s) || \
			!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len && s[start] != '\0')
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s1);
	if (!(str = (char*)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/* NOVIY FAIL ALGOS */

int		minax(t_env *point)
{
	int		count;
	int		count_min;
	t_stack	*stack;

	point->min = MAX_INT;
	point->max = MIN_INT;
	count = 1;
	count_min = 1;
	stack = point->stack_a;
	while (stack != NULL)
	{
		point->min > stack->value ? count_min = count : 0;
		point->min > stack->value ? point->min = stack->value : 0;
		point->max < stack->value ? point->max = stack->value : 0;
		stack = stack->next;
		count++;
	}
	point->count_min = count_min;
	count_min > (count / 2) ? point->count_min = ABS((count - count_min + 1)) : 0;
	count /= 2;
	return (count_min > count ? 1 : -1);
}

int		sort(t_env *point)
{
	if (point->stack_a->next == NULL)
		return (0);
	while (proverka_prav(point->stack_a, 0) != 0 || point->stack_b == NULL)
	{
		point->m = minax(point);
		if (point->min == point->stack_a->next->value)
			swap_a(point, 0);
		else
			while (point->count_min-- - 1 > 0)
				point->m == -1 ? rotate_a(point, 0) : rev_rotate_a(point, 0);
		if (proverka_prav(point->stack_a, 0) == 0 && point->stack_b == NULL)
			break ;
		if (point->stack_b != NULL &&
			proverka_prav(point->stack_a, 0) == 0 &&
			proverka_prav(point->stack_b, 1) == 0)
			break ;
		push_b(point);
	}
	while (point->stack_b != NULL)
		push_a(point);
	return (0);
}

int		proverka_prav(t_stack *stack, int md)
{
	t_stack		*st;

	st = stack;
	while (st->next != NULL)
	{
		if (md == 0 && st->value > st->next->value)
			return (-1);
		if (md == 1 && st->value < st->next->value)
			return (-1);
		st = st->next;
	}
	return (0);
}
