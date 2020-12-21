/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@studen.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 15:49:00 by grivalan          #+#    #+#             */
/*   Updated: 2020/12/14 19:03:33 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_nbr_precision(char *s, t_opt *obj)
{
	char	*new_str;
	char	neg;
	int		i;

	neg = '0';
	i = (s[0] == '-') ? 1 : 0;
	if (obj->size_print == 1 && s[0] == '0' && obj->size_precision == 0)
	{
		obj->size_print = 0;
		s[0] = '\0';
		return (s);
	}
	if (obj->size_print - i >= obj->size_precision)
		return (s);
	if (s[0] == '-')
	{
		obj->size_precision++;
		s[0] = '0';
		neg = '-';
	}
	if (!(new_str = ft_str_pad(s, obj->size_precision, '0', 'r')))
		return (0);
	new_str[0] = neg;
	obj->size_print = obj->size_precision;
	return (new_str);
}

char	*ft_str_precision(char *s, t_opt *obj)
{
	char	*new_str;
	int		i;

	if (obj->size_precision >= (int)obj->size_print)
		return (s);
	if (!(new_str = malloc(sizeof(char) * obj->size_precision)))
		return (0);
	i = -1;
	while (++i < obj->size_precision)
		new_str[i] = s[i];
	obj->size_print = obj->size_precision;
	free(s);
	return (new_str);
}
