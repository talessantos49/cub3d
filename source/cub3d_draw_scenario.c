/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_scenario.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:17:56 by asoler            #+#    #+#             */
/*   Updated: 2024/01/26 19:59:17 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	fish_eye_correction(t_pixel *data, t_ray *ray)
{
	double	correction;

	correction = *data->camera_angle - ray->angle;
	return (cos(correction));
}

void	draw_3d_wall(t_ray *ray2d, t_pixel *data, int i)
{
	double	wall_row;
	double	center;
	t_ray	ray;

	ft_memcpy(&ray, ray2d, sizeof(t_ray));
	wall_row = (BLOCK_SIZE * HEIGHT) / ray2d->len;
	if (wall_row > HEIGHT)
		wall_row = HEIGHT;
	center = (HEIGHT / 2) - (wall_row / 2);
	ray.init.x = i;
	ray.init.y = center;
	ray.end.x = i;
	ray.end.y = ray.init.y + wall_row;
	draw_texture(ray, ray2d, data);
	draw_ceiling(ray, data);
	draw_floor(ray, data);
}

void	cal_next_ray_angle(double *angle)
{
	*angle += deeg_to_rad(VIEW_RANGE) / N_RAYS;
	if (*angle > deeg_to_rad(360))
		*angle -= deeg_to_rad(360);
}

void	draw_2d_rays(t_pixel *data, t_ray *ray)
{
	int		bckp_color;

	bckp_color = data->line_color;
	data->line_color = create_trgb(0, 255, 255, 255);
	draw_line(ray->init, ray->end, data);
	data->line_color = bckp_color;
}

t_ray	*draw_rays(t_point ray_init, t_pixel *data, double angle)
{
	t_ray	*ray;
	int		i;

	i = 0;
	while (i < N_RAYS)
	{
		ray = ray_end_coord(angle, ray_init, data);
		ray->len *= fish_eye_correction(data, ray);
		if (!ray->len)
			ray->len = 1;
		draw_3d_wall(ray, data, i);
		free(ray);
		cal_next_ray_angle(&angle);
		i++;
	}
	return (ray);
}
