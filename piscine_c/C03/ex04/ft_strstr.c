/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 16:00:09 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/14 21:47:12 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
char	*ft_strstr(char *str, char *to_find)
{
	int a;

	if (to_find[0] == '\0')
		return (str);
	while (*str)
	{
		if (*str == *to_find)
		{
			a = 0;
			while (str[a] == to_find[a])
				if (to_find[++a] == '\0')
					return (str);
		}
		str++;
	}
	return (0);
}

int			main()
{
	printf("%s",ft_strstr("Hello Worlz World! oo", "World"));
	printf("%s",strstr("Hello Worlz World! oo","World"));
}
