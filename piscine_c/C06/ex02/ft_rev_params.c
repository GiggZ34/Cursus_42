/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 22:39:09 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/24 10:16:33 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

int		main(int argc, char *argv[])
{
	int i;

	i = 0;
	argv++;
	while (argc > 1)
	{
		ft_putchar(argv[argc - 2]);
		argc--;
	}
}
