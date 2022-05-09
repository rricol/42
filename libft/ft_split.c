/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:43:41 by rricol            #+#    #+#             */
/*   Updated: 2022/03/15 21:43:41 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	st_wordlen(char *s, char c)
{
	int i;

	i = 0;
	while (s[i] != c)
		i ++;
	return (i);
}

char	**ft_split(char *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	tab = malloc(sizeof(char *) * ft_count_words(s, c) + 1);
	if (tab == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (j++ < ft_count_words(s, c))
	{
		while (s[i] == c)
			i++;
		tab[j] = malloc(sizeof(char) * st_wordlen(s + i, c));
		if (tab[j] == NULL)
			return (NULL);
		while (s[i] != c)
		{
			ft_strlcpy(tab[j], s + i, st_wordlen(s + i, c));
			i += st_wordlen(s + i, c);
		}
	}
	return (tab);
}
