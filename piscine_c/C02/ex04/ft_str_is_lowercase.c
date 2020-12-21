/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 13:03:37 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/11 13:13:06 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int is_lower;
	int i;

	is_lower = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 97 || str[i] > 122)
			is_lower = 0;
		i++;
	}
	return (is_lower);
}
