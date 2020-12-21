/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin_save.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 12:41:08 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/30 21:29:34 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_strcpy(char *a, char *b)
{
	int i;

	i = 0;
	while (a[i])
	{
		b[i] = a[i];
		i++;
	}
	b[i] = '\0';
	return (b);
}

char	*ft_realloc(char *tab, int *len, int buff)
{
	char *new_tab;

	if (!(new_tab = (char *)malloc(sizeof(char) * (buff + *len + 1))))
		return (0);
	new_tab = ft_strcpy(tab, new_tab);
	free(tab);
	return (new_tab);
}

char	*ft_stdin_save(void)
{
	char		*map;
	char		buff[60000];
	int			len;
	int			n_bytes;
	int			nb;

	n_bytes = 59999;
	len = 0;
	if ((map = (char *)malloc(sizeof(char) * (n_bytes + 1))) == NULL)
		return (0);
	while ((nb = read(0, buff, n_bytes)) > 0)
	{
		buff[nb] = '\0';
		map = ft_cat(map, buff, &len);
		map = ft_realloc(map, &len, n_bytes);
		map[len] = '\0';
	}
	return (map);
}
