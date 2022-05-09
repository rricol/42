/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_ctrl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:23:06 by marvin            #+#    #+#             */
/*   Updated: 2022/02/23 13:23:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Check file extension
// return (0) = Pas d'erreurs
int	ft_err_extension(char *map_fileName)
{
	int	i;

	i = ft_strlen(map_fileName);
	if ((map_fileName + (i - 4)) == ".ber")
		return (0);
	return (1);
}

int	ft_read_map(int fd, t_data world)
{
	int		x;
	int		y;
	char	*buff;

	// TODO : Gérer les erreur de fd
	buff = malloc(1 * sizeof(char *));
	x = 0;
	read(fd, buff, 1);
	while (buff != '\0')
	{
		y = 0;
		while (buff != '\n' && buff != '\0')
		{
			ft_print_tile(world, buff, x, y);
			read(fd, buff, 1);
			y++,
		}
		x++;
	}
	world.max_x = x;
	world.max_y = y;
	free(buff);
	return (0);
}

int	ft_map_ctrl(char *map_fileName, int fd, t_data world)
{
	if (!ft_err_extension(map_fileName))
	{
		ft_err_size(fd, world)
	}
	else
		return (-1);
	return (0);
}
