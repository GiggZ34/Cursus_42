/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 10:59:27 by tbillon           #+#    #+#             */
/*   Updated: 2020/09/30 22:01:28 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

/*
** STR TOOLS
*/

void	ft_putchar(char c);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *str);
int		ft_atoi(char *str);
char	*cat_first_params(char **map);

/*
** CHECK MAPS
*/

int		is_in_params(char c, char *params);
int		check_params_in_map(char **map);
int		check_valid_params(char **map);
int		check_line_len(char **map);
int		check_lines_nb(char **map);
int		is_map_valid(char **map);

/*
** PROCESS
*/

char	**ft_file_to_tab(char *file, int *nb_lines, int *nb_chars);
int		ft_count_char(char *name_file, int *nb_chars_max);
void	ft_tab_generator(char **tab, int fd, int *nb_chars);
int		ft_check_backtracking(char **tab, int *coord, int width);
int		ft_backtracking(char **tab, int *coord, int width, int *id_ret);
void	ft_scan_tab(char **tab, int *id_square, int nb_chars, int nb_lines);
int		ft_process(char *name_file);
char	*read_params(char *map_file);
char	*ft_stdin_save(void);
void	recreate_map(char **tab, int *coord);
char	*ft_file_save(char *name_file);
char	*ft_cat(char *dest, char *src, int *pos);

/*
** DISPLAY MAP
*/

void	display_map(char **map, int nb_chars);

/*
** ERRORS
*/

int		print_error(int	error_code);

#endif
