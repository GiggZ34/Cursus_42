/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 18:32:18 by tbillon           #+#    #+#             */
/*   Updated: 2020/09/29 18:29:11 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		is_map_valid(char **map)
{
	if (!(check_line_len(map)))
		if (print_error(0))
			return (0);
	if (!(check_lines_nb(map)))
		if (print_error(0))
			return (0);
	if (!(check_valid_params(map)))
		if (print_error(0))
			return (0);
	if (!(check_params_in_map(map)))
		if (print_error(0))
			return (0);
	return (1);
}
