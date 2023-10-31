#include "color_studies.h"
#define CUBE_SIZE 100
#define CUBE_X (WIDTH - CUBE_SIZE) / 2
#define CUBE_Y (HEIGHT - CUBE_SIZE) / 2
#define CUBE_DEPTH 50

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	put_pixel(t_mlx *mlx, int x, int y, int trgb, t_data *img)
{
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
								&img->endian);
	my_mlx_pixel_put(img, x, y, trgb);
}

int	paint_something(t_mlx *mlx)
{
	int	green = create_trgb(0, 0, 255, 0);
	int	blue = create_trgb(0, 0, 0, 255);
	int line_color = create_trgb(0, 255, 0, 0);
	t_data	img;
	t_data	temp_img;

	img.img = mlx_new_image(mlx->init, WIDTH, HEIGHT);
	temp_img.img = mlx_new_image(mlx->init, WIDTH, HEIGHT);
	for (int x = 0; x < WIDTH; x++)
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			int z = abs(x - CUBE_X - CUBE_SIZE / 2) + abs(y - CUBE_Y - CUBE_SIZE / 2);
			if (x >= CUBE_X && x < CUBE_X + CUBE_SIZE && \
				y >= CUBE_Y && y < CUBE_Y + CUBE_SIZE && \
				z <= CUBE_DEPTH)
			{
				if (x == CUBE_X || x == CUBE_X + CUBE_SIZE - 1 ||
					y == CUBE_Y || y == CUBE_Y + CUBE_SIZE - 1 ||
					z == 0 || z == CUBE_DEPTH)
					put_pixel(mlx, x, y, line_color, &img);
				// else
					// put_pixel(mlx, x, y, green, &img);
			}
			// else
			// 	put_pixel(mlx, x, y, blue, &img);
		}
	}
	memcpy((void *)&temp_img,(void *)&img, sizeof(t_data));
	mlx_put_image_to_window(mlx->init, mlx->window, temp_img.img, 0, 0);
}
