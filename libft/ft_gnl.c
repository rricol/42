/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:41:35 by rricol            #+#    #+#             */
/*   Updated: 2022/03/16 15:22:34 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gnl(int fd, char *s)
{
	char	buf;
	int		ctrl;
	int		i;

	ctrl = 1;
	i = 0;
	if (s == NULL)
		return (NULL);
	while (ctrl != 0)
	{
		ctrl = read(fd, &buf, 1);
		if (ctrl == -1)
			return (NULL);
		while (buf != '\n' && ctrl != 0)
			s[i++] = buf;
		s[i] = '\0';
	}
	return (s);
}
