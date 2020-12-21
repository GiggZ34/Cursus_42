/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 09:59:09 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/09 21:45:13 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_xyz(char z, char y, char x)
{
	write(1, &z, 1);
	write(1, &y, 1);
	write(1, &x, 1);
	if (z < '7' || y < '8' || x < '9')
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	char x;
	char y;
	char z;

	z = '0';
	y = '1';
	x = '2';
	while (z <= '7')
	{
		write_xyz(z, y, x);
		x++;
		if (x > '9')
		{
			y++;
			x = y + 1;
		}
		if (y > '8')
		{
			z++;
			y = z + 1;
			x = y + 1;
		}
	}
}
