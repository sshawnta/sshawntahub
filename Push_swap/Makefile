# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshawnta <sshawnta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/05 13:42:28 by sshawnta          #+#    #+#              #
#    Updated: 2019/07/05 13:42:34 by sshawnta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PS = push_swap
NAME_CH = checker

CC = gcc
FLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes/
LIBPRINTF = $(LIBPRINTF_DIR)libftprintf.a
LIBPRINTF_DIR = ./libprintf/
SRCS = ./srcs/alg.c ./srcs/get_next_line.c ./srcs/helps.c ./srcs/lib.c ./srcs/lib2.c ./srcs/push_swap.c ./srcs/push.c \
		./srcs/rev_rot.c ./srcs/rot.c ./srcs/swap.c ./srcs/util2.c
CHECKER_C = ./srcs/checker.c
PUSH_SWAP_C = ./srcs/mainpush.c

all: $(NAME_PS) $(NAME_CH)

$(NAME_PS): $(LIBPRINTF)
	$(CC) $(FLAGS) $(LIBPRINTF) $(INCLUDES) $(SRCS) $(PUSH_SWAP_C) -o $(NAME_PS)

$(NAME_CH): $(LIBPRINTF)
	$(CC) $(FLAGS) $(LIBPRINTF) $(INCLUDES) $(SRCS) $(CHECKER_C) -o $(NAME_CH)

$(LIBPRINTF):
	$(MAKE) -C $(LIBPRINTF_DIR)

clean:
	$(MAKE) clean -C $(LIBPRINTF_DIR)

fclean:
	$(MAKE) fclean -C $(LIBPRINTF_DIR)
	/bin/rm -rf $(NAME_PS) $(NAME_CH)

re:
	$(MAKE) fclean
	$(MAKE) all