/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 22:16:07 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/15 15:38:22 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	while (dest[i] && i < size)
		i++;
	if (size != 0 && dest[i] == '\0')
	{
		j = 0;
		while (src[j])
			dest[i++] = src[j++];
		if (i > size)
			dest[size - 1] = '\0';
		else
			dest[i] = '\0';
		return (i);
	}
		return (i + ft_strlen(src));
}
