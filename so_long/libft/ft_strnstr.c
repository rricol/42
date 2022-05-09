/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:02:28 by rricol            #+#    #+#             */
/*   Updated: 2021/11/07 16:55:49 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	size_t			n_len;

	i = 0;
	n_len = ft_strlen((char *)needle);
	if (n_len > len && (char *)haystack != NULL)
		return (NULL);
	if (n_len == 0)
		return ((char *)haystack);
	while (haystack[i] && (i + n_len) <= len)
	{
		if (haystack[i] == needle[0])
		{
			if (ft_strncmp((char *)haystack + i, needle, n_len) == 0)
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
