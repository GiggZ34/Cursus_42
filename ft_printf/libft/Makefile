# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grivalan <grivalan@studen.42lyon.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/24 18:59:35 by grivalan          #+#    #+#              #
#    Updated: 2020/12/17 10:32:28 by grivalan         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_calloc.c\
				ft_isalnum.c\
				ft_islower.c\
				ft_itoa.c\
				ft_lstclear.c\
				ft_lstmap.c\
				ft_memchr.c\
				ft_memset.c\
				ft_putstr_fd.c\
				ft_str_repeat.c\
				ft_strcpy.c\
				ft_strlcat.c\
				ft_strncmp.c\
				ft_substr.c\
				ft_abs.c\
				ft_char_to_str.c\
				ft_isalpha.c\
				ft_isprint.c\
				ft_itoa_base.c\
				ft_lstdelone.c\
				ft_lstnew.c\
				ft_memcmp.c\
				ft_putchar_fd.c\
				ft_putstr_repeat.c\
				ft_str_to_lower.c\
				ft_strcpypos.c\
				ft_strlcpy.c\
				ft_strnstr.c\
				ft_tolower.c\
				ft_atoi.c\
				ft_dechex.c\
				ft_isascii.c\
				ft_isupper.c\
				ft_lstadd_back.c\
				ft_lstiter.c\
				ft_lstsize.c\
				ft_memcpy.c\
				ft_putendl_fd.c\
				ft_split.c\
				ft_str_to_upper.c\
				ft_strdup.c\
				ft_strlen.c\
				ft_strrchr.c\
				ft_toupper.c\
				ft_bzero.c\
				ft_in_array.c\
				ft_isdigit.c\
				ft_iswhitespace.c\
				ft_lstadd_front.c\
				ft_lstlast.c\
				ft_memccpy.c\
				ft_memmove.c\
				ft_putnbr_fd.c\
				ft_str_pad.c\
				ft_strchr.c\
				ft_strjoin.c\
				ft_strmapi.c\
				ft_strtrim.c

INCLUDES	=	libft.h

OBJS		=	$(SRCS:.c=.o)

NAME		=	libft.a

CC			=	gcc

RM			=	rm -f

CFLAGS		=	-Wall -Werror -Wextra

%.o: %.c libft.h
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCLUDES)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

all:	$(NAME)

clean:
		${RM} $(OBJS) $(O_BONUS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

norme:
			@norminette $(SRCS) $(INCLUDES)
			@echo "\033[1;34mlibft\t\033[1;33mNorminette\t\033[0;32m[OK]\033[0m"

.PHONY:	all clean fclean re
