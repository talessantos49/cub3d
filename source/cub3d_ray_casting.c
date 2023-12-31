/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_ray_casting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 22:43:57 by asoler            #+#    #+#             */
/*   Updated: 2023/12/31 19:56:50 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_majorx_axis_ray(t_point camera, t_pixel *data)
{
	double	ray_angle;
	double	atan;
	t_point	ray;
	t_point	offset;
	t_point	map;

	ray_angle = *data->camera_angle;
	while (TRUE)
	{
		atan = -1 / tan(ray_angle);
		if (ray_angle > M_PI)
		{
			ray.y = (( camera.y >> 6) << 6) - 0.0001;
			ray.x = (camera.y - ray.y) * atan - camera.x;
			offset.y = - BLOCK_SIZE;
			offset.x = - offset.y * atan;
		}
		if (ray_angle < M_PI)
		{
			ray.y = ((camera.y >> 6) << 6) + BLOCK_SIZE;
			ray.x = (camera.y - ray.y) * atan - camera.x;
			offset.y = BLOCK_SIZE;
			offset.x = - offset.y * atan;
		}
		while (TRUE)
		{
			// if (hit_wall())
			map.x = ((ray.x >> 6) / BLOCK_SIZE);
			map.y = ((ray.y >> 6) / BLOCK_SIZE);
			if (data->mlx->map->map[map.y][map.x] == '1')
				break ;
			else
			{
				ray.x += offset.x;
				ray.y += offset.y;
			}
		}
		draw_block(ray, data, VIEWER_SIZE);
		draw_line(camera, ray, data);
		break ;
	}
}

void	ray_casting(t_point camera, t_pixel *data)
{
	draw_majorx_axis_ray(camera, data);
}
