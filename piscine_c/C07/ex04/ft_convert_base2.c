/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 12:01:59 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/25 12:45:19 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_len(char *str);

int		ft_size_str(long int nb, char *base)
{
	int i;
	int nb_base;

	nb_base = ft_len(base);
	i = 0;
	if (nb < 0)
		i++;
	while (nb != 0)
	{
		nb /= nb_base;
		i++;
	}
	return (i);
}

void	ft_create_num_tab(long int nbr, char *base, int i, char *str)
{
	if (nbr >= ft_len(base))
		ft_create_num_tab(nbr / ft_len(base), base, i - 1, str);
	str[i] = base[nbr % ft_len(base)];
}

char	*ft_putnbr_base(long int nbr, char *base)
{
	char	*str;
	int		i;
	int		base_size;

	base_size = ft_size_str(nbr, base);
	str = malloc(sizeof(char) * base_size + 1);
	str[base_size] = '\0';
	i = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		str[i] = '-';
	}
	i = base_size - 1;
	ft_create_num_tab(nbr, base, i, str);
	return (str);
}
