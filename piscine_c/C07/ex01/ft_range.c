/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 17:54:30 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/24 14:51:39 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

int	ft_size_caculator(int min, int max)
{
	int size;

	size = max - min;
	return (size);
}

int	*ft_range(int min, int max)
{
	int	*str;
	int	size;
	int	i;

	if (min >= max)
		return (0);
	size = ft_size_caculator(min, max);
	if ((str = (malloc(sizeof(int) * size))) == NULL)
		return (0);
	i = 0;
	while (min < max && size != 0)
		str[i++] = min++;
	return (str);
}
