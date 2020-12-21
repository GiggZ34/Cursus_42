/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 12:33:01 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/16 09:39:42 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_numeric(char *str)
{
	if (*str >= '0' && *str <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int i;
	int neg;
	int result;

	neg = 1;
	i = 0;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	while (ft_is_numeric(&str[i]) && str[i])
		result = result * 10 + (str[i++] - 48);
	return (result * neg);
}
