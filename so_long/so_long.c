/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:52:41 by rricol            #+#    #+#             */
/*   Updated: 2022/03/02 22:50:37 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

t_data ft_init_world(int fd)
{
	t_data	world;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while(ft_get_next_line(fd))
	{
		world.map[i] = ft_get_next_line(fd);
		i++;
	}
	world.size_y_max = i;
	return (world);
}

int		main(int argc, char **argv)
{
	t_data	*world;
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[2], O_RDWR);
		world = ft_init_world(fd);
		//world = malloc(sizeof(t_data));
		if (1)//ft_map_ctrl(argv[2], fd, world) == 0)
		{
			ft_read_file()
			world.size_x_max = 10;
			world.size_y_max = 5;
			world.mlx_ptr = mlx_init();
			world.win_ptr = mlx_new_window(world.mlx_ptr, 50 * world.size_x_max, 
				50 * world.size_y_max, "My Super Game");
			ft_map_init(argv[2]);
			mlx_loop(world.mlx_ptr);
		}
		else
		{
		// réponses en fonction de l'erreur retournée par ft_map_ctrl
			perror("y a une erreur!");
		}
	}
	
	return (0);
}
