#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_info
{
	int	w;
	int	h;
	char b;
}				t_info;

typedef struct s_rect
{
	char r;
	float x;
	float y;
	float w;
	float h;
	char c;
}				t_rect;

int	ft_strlen(char *str)
{
	int i;

	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int print_error(char *str)
{
	ft_putstr(str);
	return (1);
}

int main(int argc, char **argv)
{
	t_info info;
	t_rect rec;
	FILE	*file;
	char	**map;
	int		ret;

	if (argc != 2)
		return (print_error("Error: argument"));
	file = fopen(argv[1], "r");
	if (!file)
		return (print_error("Error: Operation file corrupted"));
	if (fscanf(file, "%d %d %c\n", &info.w, &info.h, &info.b) != 3)
		return (print_error("Error: Operation file corrupted"));
	if (info.w <= 0 || info.w > 300 || info.h <= 0 || info.h > 300)
		return (print_error("Error: Operation file corrupted"));
	map = malloc(sizeof(char) * info.h + 1);
	if (!map)
		return (1);
	for (int i = 0; i < info.h; i++)
	{
		map[i] = malloc(sizeof(char) * info.w + 1);
		if (!map[i])
			return (1);
		for (int j = 0; j < info.w; j++)
			map[i][j] = info.b;
		map[i][info.w] = 0;
	}
	map[info.h] = 0;
	while (ret = fscanf(file, "%c %f %f %f %f %c\n", &rec.r, &rec.x, &rec.y, &rec.w, &rec.h, &rec.c) == 6)
	{
		
	}
	if (ret == -1)
		return (print_error("Error: Operation file corrupted"));


	
	return 0;
}
