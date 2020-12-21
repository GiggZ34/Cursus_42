# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcini <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/26 14:54:58 by vcini             #+#    #+#              #
#    Updated: 2020/09/27 20:53:22 by vcini            ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC = GCC

CFLAGS = -Wall -Wextra -Werror

NAME = rush-02

SRC = ft_check_dict.c\
	  ft_dict_generator.c\
	  ft_error.c\
	  ft_ft.c\
	  ft_process.c\
	  tab_nbr.c\
	  main.c

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)
