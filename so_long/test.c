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
		map[i++] = buf[0];
	return (map);
}

int	ft_init_game(int fd, t_data *game)
{
    game->map = malloc(sizeof(char **) * 1);
	game->map = ft_split(ft_read_map(fd), '\n');
	game->mlx_ptr = mlx_init();
	game->win_ptr = NULL;
    game->floor = <
	
	return (0);
}

int	main(int ac, char **av)
{
	t_data	game;
    t_data  *game_ptr;
	int		fd;

	if (ac == 2)
	{
        game_ptr = &game;
		fd = open(av[2], O_RDONLY);
        ft_ctrl_game(av[2], fd);
		ft_init_game(fd, game_ptr);
        close(fd);
        ft_start_game(game_ptr);
	}
	return (0);
}