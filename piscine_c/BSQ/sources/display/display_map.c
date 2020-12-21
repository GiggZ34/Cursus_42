/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 17:45:57 by tbillon           #+#    #+#             */
/*   Updated: 2020/09/30 19:26:45 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	free_me(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		if (map[i] != 0)
			free(map[i]);
		i++;
	}
	free(map);
}

void	display_map(char **map, int nb_chars)
{
	int y;

	y = 1;
	while (map[y])
	{
		write(1, map[y], nb_chars);
		ft_putchar('\n');
		y++;
	}
	free_me(map);
}
