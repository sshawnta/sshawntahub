# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: twight <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/17 15:57:07 by twight            #+#    #+#              #
#    Updated: 2019/04/17 17:30:53 by twight           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re make all

NAME = fillit

FILE = check_tetromino.c main.c map.c solver.c write_free.c

SRCS = $(addprefix srcs/, $(FILE))

OBJS = $(addprefix build/, $(FILE:.c=.o))

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) | lib
	gcc $(FLAGS) -o $(NAME) -I includes/ -L ./libft -lft $(OBJS)

build/%.o: srcs/%.c | build
	gcc $(FLAGS) -I includes/ -o $@ -c $^

re: fclean all

lib:
	make -C ./libft
	make clean -C ./libft

clean:
	/bin/rm -rf build/

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

build:
	mkdir build/
