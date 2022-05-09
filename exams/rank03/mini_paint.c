/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 11:02:40 by rricol            #+#    #+#             */
/*   Updated: 2022/04/30 14:43:08 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct s_zone
{
	int		width;
	int		height;
	char	bkg;
	char	*drawing;
}	t_zone;

typedef struct s_shape
{
	char	type;
	float	x;
	float	y;
	float	rad;
	char	color;
}	t_shape;

#define ERR_ARG		1
#define ERR_FILE	2

int	exit_error(int error)
{
	if (error == 1)
		write(1, "Error: argument\n", 16);
	else if (error == 2)
		write(1, "Error: Operation file corrupted\n", 32);
	exit(1);
}

int	get_info(FILE *file, t_zone *zone)
{
	int	ctrl;
	int	size;

	ctrl = fscanf(file, "%d %d %c\n", &zone->width, &zone->height, &zone->bkg);
	if (ctrl == 3)
	{
		if (zone->height < 0 || zone->height > 300
			|| zone->width < 0 || zone->width > 300)
			return (1);
		size = zone->width * zone->height;
		zone->drawing = malloc(sizeof(char) * size + 1);
		memset(zone->drawing, zone->bkg, size);
		return (0);
	}
	else
		return (1);
}

int	in_shape(float x, float y, t_shape *shape)
{
	float dist;

	dist = sqrt((x - shape->x) * (x - shape->x) + (y - shape->y) * (y - shape->y));
	if (dist > shape->rad)
		return (0);
	if (shape->rad - dist < 1 && shape->rad - dist >= 0)
		return (2);
	return (1);
}

void	draw_shape(t_shape *shape, t_zone *zone)
{
	int	x;
	int	y;
	int	ctrl;

	y = 0;
	while (y < zone->height)
	{
		x = 0;
		while (x < zone->width)
		{
			ctrl = in_shape(x, y, shape);
			if ((shape->type == 'c' && ctrl == 2)
				|| (shape->type == 'C' && ctrl))
				zone->drawing[(y * zone->width) + x] = shape->color;
			x++;
		}
		y++;
	}
}

int	get_shape(FILE *file, t_zone *zone)
{
	t_shape	*shape;
	int		ctrl;

	shape = malloc(sizeof(t_shape));
	ctrl = fscanf(file, "%c %f %f %f %c\n",
			&shape->type, &shape->x, &shape->y,
			&shape->rad, &shape->color);
	if (ctrl == -1)
		return (1);
	while (ctrl == 5)
	{
		draw_shape(shape, zone);
		ctrl = fscanf(file, "%c %f %f %f %c\n",
				&shape->type, &shape->x, &shape->y,
				&shape->rad, &shape->color);
	}
	free(shape);
	return (0);
}

void	draw(t_zone *zone)
{
	int	x;
	int	y;

	y = 0;
	while (y < zone->height)
	{
		x = 0;
		while (x < zone->width)
		{
			write(1, &zone->drawing[(y * zone->width) + x], 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}

int	main(int argc, char **argv)
{
	t_zone	*zone;
	FILE	*file;

	if (argc == 2)
	{
		zone = malloc(sizeof(t_zone));
		file = fopen(argv[1], "r");
		if (!get_info(file, zone))
		{
			get_shape(file, zone);
			draw(zone);
			free(zone->drawing);
			free(zone);
			fclose(file);
		}
		else
			exit_error(ERR_FILE);
	}
	else
		exit_error(ERR_ARG);
	return (0);
}
