/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 23:10:07 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/24 11:58:29 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

void	ft_swap(char **str, int i, int j)
{
	char *tmp;

	tmp = str[i];
	str[i] = str[j];
	str[j] = tmp;
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort(char **str)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_strcmp(str[i], str[j]) > 0)
				ft_swap(str, i, j);
			j++;
		}
		i++;
	}
}

int		main(int argc, char *argv[])
{
	(void)argc;
	argv++;
	ft_sort(argv);
	while (*argv)
	{
		ft_putchar(*argv);
		argv++;
	}
	return (0);
}
