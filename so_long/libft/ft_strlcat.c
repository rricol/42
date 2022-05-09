/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:01:55 by rricol            #+#    #+#             */
/*   Updated: 2021/11/14 12:37:25 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	d_len;
	unsigned int	s_len;
	unsigned int	offset;
	unsigned int	src_index;
	char			*str;

	str = (char *)src;
	d_len = ft_strlen(dst);
	s_len = ft_strlen(str);
	offset = d_len;
	src_index = 0;
	if (dstsize <= d_len)
		return (dstsize + s_len);
	while (*(str + src_index))
	{
		if (offset == dstsize - 1)
			break ;
		*(dst + offset) = *(str + src_index);
		offset++;
		src_index++;
	}
	*(dst + offset) = '\0';
	return (d_len + s_len);
}
