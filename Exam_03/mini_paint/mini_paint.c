# include "mini_paint.h"

typedef struct s_info
{
	int		w;
	int		h;
	char	bg_char;
}	t_info;
t_info info;

typedef struct s_circle
{
	char	type;
	float	x;
	float	y;
	float	r;
	char	draw_char;
}	t_circle;

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

int	argc_error(void)
{
	ft_putstr("Error: argument\n");
	return (1);
}

int	file_error(void)
{
	ft_putstr("Error: Operation file corrupted\n");
	return (1);
}

int	is_in_circle(t_circle *c, float x, float y)
{
	float	dist;

	dist = sqrtf(powf(x - c->x, 2) + powf(y - c->y, 2));
	if (dist > c->r)
		return (0);
	if ((c->r - dist) < (float)1)
		return (2);
	return (1);
}

void	mini_paint(char **map, t_circle *c)
{
	int	i, j, ret;

	for (i=0;i<info.h;i++)
	{
		for (j=0;j<info.w;j++)
		{
			ret = is_in_circle(c, j, i);
			if ((c->type == 'c' && ret == 2) || (c->type == 'C' && ret))
				map[i][j] = c->draw_char;
		}
	}
}

void	print_map(char **map)
{
	for (int i=0;i<info.h;i++)
	{
		for (int j=0;j<info.w;j++)
			write(1, &map[i][j], 1);
		write(1, "\n", 1);
	}
}

int	main(int argc, char **argv)
{
	t_circle	c;
	FILE		*f;
	char		**map;
	int			i, j, ret;

	if (argc != 2)
		return (argc_error());
	f = fopen(argv[1], "r");
	if (f == NULL)
		return (file_error());
	if (fscanf(f, "%d %d %c\n", &info.w, &info.h, &info.bg_char) != 3)
		return (file_error());
	if (!(info.w > 0 && info.w <= 300 && info.h > 0 && info.h <= 300))
		return (file_error());
	map = malloc(sizeof(char *) * (info.h + 1));
	if (map == NULL)
		return (1);
	for (i=0;i<info.h;i++)
	{
		map[i] = malloc(info.w + 1);
		if (map[i] == NULL)
			return (1);
		for (j=0;j<info.w;j++)
			map[i][j] = info.bg_char;
		map[i][j] = 0;
	}
	map[i] = 0;
	while ((ret = fscanf(f, "%c %f %f %f %c\n", &c.type, &c.x, &c.y, &c.r, &c.draw_char)) == 5)
	{
		if (c.r <= (float)0 || !(c.type == 'c' || c.type == 'C'))
			return (file_error());
		mini_paint(map, &c);
	}
	if (ret != -1)
		return (file_error());
	print_map(map);
	for (i=0;i<info.h;i++)
		free(map[i]);
	free(map);
	fclose(f);
	return (0);
}