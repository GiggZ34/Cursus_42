# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grivalan <grivalan@studen.42lyon.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/24 18:59:35 by grivalan          #+#    #+#              #
#    Updated: 2020/12/21 13:11:05 by grivalan         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME =		libftprintf.a

LIB  =		./lib

SRCS =		src/ft_option_treatment.c\
			src/ft_printf.c\
			src/ft_printf_error.c\
			src/ft_printf_init_var.c\
			src/ft_printf_lst_display.c\
			src/ft_printf_padding.c\
			src/ft_printf_parser.c\
			src/ft_printf_precision.c

CC = gcc

FLAGS =		-Wall -Wextra -Werror

INCLUDES =	./inc

OBJS =		$(SRCS:.c=.o)

%.o: %.c inc/ft_printf.h
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCLUDES)

$(NAME):	$(OBJS)
			$(MAKE) -C ./libft
			cp libft/libft.a $(NAME)
			ar -rcs $(NAME) $(OBJS)

all :		$(NAME)

clean :
		rm -rf $(OBJS)
		$(MAKE) clean -C ./libft

fclean :	clean
			$(MAKE) fclean -C ./libft
			rm -rf $(NAME)

re : fclean all

norme:
			@norminette $(SRCS) $(INCLUDES)
			@echo "\033[1;34mft_printf\t\033[1;33mNorminette\t\033[0;32m[OK]\033[0m"
			$(MAKE) norme -C ./libft

.PHONY : re all clean fclean norme
