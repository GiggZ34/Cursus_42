/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 20:31:36 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/24 14:51:58 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_srlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_count(char **strs, int size)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (i < size)
	{
		len += ft_srlen(strs[i]);
		i++;
	}
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		i;
	int		j;
	int		k;
	int		len;

	i = -1;
	k = 0;
	len = ft_count(strs, size) + ft_srlen(sep) * (size - 1);
	if (len < 0)
		len = 0;
	if ((str = (malloc(sizeof(char) * len + 1))) == NULL)
		return (0);
	str[len] = '\0';
	while (++i < size)
	{
		j = 0;
		while (strs[i][j])
			str[k++] = strs[i][j++];
		j = 0;
		if (i < size - 1)
			while (sep[j])
				str[k++] = sep[j++];
	}
	return (str);
}
