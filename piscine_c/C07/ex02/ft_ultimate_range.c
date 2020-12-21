/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 20:12:02 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/27 14:58:47 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int *tab_range;
	int i;
	int len;

	len = max - min;
	if (max <= min)
	{
		*range = 0;
		return (0);
	}
	i = 0;
	if ((tab_range = malloc(sizeof(int) * len)) == NULL)
		return (-1);
	while (min < max)
		tab_range[i++] = min++;
	*range = tab_range;
	return (len);
}
