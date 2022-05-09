/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:14:47 by rricol            #+#    #+#             */
/*   Updated: 2021/11/07 12:02:48 by rricol           ###   ########.fr       */
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
