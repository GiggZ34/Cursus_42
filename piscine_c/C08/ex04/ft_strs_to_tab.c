/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 10:43:39 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/25 11:46:50 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *str)
{
	char *new_str;
	int len_str;
	int i;

	len_str = ft_strlen(str);
	if ((new_str = malloc(sizeof(char) * (len_str + 1))) == NULL)
		return (0);
	new_str[len_str] = '\0';
	i = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	return (new_str);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str *strs;
	int i;

	if ((strs = malloc(sizeof(t_stock_str) * (ac + 1))) == NULL)
		return (0);
	i = 0;
	while (av[i])
	{
		strs[i].size = ft_strlen(av[i]);
		strs[i].str = av[i];
		strs[i].copy = ft_strcpy(av[i]);
		i++;
	}
	strs[i].size = 0;
	strs[i].str = 0;
	strs[i].copy = 0;
	return (strs);
}
