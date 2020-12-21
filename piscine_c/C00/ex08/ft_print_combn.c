/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 18:43:38 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/09 18:56:28 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn(int n)
{
	int max_nb;

	max_nb = 1;
	while (n > 0)
	{
		max_nb = max_nb * 10;
		n--;
	}
	create_nb(max_nb);
}

void 	create_nb(int max_nb)
{
	int i;

	while (i < max_nb)
	{
		search_char(i, max_nb/10);
		i++;
	}
}

void	search_char(int n, int div)
{
	if (n > 9)
		search_char(n / 10);
	rprint(48 + n % 10);
}

void	rprint(int c)
{
	write(1, &c, 1);
}
