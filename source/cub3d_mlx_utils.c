/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_mlx_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:47:45 by asoler            #+#    #+#             */
/*   Updated: 2024/01/14 18:47:46 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

int	put_pixel(t_point point, int trgb, t_data *img)
{
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
									&img->line_length, &img->endian);
	my_mlx_pixel_put(img, point.x, point.y, trgb);
	return (0);
}

int	render_image(t_mlx *mlx)
{
	t_data	img;
	t_data	temp_img;
	t_pixel	data;

	memset((void *)&data, 0, sizeof(t_pixel));
	img.img = mlx_new_image(mlx->init, WIDTH, HEIGHT);
	temp_img.img = mlx_new_image(mlx->init, WIDTH, HEIGHT);
	data.img = &img;
	mlx->data_img = img.img;
	mlx->temp_img = temp_img.img;
	data.mlx = mlx;
	data.camera_angle = &mlx->camera_angle;
	data.line_color = create_trgb(0, 56, 25, 90);
	mlx->camera_pos = draw_scenario(&data);
	memcpy((void *)&temp_img, (void *)&img, sizeof(t_data));
	mlx_put_image_to_window(mlx->init, mlx->window, temp_img.img, 0, 0);
	mlx_destroy_image(mlx->init, mlx->data_img);
	mlx_destroy_image(mlx->init, mlx->temp_img);
	return (0);
}
