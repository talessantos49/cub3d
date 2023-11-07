/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_mlx_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 21:04:20 by asoler            #+#    #+#             */
/*   Updated: 2023/11/04 22:16:54 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	put_pixel(t_mlx *mlx, t_point point, int trgb, t_data *img)
{
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
									&img->line_length, &img->endian);
	my_mlx_pixel_put(img, point.x, point.y, trgb);
}

int	paint_something(t_mlx *mlx)
{
	t_data	img;
	t_data	temp_img;
	t_pixel	data;
///// this is temporary: hand made cube coordinates ///////
	t_point	point1 = VERTICE_1;
	t_point	point2 = VERTICE_2;
	t_point	point3 = VERTICE_3;
	t_point	point4 = VERTICE_4;
	t_point	point5 = VERTICE_5;
	t_point	point6 = VERTICE_6;
	t_point	point7 = VERTICE_7;
//////////////////////////////

	img.img = mlx_new_image(mlx->init, WIDTH, HEIGHT);
	temp_img.img = mlx_new_image(mlx->init, WIDTH, HEIGHT);
	data.img = &img;
	data.mlx = mlx;
	data.line_color = create_trgb(0, 0, 255, 0);
/////this is temporary: hand made cube coordinates ///////
	bresenham(point3, point5, &data);
	bresenham(point5, point6, &data);
	bresenham(point2, point7, &data);
	bresenham(point7, point6, &data);
	bresenham(point4, point6, &data);
	bresenham(point3, point4, &data);
	bresenham(point1, point2, &data);
	bresenham(point1, point3, &data);
	bresenham(point2, point4, &data);
//////////////////////////////
	memcpy((void *)&temp_img,(void *)&img, sizeof(t_data));
	mlx_put_image_to_window(mlx->init, mlx->window, temp_img.img, 0, 0);
}
