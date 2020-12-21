/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:18:50 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/30 22:01:35 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "bsq.h"

int		ft_check_backtracking(char **tab, int *coord, int width)
{
	int i;
	int j;
	int x_max;
	int y_max;

	x_max = coord[0] + width;
	y_max = coord[1] + width;
	j = coord[1];
	while (j <= y_max)
	{
		i = coord[0];
		while (i <= x_max)
		{
			if (tab[j][i] != '.')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int		ft_backtracking(char **tab, int *coord, int width, int *id_ret)
{
	if (ft_check_backtracking(tab, coord, width))
		ft_backtracking(tab, coord, width + 1, id_ret);
	else
	{
		if (width > id_ret[2])
		{
			id_ret[0] = coord[0];
			id_ret[1] = coord[1];
			id_ret[2] = width;
		}
		return (width);
	}
	return (0);
}

void	ft_scan_tab(char **tab, int *id_square, int nb_chars, int nb_lines)
{
	int coord[2];

	coord[1] = 0;
	while (coord[1] < nb_lines)
	{
		coord[0] = 0;
		while (coord[0] < nb_chars)
		{
			coord[0] += ft_backtracking(tab, coord, 0, id_square) + 1;
		}
		coord[1]++;
	}
}

int		ft_process(char *in)
{
	char	**tab;
	int		nb_lines;
	int		nb_chars;
	int		id_square[3];

	id_square[0] = 0;
	id_square[1] = 0;
	id_square[2] = 0;
	nb_chars = 0;
	nb_lines = 0;
	tab = ft_file_to_tab(in, &nb_lines, &nb_chars);
	printf("%s\n", tab[0]);
	nb_lines--;
	ft_scan_tab(&tab[1], id_square, nb_chars, nb_lines);
	recreate_map(&tab[1], id_square);
	display_map(tab, nb_chars);
	return (1);
}
