/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:25:09 by rricol            #+#    #+#             */
/*   Updated: 2022/03/18 22:46:45 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *s, int c)
{
    int        i;

    i = 0;
    if (s == NULL)
        return (NULL);
    while (s[i] && s[i] != c)
            i++;
    if (s[i] == c)
        return (s + i);
    else
        return (NULL);
}

int 	ft_strichr(char *s, int c)
{
    int        i;

    i = 0;
    if (s == NULL)
        return (NULL);
    while (s[i] && s[i] != c)
            i++;
    if (s[i] == c)
        return (i);
    else
        return (ERR);
}
