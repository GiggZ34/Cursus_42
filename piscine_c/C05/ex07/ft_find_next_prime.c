/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 18:05:22 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/20 19:30:14 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_s_prime(int nb)
{
	int i;

	i = 2;
	if (nb < 2)
		return (0);
	while (i * i <= nb && i < 46340)
	{
		if (nb % i == 0)
			return (0);
		if (i % 2 == 0)
			i++;
		else
			i += 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 3)
		return (2);
	while (!ft_s_prime(nb))
		if (nb % 2 == 0)
			nb++;
		else
			nb += 2;
	return (nb);
}
