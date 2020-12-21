/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 00:45:01 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/27 22:19:52 by vcini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int		ft_check_str(char *str)
{
	while (*str)
	{
		if (*str > 32 && *str < 127)
			return (1);
	}
	return (0);
}

char	*ft_ignore_white_space(char *str)
{
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	return (str);
}

char	**ft_zero(void)
{
	char **tab;

	tab = malloc(sizeof(char*) * 2);
	tab[0] = malloc(sizeof(char) * 3);
	tab[0] = "0:\0";
	tab[1] = 0;
	return (tab);
}

void	ft_free(char **exit, char *file)
{
	free(exit);
	free(file);
}

void	**ft_process(char *nbr, char *name_file)
{
	char	*file;
	char	**tab_nbr;
	char	*test;
	char	**exit;
	int		i;

	file = dict_generator(name_file);
	tab_nbr = !ft_zero_only(nbr) ? ft_tab_nbr(nbr) : ft_zero();
	exit = malloc(sizeof(char*) * (ft_count_tab(tab_nbr) + 1));
	exit[ft_count_tab(tab_nbr)] = 0;
	i = 0;
	while (*tab_nbr)
	{
		if ((test = ft_strstr(file, *tab_nbr)) == 0)
		{
			write(1, "Dict Error\n", 11);
			return (0);
		}
		test = ft_ignore_white_space(test);
		exit[i++] = test;
		tab_nbr++;
	}
	ft_print(exit);
	ft_free(exit, file);
	return (0);
}
