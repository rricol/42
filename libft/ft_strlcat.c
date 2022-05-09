/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:28:23 by rricol            #+#    #+#             */
/*   Updated: 2022/03/16 15:29:48 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	unsigned int	d_len;
	unsigned int	s_len;
	unsigned int	offset;
	unsigned int	src_index;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	offset = d_len;
	src_index = 0;
	if (dstsize <= d_len)
		return (dstsize + s_len);
	while (*(src + src_index))
	{
		if (offset == dstsize - 1)
			break ;
		*(dst + offset) = *(src + src_index);
		offset++;
		src_index++;
	}
	*(dst + offset) = '\0';
	return (d_len + s_len);
}
