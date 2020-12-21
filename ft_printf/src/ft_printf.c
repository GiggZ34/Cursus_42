/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@studen.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:40:54 by grivalan          #+#    #+#             */
/*   Updated: 2020/12/17 18:32:27 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static t_opt	*ft_init_obj(t_list **begin)
{
	t_list	*current;
	t_opt	*obj;

	if (!(current = malloc(sizeof(t_list))))
		return (0);
	if (!(obj = malloc(sizeof(t_opt))))
		return (0);
	current->next = 0;
	current->content = obj;
	obj->var_type = '\0';
	obj->size_pad = 0;
	obj->pad_char = ' ';
	obj->precision = '\0';
	obj->size_precision = 0;
	obj->pad_direction = 'l';
	ft_lstadd_back(begin, current);
	return (obj);
}

static int		ft_count_char(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '%')
		i++;
	return (i);
}

static int		ft_create_obj_str(char *str, int *i, t_opt *obj)
{
	obj->size_print = ft_count_char(&str[*i]);
	if (!(obj->str = malloc(sizeof(char) * (obj->size_print + 1))))
		return (0);
	ft_strlcpy(obj->str, &str[*i], obj->size_print + 1);
	*i += obj->size_print;
	return (1);
}

static int		ft_create_obj_var(char *str, int *i, t_opt *obj, va_list args)
{
	*i += ft_opt_parser(&str[*i], args, obj);
	if (!(obj->str = ft_init_var(args, obj)))
		return (0);
	if (obj->var_type == 'c')
		obj->size_print = 1;
	else
		obj->size_print = ft_strlen(obj->str);
	if (!(obj->str = ft_option_treatment(obj->str, obj)))
		return (0);
	return (1);
}

int				ft_printf(const char *s, ...)
{
	int		i;
	va_list	args;
	t_list	*begin;
	t_opt	*obj;
	char	*str;

	va_start(args, s);
	i = 0;
	str = (char*)s;
	begin = 0;
	while (str[i])
	{
		if (!(obj = ft_init_obj(&begin)))
			return (ft_exit(&begin, -1));
		if (str[i] != '%')
		{
			if (!ft_create_obj_str(str, &i, obj))
				return (ft_exit(&begin, -1));
		}
		else if (str[i++] == '%')
			if (!ft_create_obj_var(str, &i, obj, args))
				return (ft_exit(&begin, -1));
	}
	va_end(args);
	return (ft_print_lst(begin));
}
