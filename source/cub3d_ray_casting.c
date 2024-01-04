/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_ray_casting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 22:43:57 by asoler            #+#    #+#             */
/*   Updated: 2024/01/03 23:01:02 by asoler           ###   ########.fr       */
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

t_ray	*ray_end_coord(double angle, t_point init_coord, t_pixel *data)
{
	t_ray	h_ray;
	t_ray	v_ray;
	t_ray	*ray;

	ray = ft_calloc(1, sizeof(t_ray));
	h_ray.init = init_coord;
	h_ray.angle = angle;
	v_ray.init = init_coord;
	v_ray.angle = angle;
	check_rays_colition_on_y_axis(&h_ray, data);
	check_rays_colition_on_x_axis(&v_ray, data);
	if (v_ray.len < h_ray.len)
		memcpy((void *)ray, (void *)&v_ray, sizeof(t_ray));
	else if (v_ray.len > h_ray.len)
		memcpy((void *)ray, (void *)&h_ray, sizeof(t_ray));
	else
		memcpy((void *)ray, (void *)&h_ray, sizeof(t_ray));
	if (!h_ray.len)
		memcpy((void *)ray, (void *)&v_ray, sizeof(t_ray));
	if (!v_ray.len)
		memcpy((void *)ray, (void *)&h_ray, sizeof(t_ray));
	return (ray);
}

void	draw_3d_wall(t_ray *ray, t_pixel *data)
{
	double	wall_row;
	double	center;
	t_point	top_init;
	t_point	botoom_init;
	t_point	top_end;
	t_point	botoom_end;

	wall_row = (BLOCK_SIZE * HEIGHT) / ray->len;
	if (wall_row > HEIGHT)
		wall_row = HEIGHT;
	center = (HEIGHT / 2) - (wall_row / 2);
	top_init.x = WIDTH / 2;
	top_init.y = center;
	top_end = top_init;
	top_end.x += 8;
	botoom_init.x = WIDTH / 2;
	botoom_init.y = wall_row;
	botoom_end = botoom_init;
	botoom_end.x += 8;
	draw_line(top_init, top_end, data);
	draw_line(botoom_init, botoom_end, data);
}

t_ray	*draw_rays(t_point init_ray, t_pixel *data, double init_angle)
{
	t_ray	*ray;
	int		i;

	i = 0;
	while (i <= N_RAYS)
	{
		ray = ray_end_coord(init_angle, init_ray, data);
		draw_line(init_ray, ray->end, data);
		init_angle += deeg_to_rad(VIEW_RANGE) / N_RAYS;
		if (init_angle > deeg_to_rad(360))
			init_angle -= deeg_to_rad(360);
		ray->end = init_ray;
		// draw_3d_wall(ray, data);
		printf("ray len %d\n", ray->len);
		i++;
		free(ray);
	}
	return(ray);
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
