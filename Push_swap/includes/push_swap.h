/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <sshawnta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 17:17:58 by sshawnta          #+#    #+#             */
/*   Updated: 2019/07/05 14:19:19 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include "../libprintf/ft_printf/ft_printf.h"

# define ABS(x) (x < 0 ? -(x) : x)
# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define COLOR_YELLOW "\e[93m"
# define COLOR_CYAN "\e[36m"
# define COLOR_GREY "\e[90m"
# define COLOR_BLUE "\e[34m"
# define COLOR_MAJ "\e[35m"
# define COLOR_ORANGE "\e[33m"
# define COLOR_RED "\e[31m"
# define COLOR_GREEN "\e[32m"
# define COLOR "\e[0m"
# define BUFF_SIZE 32
# define MAX_FD 1024 + 1

typedef struct		s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_move
{
	char			*name;
	struct s_move	*next;
}					t_move;

typedef struct		s_arg
{
	short			name;
	short			color;
	short			file;
}					t_arg;

typedef struct		s_env
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	t_stack			*stack_end_a;
	t_stack			*stack_end_b;
	t_move			*move;
	t_move			*move_end;
	t_arg			arg;
	int				count_min;
	int				count;
	int				min;
	int				max;
	int				m;
}					t_env;

int					check_err(t_env *point, int argc, char **argv);
void				create_stacks(t_env *point, int argc, char **argv);
void				error(int err);
void				da_da(t_env *point);
void				op_op (int i, int argc, int k, char **argv, \
					t_env *point, double val);
t_move				*inache(t_env *point, t_move *st);
void				asdad(int i, int j, int argc, char **argv);
void				close_free(int fd, char **arr, char *tmp);
void				file_read(t_env *point, int argc, char **argv, int i);
int					get_next_line(const int fd, char **line);
int					ft_new_line(char **s, char **line, int fd, int ret);
int					swap_a(t_env *point, int mv);
int					swap_b(t_env *point, int mv);
void				swap_a_and_b(t_env *point);
int					rotate_a(t_env *point, int mv);
int					rotate_b(t_env *point, int mv);
void				rotate_a_and_b(t_env *point);
int					rev_rotate_a(t_env *point, int mv);
int					rev_rotate_b(t_env *point, int mv);
void				rev_rotate_a_and_b(t_env *point);
void				push_a(t_env *point);
void				push_b(t_env *point);
void				add_move(t_env *point, char *mv);
void				show_stack(t_env *point, t_stack *stack, char c);
void				show_move(t_env *point);
void				color(char *name);
double				ft_atof(const char *str);
int					ft_isdigit(int c);
int					ft_isblank(char c);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_putstr(char const *s);
char				*ft_strdup(const char *s1);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				ft_strfd(int fd, char *str);
int					ft_atoi(const char *str);
int					sort(t_env *point);
int					minax(t_env *point);
int					proverka_prav(t_stack *stack, int md);
int					read_rule(t_env *point);
int					check(t_env *point);
void				free_point(t_env *point);
#endif
