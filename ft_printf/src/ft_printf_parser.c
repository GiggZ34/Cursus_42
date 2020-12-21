/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@studen.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 17:04:31 by grivalan          #+#    #+#             */
/*   Updated: 2020/12/21 13:07:12 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	ft_init_pad(char c, t_opt *option)
{
	if (c == '.')
	{
		option->precision = '.';
		option->size_precision = 0;
	}
	else if (c == '-')
	{
		option->pad_sign = c;
		option->pad_direction = 'l';
		option->pad_char = ' ';
	}
	else if (c == '0' && option->pad_sign != '-')
	{
		option->pad_sign = c;
		option->pad_direction = 'r';
		option->pad_char = '0';
	}
	else if (c == '*' && option->pad_sign != '-'
				&& option->pad_sign != '0')
	{
		option->pad_sign = c;
		option->pad_direction = 'r';
		option->pad_char = ' ';
	}
}

static int	ft_require_size_opt(char *s, char c, t_opt *option, va_list args)
{
	int i;

	i = 0;
	if (ft_isdigit(s[i]))
	{
		if (c == '.')
			option->size_precision = ft_atoi(&s[i]);
		else
			option->size_pad = ft_atoi(&s[i]);
		while (ft_isdigit(s[i]))
			i++;
	}
	else if (s[i] == '*')
	{
		if (c == '.')
			option->size_precision = va_arg(args, int);
		else
			option->size_pad = va_arg(args, int);
		i++;
	}
	return (i);
}

int			ft_opt_parser(char *s, va_list args, t_opt *option)
{
	char	c;
	int		i;

	i = 0;
	while (ft_in_array((c = s[i]), "-0*.") != -1 || ft_isdigit(s[i]))
	{
		if (ft_isdigit(c) && c != '0')
			c = '*';
		ft_init_pad(c, option);
		if (c != '*')
			i++;
		i += ft_require_size_opt(&s[i], c, option, args);
	}
	option->var_type = c;
	return (i + 1);
}
