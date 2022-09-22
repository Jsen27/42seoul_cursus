/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:39:29 by sehjung           #+#    #+#             */
/*   Updated: 2022/09/22 22:08:03 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

//기존 mlx_pixel_put은 너무 느려서 다시만듬
void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main()
{
	void *test_mlx = mlx_init();
	void *test_win = mlx_new_window(test_mlx, 1920, 1080, "testwindow");
	t_data img;
	img.img = mlx_new_image(test_mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	//초기화완료
	
	for (int i = 0; i < 500; i++)
	{
		my_mlx_pixel_put(&img, i, i, 0x00FF0000 + ( i * 100));
		my_mlx_pixel_put(&img, i, 0, 0x00FF0000 + ( i * 100));
		my_mlx_pixel_put(&img, 0, i, 0x00FF0000 + ( i * 100));
	}
	//my_mlx_pixel_put(&img, 10, 10, 0x00FF0000);
	mlx_put_image_to_window(test_mlx, test_win, img.img, 0, 0);

	mlx_loop(test_mlx);
	


	return 0;
}