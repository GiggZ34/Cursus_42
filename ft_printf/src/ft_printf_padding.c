/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_padding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@studen.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:32:47 by grivalan          #+#    #+#             */
/*   Updated: 2020/12/18 10:21:00 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	ft_def_direction(t_opt *obj)
{
	if (obj->size_pad < 0)
	{
		obj->size_pad *= -1;
		obj->pad_char = ' ';
		if (obj->pad_direction == 'r')
			obj->pad_direction = 'l';
	}
}

static char	*ft_strcpypad(char *dst, char *src, t_opt *obj, int position)
{
	int i;

	i = -1;
	while (++i < (int)obj->size_print)
		dst[position + i] = src[i];
	return (dst);
}

static char	*ft_set_pad(char *src, t_opt *obj)
{
	char	*new_str;
	int		position;

	if (!(new_str = malloc(sizeof(char) * obj->size_pad)))
		return (0);
	ft_memset(new_str, obj->pad_char, obj->size_pad);
	if (obj->pad_direction == 'r')
		position = obj->size_pad - obj->size_print;
	else
		position = 0;
	new_str = ft_strcpypad(new_str, src, obj, position);
	obj->size_print = obj->size_pad;
	return (new_str);
}

char		*ft_printf_pad(char *src, t_opt *obj)
{
	char	*new_str;
	int		position;
	char	neg;

	ft_def_direction(obj);
	if (!src)
		return (0);
	else if ((int)obj->size_print >= obj->size_pad)
		return (src);
	if (src[0] == '-' &&
		(obj->pad_char == '0' && ft_in_array(obj->var_type, "sc") == -1))
	{
		neg = '-';
		src[0] = '0';
	}
	if (!(new_str = ft_set_pad(src, obj)))
		return (0);
	if (neg == '-')
		new_str[0] = '-';
	free(src);
	return (new_str);
}
