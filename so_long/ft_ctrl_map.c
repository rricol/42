/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctrl_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 22:42:13 by rricol            #+#    #+#             */
/*   Updated: 2022/03/03 19:34:57 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int ft_ctrl_mapSize(int fd, t_data *game)
{
	/*
	> Tant qu'il y a des lignes a lire
		1. lire la 1ere ligne de la map
		2. obtenir la taille de cette ligne
		3. Stocker la taille dans line_len
		4. si tmp != 0 alors comparer tmp et line_len
			4a. diff ? -> Error_Map
			4b. Similaire ? -> Continue
		5. Augmenter le nombre de ligne de 1
	> game->x_max == total de ligne
	> game->y_max == line_len 
	*/
}

int	ft_ctrl_map(int fd, t_data *game)
{

	if (ft_ctrl_mapSize() && ft_ctrl_
}
