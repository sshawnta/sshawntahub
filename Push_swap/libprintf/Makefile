# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: twight <twight@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/28 17:43:55 by sshawnta          #+#    #+#              #
#    Updated: 2019/07/05 12:48:12 by twight           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

OBJS_DIR = libftprintf_objects
CC = clang
CFLAGS = -Wall -Wextra -Werror
RM = /bin/rm -rf

LIBFT_PATH = libft/
LIBFT_INCS =	libft.h\
				libft_typedefs.h
LIBFT_SRCS = 	ft_atoibase.c\
				ft_itoabase.c\
				ft_memalloc.c\
				ft_memcmp.c\
				ft_memdel.c\
				ft_memmove.c\
				ft_memset.c\
				ft_nbr_len.c\
				ft_strchr.c\
				ft_strdel.c\
				ft_strin.c\
				ft_strjoin.c\
				ft_strlen.c\
				ft_strncpy.c\
				ft_strndup.c\
				ft_strncmp.c\
				ft_strnew.c\
				ft_strninject.c\
				ft_strrchr.c
LIBFT_OBJS = $(LIBFT_SRCS:%.c=$(LIBFT_OBJS_DIR)/%.o)
LIBFT_OBJS_DIR = $(OBJS_DIR)

PRINTF_PATH = ft_printf/
PRINTF_INCS =	ft_printf.h\
				ft_printf_typedefs.h
PRINTF_SRCS =	ft_printf.c\
				ft_printf_cspf.c\
				ft_printf_diouxx.c\
				ft_printf_fill_funs.c\
				ft_printf_flags.c\
				ft_printf_parse.c\
				ft_printf_prec.c\
				ft_printf_width.c\
				ft_printf_mod.c\
				ft_printf_base.c\
				ft_printf_lhllhhl.c\
				ft_printf_zjt.c\
				ft_printf_r.c\
				ft_printf_unicode.c\
				ft_printf_parce_funs.c\
				ft_printf_color.c
PRINTF_OBJS = $(PRINTF_SRCS:%.c=$(PRINTF_OBJS_DIR)/%.o)
PRINTF_OBJS_DIR = $(OBJS_DIR)

all: $(NAME)

$(NAME): $(LIBFT_OBJS) $(PRINTF_OBJS)
	@ar rc $(NAME) $^
	@ranlib $(NAME)

$(LIBFT_OBJS_DIR)/%.o: $(LIBFT_PATH)%.c
	@mkdir -p $(LIBFT_OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< $(addprefix -I.,$(addprefix $(LIBFT_PATH),$(LIBFT_INCS))) -o $@

$(PRINTF_OBJS_DIR)/%.o: $(PRINTF_PATH)%.c
	@mkdir -p $(LIBFT_OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< $(addprefix -I.,$(addprefix $(PRINTF_PATH),$(PRINTF_INCS))) -o $@
clean:
	@$(RM) $(OBJS_DIR)

fclean: clean
	@$(RM) $(NAME)
	
re: fclean all
