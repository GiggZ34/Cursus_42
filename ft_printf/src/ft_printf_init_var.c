/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_init_var.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@studen.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 17:29:00 by grivalan          #+#    #+#             */
/*   Updated: 2020/12/18 10:22:17 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_init_var(va_list args, t_opt *option)
{
	char *str;

	if (ft_in_array(option->var_type, "idupxX") != -1)
		if (option->precision == '.' && option->size_precision >= 0)
			option->pad_char = ' ';
	if (option->var_type == 's')
	{
		if (!(str = va_arg(args, char*)))
			str = "(null)";
		return (ft_strdup(str));
	}
	else if (option->var_type == 'i' || option->var_type == 'd')
		return (ft_itoa(va_arg(args, int)));
	else if (option->var_type == 'u')
		return (ft_itoa(va_arg(args, unsigned int)));
	else if (option->var_type == 'x')
		return (ft_dechex(va_arg(args, unsigned int)));
	else if (option->var_type == 'X')
		return (ft_str_to_upper(ft_dechex(va_arg(args, unsigned int))));
	else if (option->var_type == 'p')
		return (ft_dechex(va_arg(args, unsigned long)));
	else if (option->var_type == 'c')
		return (ft_char_to_str((char)va_arg(args, int)));
	return (ft_char_to_str(option->var_type));
}
