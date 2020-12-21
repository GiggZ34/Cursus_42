/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@studen.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:40:56 by grivalan          #+#    #+#             */
/*   Updated: 2020/12/18 09:54:27 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct	s_opt
{
	char	*str;
	char	var_type;
	int		size_print;
	char	pad_sign;
	char	pad_direction;
	char	pad_char;
	int		size_pad;
	char	precision;
	int		size_precision;
}				t_opt;
int				ft_printf(const char *s, ...) __attribute__
						((format(printf,1,2)));
int				ft_opt_parser(char *s, va_list args, t_opt *option);
char			*ft_init_var(va_list args, t_opt *option);
char			*ft_option_treatment(char *s, t_opt *obj);
char			*ft_nbr_precision(char *s, t_opt *obj);
char			*ft_str_precision(char *s, t_opt *obj);
char			*ft_printf_pad(char *src, t_opt *obj);
int				ft_print_lst(t_list *lst);
int				ft_exit(t_list **begin, int value);

#endif
