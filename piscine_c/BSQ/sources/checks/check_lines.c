/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:53:00 by tbillon           #+#    #+#             */
/*   Updated: 2020/09/29 18:59:13 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		check_line_len(char **map)
{
	int i;
	int line_len;

	i = 1;
	line_len = ft_strlen(map[1]);
	if (ft_strlen(map[0]) < 4)
		return (0);
	if (line_len < 1)
		return (0);
	while (map[i])
	{
		if (line_len != ft_strlen(map[i]))
			return (0);
		i++;
	}
	return (1);
}

int		check_lines_nb(char **map)
{
	char	*params;
	int		nb_lines;
	int		i;

	params = cat_first_params(map);
	nb_lines = ft_atoi(params);
	i = 0;
	while (map[i])
		i++;
	if (i != nb_lines)
		return (0);
	return (1);
}
