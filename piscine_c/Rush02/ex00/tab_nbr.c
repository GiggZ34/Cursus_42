/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 17:41:15 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/27 21:04:04 by vcini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

char	*ft_generate_thousand(int size, int *w_nbr)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * (size + 1));
	str[size - 1] = ':';
	str[size] = '\0';
	str[0] = '1';
	i = 1;
	while (i < size - 1)
		str[i++] = '0';
	*w_nbr = 0;
	return (str);
}

void	ft_units(int *id, int i, char **tab, char *nbr)
{
	if ((ft_strlen(nbr) - i) % 3 == 1)
	{
		tab[*id] = malloc(sizeof(char) * (2 + 1));
		tab[*id][1] = ':';
		tab[*id][2] = '\0';
		tab[*id][0] = nbr[i];
		*id += 1;
	}
}

void	ft_ten(int *id, int *i, char **tab, char *nbr)
{
	if ((ft_strlen(nbr) - *i) % 3 == 2)
	{
		tab[*id] = malloc(sizeof(char) * (3 + 1));
		tab[*id][3] = '\0';
		tab[*id][2] = ':';
		tab[*id][0] = nbr[*i];
		if (nbr[*i] == '1')
		{
			*i += 1;
			tab[*id][1] = nbr[*i];
		}
		else
			tab[*id][1] = '0';
		*id += 1;
	}
}

void	ft_hundreds(int *id, int i, char **tab, char *nbr)
{
	if ((ft_strlen(nbr) - i) % 3 == 0)
	{
		tab[*id] = malloc(sizeof(char) * 3);
		tab[*id][0] = nbr[i];
		tab[*id][1] = ':';
		tab[*id][2] = '\0';
		if (i < ft_strlen(nbr) - 1)
		{
			*id += 1;
			tab[*id] = malloc(sizeof(char) * 5);
			tab[*id] = "100:\0";
		}
		*id += 1;
	}
}

char	**ft_tab_nbr(char *nbr)
{
	char	**tab;
	int		i;
	int		id;
	int		w_nbr;

	tab = malloc(sizeof(char *) * (ft_strlen(nbr) * 2 + 1));
	i = 0;
	id = 0;
	w_nbr = 0;
	while (nbr[i])
	{
		if (nbr[i] > '0')
		{
			w_nbr = 1;
			ft_units(&id, i, tab, nbr);
			ft_ten(&id, &i, tab, nbr);
			ft_hundreds(&id, i, tab, nbr);
		}
		i++;
		if ((ft_strlen(nbr) - i) % 3 == 0 && w_nbr && i < ft_strlen(nbr) - 1)
			tab[id++] = ft_generate_thousand(ft_strlen(nbr) - i + 2, &w_nbr);
	}
	tab[id] = 0;
	return (tab);
}
