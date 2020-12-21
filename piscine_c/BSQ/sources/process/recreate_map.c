/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recreate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 19:12:28 by tbillon           #+#    #+#             */
/*   Updated: 2020/09/29 19:55:14 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	recreate_map(char **tab, int *coord)
{
	int i;
	int j;
	int x_max;
	int y_max;

	x_max = coord[0] + coord[2];
	y_max = coord[1] + coord[2];
	j = coord[1];
	while (j < y_max)
	{
		i = coord[0];
		while (i < x_max)
		{
			if (tab[j][i] == '.')
				tab[j][i] = 'X';
			i++;
		}
		j++;
	}
}
