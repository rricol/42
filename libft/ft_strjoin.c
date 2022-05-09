/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 23:36:02 by rricol            #+#    #+#             */
/*   Updated: 2022/03/15 23:36:02 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*s3;

	if (s1 == NULL)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (s2 == NULL)
		return (NULL);
	i = ft_strlen(s1);
	s3 = malloc((i + ft_strlen(s2) + 1) * sizeof(char));
	if (s3 == NULL)
		return (NULL);
	j = 0;
	ft_strlcpy(s3, s1, ft_strlen(s2));
	while (s2[j])
		s3[i++] = s2[j++];
	s3[i] = '\0';
	free(s1);
	return (s3);
}

char	*str_join_path (char *path, char *bin)
{
	char	*dst;
	int		i;
	int		j;

	dst = malloc(sizeof(char) * (ft_strlen(path) + ft_strlen(bin) + 2));
	i = 0;
	j = 0;
	while (path[j])
		dst[i++] = path[j++];
	dst[i++] = '/';
	j = 0;
	while (bin[j])
		dst[i++] = bin[j++];
	dst[i] = 0;
	return (dst);
}
