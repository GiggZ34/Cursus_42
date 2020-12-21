/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 13:32:24 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/17 13:20:41 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_len(char *base)
{
	unsigned int i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int		ft_check_base(char *base)
{
	unsigned int i;

	if (ft_len(base) < 2)
		return (0);
	while (*base)
	{
		i = 1;
		if (*base == '-' || *base == '+')
			return (0);
		else
			while (base[i])
				if (*base == base[i++])
					return (0);
		base++;
	}
	return (1);
}

void	ft_convert_base(unsigned int nbr, char *base, unsigned int div_base)
{
	if (nbr > div_base)
		ft_convert_base(nbr / div_base, base, div_base);
	ft_putchar(base[nbr % div_base]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (ft_check_base(base) == 1)
	{
		if (nbr < 0)
			ft_putchar('-');
		ft_convert_base((unsigned int)nbr, base, ft_len(base));
	}
	else
		return ;
}
