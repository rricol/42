/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 00:13:28 by rricol            #+#    #+#             */
/*   Updated: 2022/03/02 22:50:44 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_insert_image(t_data world, char *path, int x, int y)
{
	void	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(world.mlx_ptr, path, &img_width, &img_height);
	mlx_put_image_to_window(world.mlx_ptr, world.win_ptr, img, 32 * x, 32 * y);
}

void	ft_print_tile(t_data world, char *buff, int x, int y)
{
	if (buff == "1")
		ft_insert_image(world, world.path_xpm_wall, x, y);
	else if (buff == "0")
		ft_insert_image(world, world.path_xpm_floor, x, y);
	else if (buff == "E")
		ft_insert_image(world, world.path_xpm_exit, x, y);
	else if (buff == "P")
	{
		world.player_x = x;
		world.player_y = y;
		ft_insert_image(world, world.path_xpm_floor, x, y);
		ft_insert_image(world, world.path_xpm_player, x, y);
	}
	else if (buff == "C")
	{
		ft_insert_image(world, world.path_xpm_floor, x, y);
		ft_insert_image(world, world.path_xpm_object, x, y);
	}
}

t_data	ft_map_init(t_data world, int fd)
{
	world.path_xpm_exit = "assets/tileset_style1/e-doorOpen.xpm";
	world.path_xpm_floor = "assets/tileset_style1/t-floor.xpm";
	world.path_xpm_player = "assets/tileset_style1/p-dino.xpm";
	world.path_xpm_wall = "assets/tileset_style1/t-wall.xpm";
	world.path_xpm_object = "assets/tileset_style1/c-potion.xpm";
	ft_print_tile(world, );
	return (world);
}
