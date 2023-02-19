#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_info
{
	int w;
	int h;
	char b;
}t_info;

typedef struct s_rec
{
	char r;
	float x;
	float y;
	float w;
	float h;
	char c;
}t_rec;

int ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return i;
}

int	print_error(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	return 1;
}

int	check_rec(t_rec *rec, float i, float j)
{
	if (j < rec->x || rec->x + rec->w < j
		|| i < rec->y || rec->y + rec->h < i)
		return 0;
	if (j - rec->x < (float)1 || rec->x + rec->w - j < (float)1
		|| i - rec->y < (float)1 || rec->y + rec->h - i < (float)1)
		return 2;
	return 1;
}

void	micro_paint(t_info *info, t_rec *rec, char **map)
{
	int temp;

	for(int i = 0; i < info->h; i++){
		for(int j = 0; j < info->w; j++){
			temp = check_rec(rec, i, j);
			if ((rec->r == 'r' && temp == 2) || (rec->r == 'R' && temp))
				map[i][j] = rec->c;
		}
	}
}

int main(int argc, char **argv)
{
	FILE *f;
	t_info info;
	t_rec rec;
	char **map;
	int ret;

	if (argc != 2)
		return print_error("Error: argument");
	f = fopen(argv[1], "r");
	if (!f)
		return print_error("Error: Operation file corrupted");
	if (fscanf(f, "%d %d %c\n", &info.w, &info.h, &info.b) != 3)
		return print_error("Error: Operation file corrupted");
	if (info.w <= 0 || info.w > 300 || info.h <= 0 || info.h > 300)
		return print_error("Error: Operation file corrupted");
	map = malloc(sizeof(char *) * (info.h + 1));
	if (map == NULL)
		return print_error("Error: Operation file corrupted");
	for(int i = 0; i < info.h; i++){
		map[i] = malloc(sizeof(char) * (info.w + 1));
		if (map[i] == NULL)
			return print_error("Error: Operation file corrupted");
		for(int j = 0; j < info.w; j++)
			map[i][j] = info.b;
		map[i][info.w] = 0;
	}
	map[info.h] = 0;
	while ((ret = fscanf(f, "%c %f %f %f %f %c\n", &rec.r, &rec.x, &rec.y, &rec.w, &rec.h, &rec.c)) == 6)
	{
		if (!(rec.r == 'r' || rec.r == 'R') || rec.w <= 0 || rec.h <= 0)
			return print_error("Error: Operation file corrupted");
		micro_paint(&info, &rec, map);
	}
	if (ret != -1)
		return print_error("Error: Operation file corrupted");
	for (int i = 0; i < info.h; i++){
		for (int j = 0; j < info.w; j++)
			write(1, &map[i][j], 1);
		write(1, "\n", 1);
	}
	for (int i = 0; i <= info.h; i++)
		free(map[i]);
	free(map);
	fclose(f);
	return 0;
}
