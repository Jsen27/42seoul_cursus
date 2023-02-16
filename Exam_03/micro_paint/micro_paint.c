#include "micro_paint.h"

typedef struct s_info
{
	int		w;
	int		h;
	char	bg_c;
}	t_info;
t_info	info;

typedef struct s_rect
{
	char	type;
	float	x;
	float	y;
	float	w;
	float	h;
	char	draw_c;
}	t_rect;

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

int	file_error(void)
{
	ft_putstr("Error: Operation file corrupted\n");
	return (1);
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

int	is_in_rect(float x, float y, t_rect *r)
{
	if (((x < r->x || (r->x + r->w< x))
		|| (y < r->y)) || (r->y + r->h < y))
		return (0);
	if (((x - r->x < (float)1) || ((r->x + r->w) - x < (float)1)) ||
	((y - r->y < (float)1 || ((r->y + r->h) - y < (float)1))))
		return (2);
	return (1);
}

void	micro_paint(char **map, t_rect *r)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	while (i < info.h)
	{
		j = 0;
		while (j< info.w)
		{
			ret = is_in_rect(j, i, r);
			if ((r->type == 'r' && ret == 2) || (r->type == 'R' && ret))
				map[i][j] = r->draw_c;
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	FILE	*f;
	t_rect	r;
	char	**map;
	int		i, j, ret;

	if (argc != 2)
	{
		ft_putstr("Error: argument\n");
		return (1);
	}
	f = fopen(argv[1], "r");
	if (f == NULL)
		return (file_error());
	if (fscanf(f, "%d %d %c\n", &info.w, &info.h, &info.bg_c) != 3)
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
			map[i][j] = info.bg_c;
		map[i][j] = 0;
	}
	map[i] = 0;
	while ((ret = fscanf(f, "%c %f %f %f %f %c\n", &r.type, &r.x, &r.y, &r.w, &r.h, &r.draw_c)) == 6)
	{
		if (r.w <= (float)0 || r.h <= (float)0 || !(r.type == 'r' || r.type == 'R'))
			return (file_error());
		micro_paint(map, &r);
	}
	if (ret != -1)
		return (file_error());
	print_map(map);
	for (i=-0;i<info.h;i++)
		free(map[i]);
	free(map);
	fclose(f);
	return (0);
}