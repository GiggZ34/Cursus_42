# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grivalan <grivalan@studen.42lyon.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/24 18:59:35 by grivalan          #+#    #+#              #
#    Updated: 2020/12/16 16:48:17 by grivalan         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_bzero.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_memccpy.c \
				ft_memcmp.c \
				ft_memmove.c \
				ft_split.c \
				ft_strdup.c \
				ft_strlcat.c \
				ft_strlen.c \
				ft_strncmp.c \
				ft_strrchr.c \
				ft_substr.c \
				ft_toupper.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_itoa.c \
				ft_memchr.c \
				ft_memcpy.c \
				ft_memset.c \
				ft_strchr.c \
				ft_strjoin.c \
				ft_strlcpy.c \
				ft_strmapi.c \
				ft_strnstr.c \
				ft_strtrim.c \
				ft_tolower.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_lstnew.c \
				ft_lstadd_front.c

BONUS_SRCS	=	ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c

O_BONUS		=	$(BONUS_SRCS:.c=.o)

OBJS		=	$(SRCS:.c=.o)

NAME		=	libft.a

CC			=	gcc

RM			=	rm -f

CFLAGS		=	-Wall -Werror -Wextra

%.o: %.c libft.h
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCS)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

all:	$(NAME)

bonus:	$(OBJS) $(O_BONUS)
		ar rcs $(NAME) $(OBJS) $(O_BONUS)

clean:
		${RM} $(OBJS) $(O_BONUS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

norme:		norminette CheckHeaderForbidenSource$(SRCS);

.PHONY:	all clean fclean re bonus
