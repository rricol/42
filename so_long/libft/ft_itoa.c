/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:39:10 by rricol            #+#    #+#             */
/*   Updated: 2021/11/14 10:57:53 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nblen(long nb)
{
	int	len;

	len = 1;
	if (nb < 0)
		len += ft_nblen(-nb);
	else if (nb > 9)
		len += ft_nblen(nb / 10);
	else if (nb < 10)
		len++;
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		k;
	long	nbr;

	nbr = n;
	len = ft_nblen(nbr);
	str = ft_calloc(len, sizeof(char));
	if (str == NULL)
		return (NULL);
	k = 0;
	if (nbr < 0)
	{
		str[0] = '-';
		k = 1;
		nbr *= -1;
	}
	len--;
	while (len > k)
	{
		str[--len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}
