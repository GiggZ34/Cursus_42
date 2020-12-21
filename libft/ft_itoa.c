/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@studen.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:52:45 by grivalan          #+#    #+#             */
/*   Updated: 2020/11/27 10:22:26 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_nb_numbers(int n)
{
	int nb_numbers;

	nb_numbers = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		nb_numbers++;
	while (n != 0)
	{
		n /= 10;
		nb_numbers++;
	}
	return (nb_numbers);
}

static	void	ft_int_to_char(char *str, int id, int n)
{
	if (n > 9)
		ft_int_to_char(str, id - 1, n / 10);
	str[id] = n % 10 + 48;
}

char			*ft_itoa(int n)
{
	char	*result;
	int		nb_numbers;
	int		i;

	nb_numbers = ft_nb_numbers(n);
	if ((result = malloc(sizeof(char) * (nb_numbers + 1))) == NULL)
		return (0);
	result[nb_numbers] = '\0';
	i = nb_numbers - 1;
	if (n < 0)
	{
		result[0] = '-';
		if (n == -2147483648)
		{
			result[i] = '8';
			i--;
			n /= 10;
		}
		n *= -1;
	}
	ft_int_to_char(result, i, n);
	return (result);
}
