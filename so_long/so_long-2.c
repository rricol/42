/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long-2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:35:33 by rricol            #+#    #+#             */
/*   Updated: 2022/03/03 19:35:00 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_read_map(int fd)
{
	char	*map;
	char	*buf;
	int		ctrl;
	int		i;

	i = 0;
	buf = malloc(sizeof(char*) * 1);
	ctrl = read(fd, buf, 1);
	if (ctrl = -1)
		return(NULL);
	while (ctrl != 0)
		map[i++] == buf;
	return (map);
}

int		ft_init_game(int fd, t_data *game)
{
	int		img_width;
	int		img_height;

	game->map = ft_split(ft_read_map(fd), '\n');
	game->mlx_ptr = mlx_init();
	game->win_ptr = NULL;
	game->floor = mlx_xpm_file_to_image(game->mlx_ptr, 
		FLOOR, &img_width, &img_height);
	game->stairs = mlx_xpm_file_to_image(game->mlx_ptr, 
		STAIRS, &img_width, &img_height);
	game->exit_cover = mlx_xpm_file_to_image(game->mlx_ptr, 
		EXIT, &img_width, &img_height);
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr, 
		WALL, &img_width, &img_height);
	game->player = mlx_xpm_file_to_image(game->mlx_ptr, 
		PLAYER, &img_width, &img_height);
	game->potion = mlx_xpm_file_to_image(game->mlx_ptr, 
		POTION, &img_width, &img_height);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*game;
	int		fd;

	if (argc == 2)
	{
		game = malloc(sizeof(t_data));
		fd = open(argv[2], O_RDONLY);
		if (!ft_ctrl_map(fd, game))
		ft_init_game(fd, game);
	}
	return (0);
}
