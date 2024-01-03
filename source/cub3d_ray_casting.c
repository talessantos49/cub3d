/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_ray_casting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 22:43:57 by asoler            #+#    #+#             */
/*   Updated: 2024/01/03 20:17:04 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_rays_colition_on_x_axis(t_ray *ray, t_pixel *data)
{
	int		i;
	int		flag;

	i = 0;
	while (TRUE)
	{
		if (ray->angle < deeg_to_rad(270) && ray->angle > deeg_to_rad(90))
			calculate_west_rays(ray, i);
		if (ray->angle > deeg_to_rad(270) || ray->angle < deeg_to_rad(90))
			calculate_est_rays(ray, i);
		i++;
		flag = check_wall(ray->map, data);
		if (flag > 0)
			break ;
		else if (flag < 0)
		{
			ray->len = 0;
			break ;
		}
	}
}

void	check_rays_colition_on_y_axis(t_ray *ray, t_pixel *data)
{
	int		i;
	int		flag;

	i = 0;
	while (TRUE)
	{
		if (ray->angle < deeg_to_rad(180))
			calculate_south_rays(ray, i);
		if (ray->angle > deeg_to_rad(180))
			calculate_north_rays(ray, i);
		i++;
		flag = check_wall(ray->map, data);
		if (flag > 0)
			break ;
		else if (flag < 0)
		{
			ray->len = 0;
			break ;
		}
	}
}

t_point	ray_end_coord(double angle, t_point init_coord, t_pixel *data)
{
	t_ray	h_ray;
	t_ray	v_ray;
	t_point	ray_end;

	ft_memset((void *)&ray_end, 0, sizeof(t_point));
	h_ray.init = init_coord;
	h_ray.angle = angle;
	v_ray.init = init_coord;
	v_ray.angle = angle;
	check_rays_colition_on_y_axis(&h_ray, data);
	check_rays_colition_on_x_axis(&v_ray, data);
	if (v_ray.len < h_ray.len)
		ray_end = v_ray.end;
	else if (v_ray.len > h_ray.len)
		ray_end = h_ray.end;
	else
		ray_end = h_ray.end;
	if (!h_ray.len)
		ray_end = v_ray.end;
	if (!v_ray.len)
		ray_end = h_ray.end;
	return (ray_end);
}

void	draw_rays(t_point init_ray, t_pixel *data, double init_angle)
{
	t_point	end_ray;
	int		i;

	i = 0;
	end_ray = init_ray;
	while (i <= N_RAYS)
	{
		end_ray = ray_end_coord(init_angle, init_ray, data);
		draw_line(init_ray, end_ray, data);
		init_angle += deeg_to_rad(VIEW_RANGE) / N_RAYS;
		if (init_angle > deeg_to_rad(360))
			init_angle -= deeg_to_rad(360);
		end_ray = init_ray;
		i++;
	}
}

void	ray_casting(t_point camera, t_pixel *data)
{
	int		bckp_color;
	double	init_angle;

	init_angle = *data->camera_angle - deeg_to_rad(VIEW_RANGE / 2);
	if (init_angle < 0)
		init_angle += deeg_to_rad(360);
	draw_circle_viewer(camera, data);
	bckp_color = data->line_color;
	data->line_color = create_trgb(0, 255, 255, 255);
	draw_rays(camera, data, init_angle);
	data->line_color = bckp_color;
}
