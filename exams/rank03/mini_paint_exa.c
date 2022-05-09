#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct s_a
{
	int	w;
	int	h;
	int	s;
	char	c;
	char	*d;
}	t_a;

typedef struct s_s
{
	float	x;
	float	y;
	float	r;
	char	t;
	char	c;
}	t_s;

int	slen(char *s)
{
	int	i = 0;
	while (s[i]) i++;
	return (i);
}

int	perr(char *s, FILE *f, t_a *a)
{
	write(1, s, slen(s));
	write(1, "\n", 1);
	if (f) fclose(f);
	if (a->d && a)
	{
		free(a->d);
		free(a);
	}
	return (1);
}

int	get_info(FILE *f, t_a *a)
{
	int	scan;
	scan = 6;
	while (scan == 6)
	{
		scan = fscanf(f, "%d %d %c\n", &a->w, &a->h, &a->c);
		if (scan != 3) return (1);
		if (a->w > 300 || a->w < 1 || a->h > 300 || a->h < 1) return (1);
		a->s = a->w * a->h;
		a->d = malloc(sizeof(char) * a->s);
		memset(a->d, a->c, a->s);
	}
	return (0);
}

float	dbl(float v)
{
	return (v * v);
}

int	in_shape(float x, float y, t_s *s)
{
	float	dist_sqrt, dist;
	
	dist_sqrt = sqrt(dbl(x - s->x) + dbl(y - s->y));
	dist = dist_sqrt - s->r;
	if (dist > 0) return (0);
	if (dist <= -1) return (1);
	return (2);
}

void	draw_shape(t_a *a, t_s *s)
{
	int	x, y, ctrl;
	y = 0;
	while (y < a->h)
	{
		x = 0;
		while (x < a->w)
		{
			ctrl = in_shape(x, y, s);
			if ((ctrl == 2 && s->t == 'c') || (ctrl && s->t == 'C'))
				a->d[y * a->w + x] = s->c;
			x++;
		}
		y++;
	}
}

int	get_shape(FILE *f, t_a *a)
{
	t_s	*s;
	int	scan;

	s = malloc(sizeof(t_s));
	scan = 5;
	while (scan == 5)
	{
		scan = fscanf(f, "%c %f %f %f %c\n", &s->t, &s->x, &s->y, &s->r, &s->c);
		if (scan != 5 && scan != -1) return (1);
		if (s->r <= 0 || (s->t != 'c' && s->t != 'C')) return (1);
		draw_shape(a, s);
	}
	free(s);
	return (0);
}

void	draw(t_a *a)
{
	int	i = 0;
	while (i < a->h)
	{
		write(1, &a->d[i * a->w], a->w);
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	FILE	*f;
	t_a	*a;

	if (argc == 2)
	{
		f = fopen(argv[1], "r");
		if (f == NULL) return (perr("Error: Operation file corrupted", f, NULL));
		a = malloc(sizeof(t_a));
		if (get_info(f, a)) return (perr("Error: Operation file corrupted", f, a));
		if (get_shape(f, a)) return (perr("Error: Operation file corrupted", f, a));
		fclose(f);
		draw(a);
		free(a->d);
		free(a);
	}
	else
		return (perr("Error: argument", NULL, NULL));
	return (0);
}
