/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 22:28:35 by rricol            #+#    #+#             */
/*   Updated: 2022/03/15 22:28:35 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char			*str;
	unsigned int	i;
	unsigned int	len;

	i = 0;
	str = (char *)src;
	len = ft_strlen(str);
	if (dstsize == 0)
		return (len);
	while (i < (dstsize - 1) && str[i])
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
