/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 20:58:08 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/21 11:30:23 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_program_name(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

int		main(int argc, char *argv[])
{
	(void)argc;
	ft_print_program_name(*argv);
}
