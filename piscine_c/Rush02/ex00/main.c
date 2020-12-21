/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 15:00:49 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/27 20:27:25 by vcini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int		main(int argc, char *argv[])
{
	if (argc == 2)
	{
		argv++;
		if (!ft_check_number(*argv))
			return (0);
		ft_process(*argv, "numbers.dict");
	}
	else if (argc == 3)
	{
		argv++;
		if (!ft_check_number(argv[1]))
			return (0);
		if (!ft_check_error(argv[0]))
		{
			write(1, "Dict Error\n", 11);
			return (0);
		}
		ft_process(argv[1], argv[0]);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
