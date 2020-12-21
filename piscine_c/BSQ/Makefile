# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbillon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/28 10:08:28 by tbillon           #+#    #+#              #
#    Updated: 2020/09/30 09:40:27 by grivalan         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

-include sources.mk

NAME = BSQ

OBJS = $(SOURCES:.c=.o)

CFLAGS = -g -Wall -Werror -Wextra -O3 -I includes

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

re: fclean all

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

gmk:
	./scripts/generate-mk.sh

.PHONY:	all clean fclean re

