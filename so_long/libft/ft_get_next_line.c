/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 14:50:57 by rricol            #+#    #+#             */
/*   Updated: 2022/02/26 14:53:08 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_next_line(int fd, char *str)
{
	char	buff;
	int		ctrl;
	int		i;

	ctrl = 1;
	i = 0;
	while (ctrl != 0)
	{
		ctrl = read(fd, &buff, 1);
		if (ctrl == -1)
			return (0);
		if (ctrl != 0)
			str[i++] = buff;
		str[i] = '\0';
	}
	if (i == 0)
		return (0);
	close (fd);
	return (str);
}
