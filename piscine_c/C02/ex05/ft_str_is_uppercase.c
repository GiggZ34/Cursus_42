/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 13:14:55 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/11 13:22:55 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int i;
	int is_upper;

	is_upper = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 65 || str[i] > 90)
			is_upper = 0;
		i++;
	}
	return (is_upper);
}
