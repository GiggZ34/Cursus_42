/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 12:01:46 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/25 12:45:24 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_putnbr_base(long int nbr, char *base);
int		ft_size_str(long int nbr, char *base);

int		ft_in_base(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int		ft_len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_ck_base(char *base)
{
	int i;

	if (ft_len(base) < 2)
		return (0);
	while (*base)
	{
		i = 1;
		if (*base == '-' || *base == '+' || (*base >= 9 && *base <= 13))
			return (0);
		else
			while (base[i])
				if (*base == base[i++])
					return (0);
		base++;
	}
	return (1);
}

int		ft_atoi_base(char *nbr, char *base)
{
	int			neg;
	long int	result;
	int			id;
	int			nb_base;

	result = 0;
	neg = 1;
	id = 0;
	nb_base = ft_len(base);
	while ((*nbr >= 9 && *nbr <= 13) || *nbr == ' ')
		nbr++;
	while (*nbr == '+' || *nbr == '-')
	{
		if (*nbr == '-')
			neg *= -1;
		nbr++;
	}
	while ((id = ft_in_base(base, *nbr)) >= 0)
	{
		result = result * nb_base + id;
		nbr++;
	}
	return (result * neg);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long int	number;
	char		*str;
	int			size_tab;

	if (!ft_ck_base(base_from) || !ft_ck_base(base_to))
		return (NULL);
	number = ft_atoi_base(nbr, base_from);
	if (number == 0)
		size_tab = 1;
	else
		size_tab = ft_size_str(number, base_to);
	str = malloc(sizeof(char) * size_tab);
	if (number == 0)
	{
		str[0] = base_to[0];
		str[1] = '\0';
		return (str);
	}
	else
		str = ft_putnbr_base(number, base_to);
	return (str);
}
