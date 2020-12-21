/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 10:42:30 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/24 17:22:32 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H
# include <unistd.h>

typedef	int	t_bool;
# define EVEN_MSG "I have an even number of arguments."
# define ODD_MSG "I have an odd number of arguments."
# define TRUE 1
# define FALSE 0
# define SUCCESS FALSE
# define EVEN(nb) (nb%2 == 0)
#endif
