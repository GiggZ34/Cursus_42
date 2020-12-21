/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 16:16:31 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/09 21:36:06 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	w_print(int i, int j)
{
	int a;
	int b;

	a = i / 10 + 48;
	b = i % 10 + 48;
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, " ", 1);
	a = j / 10 + 48;
	b = j % 10 + 48;
	write(1, &a, 1);
	write(1, &b, 1);
	if (i != 98 || j != 99)
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int i;
	int j;

	i = 0;
	j = i + 1;
	while (i < 99)
	{
		w_print(i, j);
		j++;
		if (j > 99)
		{
			i++;
			j = i + 1;
		}
	}
}
