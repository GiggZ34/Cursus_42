/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_treatment.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@studen.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 17:13:14 by grivalan          #+#    #+#             */
/*   Updated: 2020/12/18 10:19:01 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char	*ft_address(char *s, t_opt *obj)
{
	char	*new_str;
	int		i;

	obj->size_print += 2;
	if (!(new_str = ft_calloc(sizeof(char), obj->size_print)))
		return (0);
	new_str[0] = '0';
	new_str[1] = 'x';
	i = 1;
	while (++i < (int)obj->size_print)
		new_str[i] = s[i - 2];
	free(s);
	return (new_str);
}

char		*ft_option_treatment(char *s, t_opt *obj)
{
	if (obj->precision == '.' && obj->size_precision >= 0)
	{
		if (ft_in_array(obj->var_type, "diuxXp") != -1)
		{
			if (!(s = ft_nbr_precision(s, obj)))
				return (0);
		}
		else if (obj->var_type == 's' && obj->size_precision >= 0
						&& obj->size_precision < obj->size_print)
		{
			if (!(s = ft_str_precision(s, obj)))
				return (0);
		}
	}
	if (obj->var_type == 'p' && !(s = ft_address(s, obj)))
		return (0);
	if (obj->size_print < ft_abs(obj->size_pad))
	{
		if (!(s = ft_printf_pad(s, obj)))
			return (0);
		obj->size_print = obj->size_pad;
	}
	return (s);
}
