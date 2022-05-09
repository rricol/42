/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 20:32:14 by rricol            #+#    #+#             */
/*   Updated: 2022/03/18 23:36:44 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t i;

	if (s1 == NULL || s2 == NULL)
		return (-1);
	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int 	ft_strichr(char *s, int c)
{
    int        i;

    i = 0;
    if (s == NULL)
        return (ERR);
    while (s[i] && s[i] != c)
            i++;
    if (s[i] == c)
        return (i);
    else
        return (ERR);
}

char	*ft_strndup(char *s, int n)
{
	char	*dst;
	int		i;

	i = 0;
	dst = malloc(sizeof(char) * n + 1);
	if (dst == NULL)
		return (NULL);
	while (s[i] && i < n)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_join_path (char *path, char *bin)
{
	char	*dst;
	int		i;
	int		j;

	dst = malloc(sizeof(char) * (ft_strlen(path) + ft_strlen(bin) + 2));
	i = 0;
	j = 0;
	while (path[j])
		dst[i++] = path[j++];
	dst[i++] = '/';
	j = 0;
	while (bin[j])
		dst[i++] = bin[j++];
	dst[i] = 0;
	return (dst);
}

char	**ft_split (char *str, char sep)
{
	char	**tab;
	int		sep_count;
	int		i;
	int		j;

	sep_count = 0;
	j = 0;
	while (str[j])
	{
		if (str[j++] == sep)
			sep_count++;
	}
	tab = malloc(sizeof(char *) * (sep_count + 2));
	tab[sep_count + 1] = NULL;
	i = 0;
	while (i < sep_count + 1)
	{
		j = 0;
		while (str[j] && str[j] != sep)
			j++;
		tab[i++] = ft_strndup(str, j);
		str = str + j + 1;
	}
	return (tab);
}
