/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 10:39:14 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/20 22:53:44 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int *numbers)
{
	char	c;
	int		i;

	i = 0;
	while (i < 10)
	{
		c = numbers[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int		ft_check_queens(int *queens, int id)
{
	int i;

	i = 1;
	while (id - i >= 0)
	{
		if (queens[id] == queens[id - i] ||
				queens[id] - i == queens[id - i] ||
				queens[id] + i == queens[id - i])
			return (0);
		i++;
	}
	return (1);
}

int		to_solve(int id_queen, int *queens, int resultat)
{
	int id_x;

	id_x = 0;
	while (id_x < 10)
	{
		queens[id_queen] = id_x;
		if (ft_check_queens(queens, id_queen))
		{
			if (id_queen < 9)
			{
				resultat = to_solve(id_queen + 1, queens, resultat);
			}
			else
			{
				resultat++;
				ft_print(queens);
			}
		}
		id_x++;
	}
	return (resultat);
}

int		ft_ten_queens_puzzle(void)
{
	int queens[10];
	int resultat;

	resultat = 0;
	resultat = to_solve(0, queens, resultat);
	return (resultat);
}

int		main()
{
	ft_ten_queens_puzzle();
}
