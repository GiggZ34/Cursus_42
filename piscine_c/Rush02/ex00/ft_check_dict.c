/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dict.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 17:51:21 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/27 22:43:45 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	ft_check_lines(char *str, int nb_lines)
{
	while (nb_lines > 0)
	{
		while (*str >= '0' && *str <= '9')
			str++;
		while (*str == ' ' || (*str >= 9 && *str <= 13))
			str++;
		if (*str != ':')
			return (0);
		else
			str++;
		while (*str == ' ' || (*str >= 9 && *str <= 13))
			str++;
		while (*str > 31 && *str < 127)
			str++;
		if (*str != '\n')
			return (0);
		else
			while (*str == '\n')
			{
				str++;
				nb_lines--;
			}
	}
	return (1);
}

int	ft_check_error(char *name_file)
{
	char	c;
	int		dict;
	char	*str;
	int		i;
	int		nb_lines;

	i = 0;
	nb_lines = 0;
	if ((dict = open(name_file, O_RDONLY)) == -1)
		return (0);
	while (read(dict, &c, 1) > 0)
	{
		i++;
		if (c == '\n')
			nb_lines++;
	}
	close(dict);
	if ((dict = open(name_file, O_RDONLY)) == -1)
		return (0);
	str = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (read(dict, &c, 1))
		str[i++] = c;
	close(dict);
	return (ft_check_lines(str, nb_lines));
}
