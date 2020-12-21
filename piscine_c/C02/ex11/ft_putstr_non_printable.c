/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 17:10:08 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/14 20:55:39 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_printf(char c)
{
	write(1, &c, 1);
}

void	ft_dec_to_hex(unsigned char ascii_dec)
{
	char *hexa;

	hexa = "0123456789abcdef";
	ft_printf(hexa[ascii_dec / 16]);
	ft_printf(hexa[ascii_dec % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] < ' ' || str[i] == 127)
		{
			ft_printf('\\');
			ft_dec_to_hex((unsigned char)str[i]);
		}
		else
			ft_printf(str[i]);
		i++;
	}
}
