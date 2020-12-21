/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat_first_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 14:48:53 by tbillon           #+#    #+#             */
/*   Updated: 2020/09/29 18:51:35 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*cat_first_params(char **map)
{
	int		i;
	char	*nb_line_param;
	char	*line;

	i = 0;
	line = map[i];
	if (!(nb_line_param = malloc(sizeof(char) * (ft_strlen(map[0]) + 1))))
		return (0);
	while (line[i] >= '0' && line[i] <= '9')
	{
		nb_line_param[i] = line[i];
		i++;
	}
	nb_line_param[i] = '\0';
	return (nb_line_param);
}
