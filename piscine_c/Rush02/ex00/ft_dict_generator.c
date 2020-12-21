/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 13:17:42 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/27 20:25:56 by vcini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

char	*dict_generator(char *name_file)
{
	int		file;
	char	*str;
	char	c;
	int		i;
	int		compt_char;

	file = open(name_file, O_RDONLY);
	compt_char = 0;
	while (read(file, &c, 1) > 0)
		compt_char++;
	close(file);
	str = malloc(sizeof(char) * (compt_char + 1));
	file = open(name_file, O_RDONLY);
	i = 0;
	while (read(file, &c, 1) > 0)
	{
		if (c != ' ' || (c == ' ' && (str[i - 1] >= 'a' && str[i - 1] <= 'z')))
			str[i++] = c;
	}
	str[i] = '\0';
	close(file);
	return (str);
}
