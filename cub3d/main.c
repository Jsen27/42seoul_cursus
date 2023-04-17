#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include "./mlx/mlx.h"

#define MINI_SCALE 0.25 // 미니맵 배율
#define TILE_SIZE 80 // 블럭사이즈
#define MAP_NUM_ROWS 12 // 세로
#define MAP_NUM_COLS 20 // 가로

#define WINDOW_WIDTH (MAP_NUM_COLS * TILE_SIZE)
#define WINDOW_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)

const int mini_map[MAP_NUM_ROWS][MAP_NUM_COLS] = { // 임시
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1},
    {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

typedef struct	s_mlx
{
	void *mlx;
	void *win;
}				t_mlx;

typedef struct	s_img
{
	void	*img;
	int		*data;
	int		bpp;
	int		line_size;
	int		endian;
}				t_img;

void	fill_squares(t_img *map, int x, int y, int color)
{
	int	i;
	int	j;

	j = 0;
	while (j < (int)(MINI_SCALE * TILE_SIZE))
	{
		i = 0;
		while (i < (int)(MINI_SCALE * TILE_SIZE))
		{
			map->data[(int)(MINI_SCALE * WINDOW_WIDTH) * (y + j) + (x + i)] = color;
			i++;
		}
		j++;
	}
}

void	render_map(t_mlx *mlx, t_img *map)
{
	int	col;
	int	row;

	row = 0;
	map->data = (int*)mlx_get_data_addr(map->img, &map->bpp, &map->line_size, &map->endian);
	while(row < MAP_NUM_ROWS)
	{
		col = 0;
		while(col < MAP_NUM_COLS)
		{
			if (mini_map[row][col] == 1)
				fill_squares(map, (int)(MINI_SCALE * TILE_SIZE * col), (int)(MINI_SCALE * TILE_SIZE * row), 0xffffff);
			else
				fill_squares(map, (int)(MINI_SCALE * TILE_SIZE * col), (int)(MINI_SCALE * TILE_SIZE * row), 0x000000);
			col++;
		}
		row++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, map->img, (int)(WINDOW_WIDTH * (1 - MINI_SCALE)), (int)(WINDOW_HEIGHT * (1 - MINI_SCALE)));
}

int main(int argc, char **argv)
{
	t_mlx	mlx;
	t_img	map;
	
	(void)argc;
	(void)argv;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WINDOW_WIDTH, WINDOW_WIDTH, "title");
	map.img = mlx_new_image(mlx.mlx, (int)(MINI_SCALE * WINDOW_WIDTH), (int)(MINI_SCALE * WINDOW_HEIGHT));
	render_map(&mlx, &map);
	mlx_loop(mlx.mlx);

	return 0;
}