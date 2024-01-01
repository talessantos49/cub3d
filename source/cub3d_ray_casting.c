/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_ray_casting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 22:43:57 by asoler            #+#    #+#             */
/*   Updated: 2024/01/01 12:57:38 by asoler           ###   ########.fr       */
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
			ray.y = camera.y - 0.0001;
			ray.x = (camera.y - ray.y) * atan - camera.x;
			offset.y = - BLOCK_SIZE;
			offset.x = - offset.y * atan;
		}
		if (ray_angle < M_PI)
		{
			ray.y = camera.y + BLOCK_SIZE;
			ray.x = (camera.y - ray.y) * atan - camera.x;
			offset.y = BLOCK_SIZE;
			offset.x = - offset.y * atan;
		}
		while (TRUE)
		{
			// if (hit_wall())
			map.x = ((ray.x / BLOCK_SIZE) / BLOCK_SIZE);
			map.y = ((ray.y / BLOCK_SIZE) / BLOCK_SIZE);
			if (data->mlx->map->map[map.y][map.x] == '1')
				break ;
			else
			{
				ray.x += offset.x;
				ray.y += offset.y;
			}
		}
		draw_block(ray, data, VIEWER_SIZE);
		// draw_line(camera, ray, data);
		draw_line(ray, camera, data);
		break ;
	}
}

void	draw_rays(t_point coord,t_pixel *data, double final_angle, double init_angle, int ray_size)
{
	t_point	dir;

	dir = coord;
	while (init_angle < final_angle)
	{
		dir.x += ray_size * cos(init_angle);
		dir.y += ray_size * sin(init_angle);
		draw_line(coord, dir, data);
		init_angle += ONE_DEGREE;
		dir = coord;
	}
}

void	ray_casting(t_point camera, t_pixel *data)
{
	int	bckp_color;

	bckp_color = data->line_color;
	draw_rays(camera, data, ONE_DEGREE * 360, 0, LINE_SIZE / 3); //draw viewer
	data->line_color = create_trgb(0, 255, 255, 50);
	draw_rays(camera, data, *data->camera_angle + ONE_DEGREE * 30, *data->camera_angle - ONE_DEGREE * 30, LINE_SIZE * 4); //draw view range
	data->line_color = bckp_color;
	// draw_majorx_axis_ray(camera, data);
}
