/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 14:34:40 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/27 20:26:25 by vcini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *find)
{
	int i;

	while (*str)
	{
		i = 0;
		while (str[i] == find[i])
			if (find[++i] == '\0')
				return (&str[i]);
		str++;
	}
	return (0);
}

int		ft_count_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int		ft_zero_only(char *str)
{
	while (*str)
	{
		if (*str != '0')
			return (0);
		str++;
	}
	return (1);
}

void	ft_print(char **tab)
{
	int i;
	int j;
	int len;

	len = ft_count_tab(tab);
	i = 0;
	while (tab[i] != 0)
	{
		j = 0;
		while (tab[i][j] != '\n')
		{
			write(1, &tab[i][j], 1);
			j++;
		}
		if (i < len - 1)
			write(1, " ", 1);
		else
			write(1, "\n", 1);
		i++;
	}
}
