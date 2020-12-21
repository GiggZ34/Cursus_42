/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 20:21:26 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/16 14:15:14 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int i;
	int x;

	i = 0;
	x = 1;
	if (power < 0)
		return (0);
	while (power > i++)
		x = x * nb;
	return (x);
}
