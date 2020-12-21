/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@studen.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 17:07:31 by grivalan          #+#    #+#             */
/*   Updated: 2020/12/16 19:12:32 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	ft_free_content(void *content)
{
	t_opt	*obj;

	obj = content;
	if (obj)
	{
		if (obj->str)
			free(obj->str);
		free(obj);
	}
}

int			ft_exit(t_list **begin, int value)
{
	void	*del;

	del = &ft_free_content;
	ft_lstclear(begin, del);
	return (value);
}
