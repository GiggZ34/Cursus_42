/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ckeck_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:58:48 by tbillon           #+#    #+#             */
/*   Updated: 2020/09/29 17:59:53 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		is_in_params(char c, char *params)
{
	int i;

	i = 0;
	while (params[i])
	{
		if (c == params[i])
			return (1);
		i++;
	}
	return (0);
}

int		check_params_in_map(char **map)
{
	int		i;
	int		j;
	char	*params;

	params = map[0];
	i = 1;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (!(is_in_params(map[i][j], params) == 1))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int		check_valid_params(char **map)
{
	int		i;
	char	*params;
	int		len;

	params = map[0];
	len = ft_strlen(params);
	i = len - 3;
	if (!(params[i] != params[i + 1] &&
			params[i] != params[i + 2] &&
			params[i + 1] != params[i + 2]))
		return (0);
	while (params[i])
	{
		if (!(params[i] >= 32 && params[i] <= 126))
			return (0);
		i++;
	}
	i = 0;
	while (i < len - 3)
	{
		if (!(params[i] >= '0' && params[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}
