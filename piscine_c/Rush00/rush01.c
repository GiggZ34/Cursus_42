/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 11:12:58 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/13 11:23:41 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_convert_negative(int *a)
{
	return (*a * -1);
}

char	*ft_pattern_generate(int n)
{
	if (n == 1)
		return ("/*\\");
	else if (n == 2)
		return ("* *");
	else
		return ("\\*/");
}

void	ft_print_line(char *pattern, int *x)
{
	int j;

	j = 0;
	while (j < *x)
	{
		if (j == 0)
			ft_putchar(pattern[0]);
		else if (j == *x - 1)
			ft_putchar(pattern[2]);
		else
			ft_putchar(pattern[1]);
		j++;
	}
}

void	ft_print_column(int *x, int *y)
{
	int i;

	i = 0;
	while (i < *y)
	{
		if (i == 0)
			ft_print_line(ft_pattern_generate(1), x);
		else if (i == *y - 1)
			ft_print_line(ft_pattern_generate(3), x);
		else
			ft_print_line(ft_pattern_generate(2), x);
		ft_putchar('\n');
		i++;
	}
}

void	rush(int x, int y)
{
	if (x < 0)
		x = ft_convert_negative(&x);
	if (y < 0)
		y = ft_convert_negative(&y);
	ft_print_column(&x, &y);
}
