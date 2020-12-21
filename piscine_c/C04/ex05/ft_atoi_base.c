/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 15:07:26 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/16 19:14:13 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_slen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_ck_base(char *base)
{
	int i;

	if (ft_slen(base) < 2)
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

int	ft_in_base(char *base, char c)
{
	int i;

	i = 0;
	while (base[i])
		if (c == base[i++])
			return (i - 1);
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int i;
	int neg;
	int result;

	if (ft_ck_base(base) == 1)
	{
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
		while (ft_in_base(base, str[i]) >= 0 && str[i])
			result = result * ft_slen(base) + ft_in_base(base, str[i++]);
		return (result * neg);
	}
	else
		return (0);
}
