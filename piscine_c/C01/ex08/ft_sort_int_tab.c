/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 17:55:28 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/11 09:55:34 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (i++ < size - 1)
	{
		while (++j < size)
		{
			if (tab[i] > tab[j])
				ft_swap(&tab[i], &tab[j]);
		}
		j = i + 1;
	}
}
