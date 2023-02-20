#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_info
{
	int w;
	int h;
	char b;
}	t_info;

typedef struct s_rad
{
	char c;
	float x;
	float y;
	float r;
	char d;
}	t_rad;

int ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return i;
}

int print_error(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	return 1;
}

int check_rad(t_rad rad, float x, float y)
{
	float temp;
	temp = sqrtf(powf(x - rad.x, 2) + powf(y - rad.y, 2));
	if (temp > rad.r)
		return 0;
	if (rad.r - temp < (float)1)
		return 2;
	return 1;
}

void mini_paint(t_info info, t_rad rad, char **map)
{
	int check;

	for(int i = 0; i < info.h; i++){
		for(int j = 0; j < info.w; j++){
			check = check_rad(rad, j, i);
			if ((rad.c == 'c' && check == 2) || (rad.c == 'C' && check))
				map[i][j] = rad.d;
		}
	}
}

int main(int argc, char **argv)
{
	FILE *f;
	t_info info;
	t_rad rad;
	int ret;
	char **map;

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
	if (!map)
		return print_error("Error: Operation file corrupted");
	for(int i = 0; i < info.h; i++){
		map[i] = malloc(sizeof(char) * (info.w + 1));
		if (!map[i])
			return print_error("Error: Operation file corrupted");
		for(int j = 0; j < info.w; j++)
			map[i][j] = info.b;
		map[i][info.w] = 0;
	}
	map[info.h] = 0;
	while ((ret = fscanf(f, "%c %f %f %f %c\n", &rad.c, &rad.x, &rad.y, &rad.r, &rad.d)) == 5)
	{
		if (rad.r <= (float)0 || !(rad.c == 'c' || rad.c == 'C'))
			return print_error("Error: Operation file corrupted");
		mini_paint(info, rad, map);		
	}
	if (ret != -1)
		return print_error("Error: Operation file corrupted");
	for(int i = 0; i < info.h; i++){
		for(int j = 0; j < info.w; j++)
			write(1, &map[i][j], 1);
		write(1, "\n", 1);
	}
	for(int i = 0; i <= info.h; i++)
		free(map[i]);
	free(map);
	fclose(f);
	return 0;
}
