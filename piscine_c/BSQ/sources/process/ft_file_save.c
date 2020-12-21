/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_save.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:06:54 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/30 22:03:49 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "bsq.h"

char	*ft_cat(char *dest, char *src, int *pos)
{
	int j;

	j = 0;
	while (src[j])
	{
		dest[*pos + j] = src[j];
		j++;
	}
	dest[*pos + j] = '\0';
	*pos = *pos + j;
	return (dest);
}

int		ft_len_file(char *name_file)
{
	int fd;
	int i;
	char c;

	i = 0;
	if ((fd = open(name_file, O_RDONLY)) == -1)
		return (0);
	while (read(fd, &c, 1))
		i++;
	close(fd);
	return (i);
}

char	*ft_file_save(char *name_file)
{
	char		*map;
	char		buff[60000];
	int			len;
	int			fd;
	int			nb;
	int			pos;

	pos = 0;
	len = ft_len_file(name_file);
	if ((fd = open(name_file, O_RDONLY)) == -1)
		return (0);
	if ((map = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (0);
	map[len] = '\0';
	while ((nb = read(fd, buff, 59999)) > 0)
	{
		buff[nb] = '\0';
		map = ft_cat(map, buff, &pos);
		printf("%d\n", pos);
	}
	close(fd);
	return (map);
}
