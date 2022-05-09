/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:06:19 by rricol            #+#    #+#             */
/*   Updated: 2022/03/02 23:06:16 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

# include "./mlx/mlx.h"
# include "./libft/libft.h"

# define TILE_WIDTH 50

# define WALL "./assets/st1/wall.xpm"
# define FLOOR "./assets/st1/floor.xpm"
# define PLAYER "./assets/st1/player.xpm"
# define POTION "./assets/st1/potion.xpm"
# define STAIRS "./assets/st1/stairs.xpm"
# define EXIT "./assets/st1/exit-cover.xpm"

# define ERR_MSG "Il semble qu'il y ait eu un problème. Veuillez contrôler votre map."

# define GAME_WON "Well done champion!"
# define GAME_LOST	"Game over!"

# define BLUE 0x000000FF

typedef struct s_data {
	void	*mlx_ptr;
	void	*win_ptr;
	char	*map;
	void	*player;
	void	*exit_cover;
	void	*stairs;
	void	*potion;
	void	*floor;
	void	*wall;
	int		map_length;
	int		map_width;
	int		player_pos_x;
	int		player_pos_y;
	int		steps;
	int		score;
}				t_data;


#endif
