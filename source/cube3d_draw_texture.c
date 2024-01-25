/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_draw_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:05:37 by asoler            #+#    #+#             */
/*   Updated: 2024/01/25 13:01:20 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	choose_texture_by_angle(t_ray *ray, t_point text, t_mlx *mlx)
{
	int	color;

	if (ray->is_hor)
	{
		if (ray->angle < deeg_to_rad(180))
			color = mlx->south_text[text.y][text.x];
		if (ray->angle > deeg_to_rad(180))
			color = mlx->north_text[text.y][text.x];
	}
	else
	{
		if (ray->angle < deeg_to_rad(270) && ray->angle > deeg_to_rad(90))
			color = mlx->west_text[text.y][text.x];
		if (ray->angle > deeg_to_rad(270) || ray->angle < deeg_to_rad(90))
			color = mlx->est_text[text.y][text.x];
	}
	return (color);
}

void	draw_texture(t_ray *ray, t_pixel *data)
{
	int		size;
	int		bckp_color;
	t_point	p;
	t_point	text;
	int		i;

	i = 0;
	p = ray->init;
	size = ray->end.y - ray->init.y;
	bckp_color = data->line_color;
	while (i < size)
	{
		text.x = p.x % BLOCK_SIZE;
		text.y = (BLOCK_SIZE * (p.y - ray->init.y)) / size;
		data->line_color = choose_texture_by_angle(ray, text, data->mlx);
		call_put_pixel(p.x, p.y, data, 0);
		p.y++;
		i++;
	}
	data->line_color = bckp_color;
}
