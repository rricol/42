/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctrl_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 22:37:01 by rricol            #+#    #+#             */
/*   Updated: 2022/03/02 22:54:15 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int	ft_ctrl_ext(char *file, char *ext)
{
	int	file_len;
	int	ext_len;

	ext_len = ft_strlen(ext);
	file_len = ft_strlen(file);
	if (*file + (file_len - ext_len) == ext)
		return (1);
	else
		return (0);
}
