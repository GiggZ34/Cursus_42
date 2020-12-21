/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <grivalan@studen.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:47:18 by grivalan          #+#    #+#             */
/*   Updated: 2020/12/09 10:37:41 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t nb_words;
	size_t i;

	nb_words = 0;
	if (s[0] != c && s[0] != '\0')
		nb_words++;
	i = -1;
	while (s[++i])
		if (s[i] == c && (s[i + 1] != c && s[i + 1] != '\0'))
			nb_words++;
	return (nb_words);
}

static size_t	ft_letter(char const *s, char c)
{
	size_t	nb_letters;
	int		i;

	nb_letters = 0;
	i = -1;
	while (s[++i] != c && s[i])
		nb_letters++;
	return (nb_letters);
}

static	int		ft_free_split(char **str)
{
	while (*str)
	{
		free(*str);
		*str = 0;
		str++;
	}
	free(str);
	str = 0;
	return (0);
}

static int		ft_str_to_tab(char **new_s, char *str, char c, size_t nb_words)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < nb_words)
	{
		while (*str == c && *str)
			str++;
		if ((new_s[i] = malloc(sizeof(char) * (ft_letter(str, c) + 1))) == NULL)
		{
			return (ft_free_split(new_s));
		}
		j = 0;
		while (*str != c && *str)
		{
			new_s[i][j++] = *str;
			str++;
		}
		new_s[i++][j] = '\0';
	}
	return (0);
}

char			**ft_split(char const *s, char c)
{
	char	**new_s;
	char	*str;
	size_t	nb_words;

	if (!s)
		return (0);
	str = (char*)s;
	nb_words = ft_count_words(s, c);
	if ((new_s = malloc(sizeof(char *) * (nb_words + 1))) == NULL)
		return (0);
	new_s[nb_words] = 0;
	ft_str_to_tab(new_s, str, c, nb_words);
	return (new_s);
}
