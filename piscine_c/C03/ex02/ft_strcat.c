/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 15:14:05 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/15 12:47:57 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (dest[i])
		i++;
	while (src[y])
		dest[i++] = src[y++];
	dest[i] = '\0';
	return (dest);
}
