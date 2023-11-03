#include "color_studies.h"
#define VERTICE_1 {128, 128}
#define VERTICE_2 {256, 128}
#define VERTICE_3 {128, 256}
#define VERTICE_4 {256, 256}
#define VERTICE_5 {160, 320}
#define VERTICE_6 {320, 320}
#define VERTICE_7 {320, 160}
// aqui encima conversão para plano 480 * 480
// Vértice 1 (4,4)
// Vértice 2 (8,4)
// Vértice 3 (4,8)
// Vértice 4 (8,8)
// Vértice 5 (5, 10)
// Vértice 6 (10, 10)
// Vértice 7 (10, 5)

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
	t_pixel	data;
	t_point	point1 = VERTICE_1;
	t_point	point2 = VERTICE_2;
	t_point	point3 = VERTICE_3;
	t_point	point4 = VERTICE_4;
	t_point	point5 = VERTICE_5;
	t_point	point6 = VERTICE_6;
	t_point	point7 = VERTICE_7;

	img.img = mlx_new_image(mlx->init, WIDTH, HEIGHT);
	temp_img.img = mlx_new_image(mlx->init, WIDTH, HEIGHT);
	data.img = &img;
	data.mlx = mlx;
	data.line_color = green;
	bresenham(point3, point4, &data);
	bresenham(point1, point2, &data);
	data.line_color = blue;
	bresenham(point3, point5, &data);
	data.line_color = green;
	bresenham(point5, point6, &data);
	bresenham(point2, point7, &data);

	data.line_color = blue;
	bresenham(point4, point6, &data);
	// bresenham(point6, point7, &data);
	// bresenham(point1, point3, &data);
	// bresenham(point1, point3, &data);

	memcpy((void *)&temp_img,(void *)&img, sizeof(t_data));
	mlx_put_image_to_window(mlx->init, mlx->window, temp_img.img, 0, 0);
}
