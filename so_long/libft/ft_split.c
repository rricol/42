/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 12:23:05 by rricol            #+#    #+#             */
/*   Updated: 2022/02/26 15:01:39 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (c == '\0')
		return (1);
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] != c && str[i])
				i++;
		}
	}
	return (count);
}

static int	word_length(char *str, int index, char c)
{
	int	w_len;

	w_len = 0;
	while (str[index] != c && str[index])
	{
		w_len++;
		index++;
	}
	return (w_len);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	char	*str;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	str = (char *)s;
	tab = ft_calloc(count_words(str, c) + 1, sizeof(char *));
	if (tab == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < (int)ft_strlen(s))
	{
		while (str[i] == c)
			i++;
		if (str[i])
		{
			tab[j] = ft_calloc(word_length(str, i, c) + 1, sizeof(char));
			ft_strlcpy(tab[j++], str + i, word_length(str, i, c) + 1);
			i += word_length(str, i, c);
		}
	}
	return (tab);
}
