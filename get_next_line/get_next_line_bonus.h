/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@studen.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:08:50 by grivalan          #+#    #+#             */
/*   Updated: 2020/12/21 09:14:27 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct	s_fd
{
	int			fd;
	char		*buff;
	int			start;
	int			end;
	struct s_fd	*next;
}				t_fd;

int				get_next_line(int fd, char **line);
char			*ft_realloc(char *str, unsigned int size);
char			*ft_substr(char const *s, unsigned int start, int len);
int				ft_strlen(const char *s);
void			*ft_calloc(int count, int size);
int				ft_strpos(const char *s, char c);

#endif
