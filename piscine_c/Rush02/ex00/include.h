/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcini <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 16:21:34 by vcini             #+#    #+#             */
/*   Updated: 2020/09/27 21:18:48 by vcini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H

# define INCLUDE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

int		ft_check_lines(char *str, int nb_lines);
int		ft_check_error(char *name_file);
int		ft_check_number(char *nbr);
int		ft_strlen(char *str);
int		ft_count_tab(char **tab);
int		ft_zero_only(char *str);
int		ft_check_str(char *str);
int		main(int argc, char *argv[]);

char	*dict_generator(char *name_file);
char	*ft_strstr(char *str, char *find);
char	*ft_ignore_white_space(char *str);
char	**ft_zero(void);
char	*ft_generate_thousand(int size, int *w_nbr);
char	**ft_tab_nbr(char *nbr);

void	ft_print(char **tab);
void	**ft_process(char *nbr, char *name_file);
void	ft_units(int *id, int i, char **tab, char *nbr);
void	ft_ten(int *id, int *i, char **tab, char *nbr);
void	ft_hundreds(int *id, int i, char **tab, char *nbr);
void	ft_free(char **tab_nbr, char *file);

#endif
