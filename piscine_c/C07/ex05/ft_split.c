/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 20:47:44 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/24 14:53:33 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_charset(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_count_words(char *str, char *charset)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (*str)
	{
		if (is_charset(*str, charset) && i > 0)
		{
			count++;
			i = 0;
		}
		else if (!is_charset(*str, charset))
			i++;
		str++;
	}
	if (i > 0)
		count++;
	return (count);
}

int		*ft_count_letters(char *str, char *charset, int nb_words)
{
	int *size_word;
	int count;
	int id;

	if ((size_word = malloc(sizeof(int) * nb_words)) == NULL)
		return (0);
	count = 0;
	id = 0;
	while (*str)
	{
		if (is_charset(*str, charset) && count > 0)
		{
			size_word[id] = count;
			id++;
			count = 0;
		}
		else if (!is_charset(*str, charset))
			count++;
		str++;
	}
	if (count > 0)
		size_word[id] = count;
	return (size_word);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		count_words;
	int		*size_word;
	int		i;
	int		j;

	count_words = ft_count_words(str, charset);
	tab = malloc(sizeof(char*) * count_words + 1);
	tab[count_words] = NULL;
	if (count_words == 0)
		return (tab);
	size_word = malloc(sizeof(int) * count_words);
	size_word = ft_count_letters(str, charset, count_words);
	i = 0;
	while (i < count_words && (j = -1))
	{
		tab[i] = malloc(sizeof(char) * size_word[i] + 1);
		tab[i][size_word[i]] = '\0';
		while (is_charset(*str, charset) && *str)
			str++;
		while (++j < size_word[i] && str[j])
			tab[i][j] = str[j];
		str += size_word[i++];
	}
	return (tab);
}
