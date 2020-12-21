/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 14:49:44 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/18 16:35:31 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

long int	ft_div(long int nbr)
{
	long int tmp;

	tmp = nbr / 2;
	while (tmp / 2 * tmp / 2 >= nbr)
	{
		tmp /= 2;
	}
	return (tmp);
}

int			ft_sqrt(int nb)
{
	long int i;

	nb = (long int)nb;
	if (nb == 1)
		return (1);
	else if (nb <= 0)
		return (0);
	i = ft_div(nb);
	while (i * i >= nb)
	{
		if (i * i == nb)
			return ((int)i);
		i--;
	}
	return (0);
}
