/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_mlx_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 21:04:20 by asoler            #+#    #+#             */
/*   Updated: 2023/12/02 10:32:39 by asoler           ###   ########.fr       */
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

	img.img = mlx_new_image(mlx->init, WIDTH, HEIGHT);
	temp_img.img = mlx_new_image(mlx->init, WIDTH, HEIGHT);
	data.img = &img;
	data.mlx = mlx;
	data.line_color = create_trgb(0, 0, 255, 0);
	ray_casting(&data);
	memcpy((void *)&temp_img, (void *)&img, sizeof(t_data));
	mlx_put_image_to_window(mlx->init, mlx->window, temp_img.img, 0, 0);
	return (0);
}
