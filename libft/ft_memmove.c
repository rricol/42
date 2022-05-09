/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:35:57 by rricol            #+#    #+#             */
/*   Updated: 2022/03/16 14:35:59 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;
	unsigned char	*dest;
	unsigned char	*srce;

	if (dst == NULL && src == NULL)
		return (NULL);
	dest = (unsigned char *)dst;
	srce = (unsigned char *)src;
	if (srce < dest)
	{
		while (len-- > 0)
			dest[len] = srce[len];
	}
	else
	{
		i = -1;
		while (++i < len)
			dest[i] = srce[i];
	}
	return (dest);
}
