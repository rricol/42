/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:16:54 by rricol            #+#    #+#             */
/*   Updated: 2021/11/10 09:48:11 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_isspace(char *str)
{
	if (*str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r' || *str == ' ')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		resp;
	char	*ptr;

	ptr = (char *)str;
	resp = 0;
	sign = 1;
	i = 0;
	while (*(ptr + i))
	{
		while (ft_isspace(ptr + i) == 1)
			i++;
		if (*(ptr + i) == '-')
		{
			sign *= -1;
			i++;
		}
		else if (*(ptr + i) == '+')
			i++;
		while (ft_isdigit(*(ptr + i)))
			resp = (resp * 10) + (*(ptr + i++) - 48);
		return (resp * sign);
	}
	return (0);
}
