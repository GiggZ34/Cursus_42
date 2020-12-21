/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lst_display.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@studen.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 17:09:51 by grivalan          #+#    #+#             */
/*   Updated: 2020/12/18 10:33:00 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_print_lst(t_list *lst)
{
	t_list	*tmp;
	t_opt	*obj;
	int		len;

	len = 0;
	while (lst)
	{
		obj = lst->content;
		len += write(1, obj->str, obj->size_print);
		tmp = lst->next;
		free(obj->str);
		free(obj);
		free(lst);
		lst = tmp;
	}
	return (len);
}
