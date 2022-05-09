/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 11:26:15 by rricol            #+#    #+#             */
/*   Updated: 2022/03/16 11:26:15 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *s)
{
	int		i;
	int		sign;
	int		res;

	i = 0;
	sign = 1;
	res = 0;
	while (s[i])
	{
		while(ft_isspace(s[i]) == 0)
			i++;
		if(s[i] == '-')
		{
			sign = -1;
			i++;
		}
		else if (s[i] == '+')
			i++;
		while (ft_isdigit(s[i]) == 0)
			res = (res * 10) + (s[i++] - 48);
		return (res * sign);
	}
	return (0);
}
