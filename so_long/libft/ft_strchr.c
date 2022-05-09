/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:01:15 by rricol            #+#    #+#             */
/*   Updated: 2021/11/10 09:55:31 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strchr(const char *s, int c)
{
    int        i;
    char    *str;

    str = (char *)s;
    i = 0;
    if (str == NULL)
        return (NULL);
    while (str[i])
    {
        if (str[i] == c)
            return (str + i);
        else
            i++;
    }
    if (str[i] == c)
        return (str + i);
    else
        return (NULL);
}
