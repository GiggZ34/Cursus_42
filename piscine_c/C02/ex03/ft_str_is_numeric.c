/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 12:38:04 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/11 12:46:55 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int is_numeric;
	int i;

	is_numeric = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 48 || str[i] > 57)
			is_numeric = 0;
		i++;
	}
	return (is_numeric);
}
