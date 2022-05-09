/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:07:17 by rricol            #+#    #+#             */
/*   Updated: 2021/11/10 11:24:39 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_set_in_str(char s1, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == s1)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	char	*str1;
	size_t	i;
	size_t	start;
	size_t	end;

	i = 0;
	start = 0;
	if (s1 == NULL)
		return (NULL);
	str1 = (char *) s1;
	while (str1[start] && ft_set_in_str(str1[start], set))
		start++;
	end = ft_strlen(str1);
	while (end > start && ft_set_in_str(str1[end - 1], set))
		end--;
	dest = (char *)malloc(sizeof(char) * (end - start + 1));
	if (dest == NULL)
		return (NULL);
	while (start < end)
		dest[i++] = str1[start++];
	dest[i] = '\0';
	return (dest);
}
