/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 22:41:39 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/14 23:16:46 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *find)
{
	int len;

	len = ft_strlen(find);
	while(*str)
	{
		if (str[0 ... len] == find)
			return (str);
		str++;
	}
}

int		main()
{
	printf("%s\n", ft_strstr("Hello World!","llo"));
}	
