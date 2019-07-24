#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshawnta <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/24 19:02:03 by sshawnta          #+#    #+#              #
#    Updated: 2019/07/24 19:02:04 by sshawnta         ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME_PS = push_swap
NAME_CH = checker

CC = gcc
FLAGS = -Wall -Wextra -Werror

INCLUDES = -I./includes -I./libft
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./libft/

SRCS = $(ALG) $(CMNDS) $(UTILS)
SRCS_DIR = ./srcs/

ALG = $(ALG_DIR)align.c $(ALG_DIR)index.c $(ALG_DIR)order.c $(ALG_DIR)sort.c \
		$(ALG_DIR)shift.c
ALG_DIR = $(SRCS_DIR)algorithm/

CMNDS = $(CMNDS_DIR)push.c $(CMNDS_DIR)reverse_rotate.c $(CMNDS_DIR)rotate.c \
		$(CMNDS_DIR)swap.c
CMNDS_DIR = $(SRCS_DIR)commands/

UTILS = $(UTILS_DIR)add.c $(UTILS_DIR)parser.c $(UTILS_DIR)terminate.c \
		$(UTILS_DIR)visualiser.c
UTILS_DIR = $(SRCS_DIR)utilities/

CHECKER_C = $(MAIN_DIR)checker.c
PUSH_SWAP_C = $(MAIN_DIR)push_swap.c
MAIN_DIR = $(SRCS_DIR)main_files/

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME_PS) $(NAME_CH)

$(NAME_PS): $(LIBFT)
		@$(CC) $(FLAGS) $(LIBFT) $(INCLUDES) $(SRCS) $(PUSH_SWAP_C) -o $(NAME_PS)
		@echo "$(NAME_PS): $(GREEN)$(NAME_PS) has been created$(RESET)"
$(NAME_CH): $(LIBFT)
		@$(CC) $(FLAGS) $(LIBFT) $(INCLUDES) $(SRCS) $(CHECKER_C) -o $(NAME_CH)
		@echo "$(NAME_PS): $(GREEN)$(NAME_CH) has been created$(RESET)"
$(LIBFT):
		@$(MAKE) -C $(LIBFT_DIR)
		@echo "$(NAME_PS): $(GREEN)Assembling $(LIBFT)...$(RESET)"

clean:
		@$(MAKE) clean -C $(LIBFT_DIR)

fclean:
		@$(MAKE) fclean -C $(LIBFT_DIR)
		@rm -rf $(NAME_PS) $(NAME_CH)
		@echo "$(NAME_PS): $(RED)$(NAME_PS) and $(NAME_CH) executables have been deleted$(RESET)"

re:
		@$(MAKE) fclean
		@$(MAKE) all

.PHONY: all clean fclean re