#include "color_studies.h"
#define SQUARE_SIZE 200
#define SQUARE_SIDE 100

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
	t_data	img;
	t_data	temp_img;

	img.img = mlx_new_image(mlx->init, WIGTH, HEIGHT);
	temp_img.img = mlx_new_image(mlx->init, WIGTH, HEIGHT);
	for (int x = 0; x < WIGTH; x++)
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			if (x >= SQUARE_SIZE && x <= SQUARE_SIZE + SQUARE_SIDE && y >= SQUARE_SIZE && y <= SQUARE_SIZE + SQUARE_SIDE)
				put_pixel(mlx, x, y, green, &img);
			else
				put_pixel(mlx, x, y, blue, &img);
		}
	}
	memcpy((void *)&temp_img,(void *)&img, sizeof(t_data));
	mlx_put_image_to_window(mlx->init, mlx->window, temp_img.img, 0, 0);
}
