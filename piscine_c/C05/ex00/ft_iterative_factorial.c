/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 19:53:42 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/18 10:24:57 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int x;

	x = 1;
	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	while (nb > 0)
	{
		x *= nb;
		nb--;
	}
	return (x);
}
