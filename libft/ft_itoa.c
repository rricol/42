/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 11:39:22 by rricol            #+#    #+#             */
/*   Updated: 2022/03/16 11:39:22 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	st_nblen(long n)
{
	int len;

	len = 1;
	if (n < 0)
		len += st_nblen(-n);
	else if (n / 10 != 0)
		len += st_nblen(n / 10);
	else
		len++;
	return (len);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;
	int		i;

	len = st_nblen((long)n);
	s = malloc(sizeof(char) * len + 1);
	if (s == NULL)
		return  (NULL);
	i = 0;
	if (n < 0)
	{
		s[i++] = '-';
		n *= -1;
	}
	s[len--] = '\0';
	while (len > i)
	{
		s[--len] = n % 10 + 48;
		n /= 10;
	}
	return (s);
}
