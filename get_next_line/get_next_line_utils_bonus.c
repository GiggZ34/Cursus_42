/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@studen.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:08:47 by grivalan          #+#    #+#             */
/*   Updated: 2020/12/21 09:18:12 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_strlen(const char *s)
{
	int i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc(int count, int size)
{
	char	*tab;
	int		i;

	if ((tab = malloc(size * count)) == NULL)
		return (0);
	i = 0;
	while (i < count * size)
		tab[i++] = 0;
	return (tab);
}

char	*ft_realloc(char *str, unsigned int size)
{
	int		len;
	char	*new_str;
	int		i;

	len = ft_strlen(str) + size + 1;
	if (!(new_str = ft_calloc(sizeof(char), len)))
		return (0);
	if (str)
	{
		i = -1;
		while (str[++i])
			new_str[i] = str[i];
		free(str);
	}
	return (new_str);
}

char	*ft_substr(char const *s, unsigned int start, int len)
{
	char	*new_str;
	int		i;

	if (!s)
		return (0);
	if ((new_str = ft_calloc(sizeof(char), len + 1)) == NULL)
		return (0);
	i = 0;
	while (start + i < start + len)
	{
		new_str[i] = s[start + i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

int		ft_strpos(const char *s, char c)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}
