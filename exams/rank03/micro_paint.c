/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 10:57:26 by rricol            #+#    #+#             */
/*   Updated: 2022/04/29 13:21:14 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_shape
{
	char	type;
	float	x;
	float	y;
	float	width;
	float	height;
	char	color;
}	t_shape;

typedef	struct s_bkg
{
	int		width;
	int		height;
	char	bkg;
	char	*drawing;
}	t_bkg;

size_t	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	print_error(char *error)
{
	write(1, error, ft_strlen(error));
	write(1, "\n", 1);
}

int	get_info(FILE *file, t_bkg *bkg)
{
	int	scan_ret;
	int	size;

	scan_ret = fscanf(file, "%d %d %c\n", &bkg->width, &bkg->height, &bkg->bkg);
	if (scan_ret == -1)
		return (1);
	if(bkg->height > 300 || bkg->height < 0 || bkg->width > 300 || bkg->width < 0)
		return (1);
	size = bkg->height * bkg->width;
	bkg->drawing = malloc(sizeof(char) * size + 1);
	memset(bkg->drawing, bkg->bkg, size);
	bkg->drawing[size] = 0;
	return (0);
}

int	is_in_shape(float x, float y, t_shape *shape)
{
	if ((x < shape->x || x > (shape->x + shape->width)) ||
		y < shape->y || y > (shape->y + shape->height))
		return (0);
	if ((x - shape->x <= 1 || (shape->x + shape->width) - x <= 1) ||
		(y - shape->y <= 1 || (shape->y + shape->height) - y <= 1))
		return (2);
	return (1);
}

int	draw_shape(t_bkg *bkg, t_shape *shape)
{
	int	i;
	int	j;
	int ctrl;

	ctrl = 0;
	i = 0;
	while (i < bkg->height)
	{
		j = 0;
		while (j < bkg->width)
		{
			ctrl = is_in_shape(j, i, shape);
			if ((shape->type == 'r' && ctrl == 2) || (shape->type == 'R' && ctrl))
				bkg->drawing[(i * bkg->width) + j] = shape->color;
			j++;
		}
		i++;
	}
	return (0);
}

int	get_shape(FILE *file, t_bkg *bkg)
{
	int		scan_ret;
	t_shape	*shape;

	shape = malloc(sizeof(t_shape));
	scan_ret = fscanf(file, "%c %f %f %f %f %c\n", &shape->type, &shape->x, &shape->y, &shape->width, &shape->height, &shape->color);
	while (scan_ret == 6)
	{
		draw_shape(bkg, shape);
		scan_ret = fscanf(file, "%c %f %f %f %f %c\n", &shape->type, &shape->x, &shape->y, &shape->width, &shape->height, &shape->color);
	}
	free(shape);
	return (0);
}

void	print_drawing(t_bkg *bkg)
{
	int	i;
	int	j;

	i = 0;
	while (i < bkg->height)
	{
		j = 0;
		while (j < bkg->width)
		{
			write(1, &bkg->drawing[(i * bkg->width) + j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	FILE	*file;
	t_bkg	*bkg;

	if (argc == 2)
	{
		bkg = malloc(sizeof(t_bkg));
		file = fopen(argv[1], "r");
		if (!get_info(file, bkg))
		{
			if (get_shape(file, bkg))
				print_error("Error: Operation file corrupted.");
			print_drawing(bkg);
			fclose(file);
			free(bkg->drawing);
			free(bkg);
		}
		else
		{
			print_error("Error: Operation file corrupted.");
			return (1);
		}
	}
	else
	{
		print_error("Error: arguments");
		return (1);
	}
	return (0);
}
