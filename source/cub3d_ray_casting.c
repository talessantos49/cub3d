/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_ray_casting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 22:43:57 by asoler            #+#    #+#             */
/*   Updated: 2024/01/14 12:12:10 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	debug_rays(t_ray *ray, int i, char *str);

void	check_rays_colition_on_x_axis(t_ray *ray, t_pixel *data, int j)
{
	int		i;
	int		flag;

	i = 0;
	while (TRUE)
	{
		if (ray->angle < deeg_to_rad(270) && ray->angle > deeg_to_rad(90)) {
			calculate_west_rays(ray, i);
			debug_rays(ray, j, "west");
		}
		if (ray->angle > deeg_to_rad(270) || ray->angle < deeg_to_rad(90)){
			calculate_est_rays(ray, i);
			debug_rays(ray, j, "est");
		}
		i++;
		flag = check_collition(ray->map, data->mlx);
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
		flag = check_collition(ray->map, data->mlx);
		if (flag > 0)
			break ;
		else if (flag < 0)
		{
			ray->len = 0;
			break ;
		}
	}
}

void	choose_final_ray(t_ray *ray, t_ray *h_ray, t_ray *v_ray)
{
	if (v_ray->len < h_ray->len)
		memcpy((void *)ray, (void *)v_ray, sizeof(t_ray));
	else if (v_ray->len > h_ray->len)
		memcpy((void *)ray, (void *)h_ray, sizeof(t_ray));
	else
		memcpy((void *)ray, (void *)h_ray, sizeof(t_ray));
	if (!h_ray->len)
		memcpy((void *)ray, (void *)v_ray, sizeof(t_ray));
	if (!v_ray->len)
		memcpy((void *)ray, (void *)h_ray, sizeof(t_ray));
}

void	debug_rays(t_ray *ray, int i, char *str)
{
	if (i > 137 && i < 140)
	{
		printf("\n%s\n", str);
		printf("index: %d\n", i);
		printf("len: %d\n", ray->len);
		printf("map: y: %d x:%d \n", ray->map.y, ray->map.x);
		printf("ray: end y: %d en x:%d \n", ray->end.y, ray->end.x);
	}
	// printf("len: %d\n", ray->len);
	// // if (ray->map.y != 1 && ray->map.y != 2 && ray->map.y != 3)
	// // {
	// printf("index: %d\n\n", i);
		
	// // }
	
}

t_ray	*ray_end_coord(double angle, t_point init_coord, t_pixel *data, int i)
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
	check_rays_colition_on_x_axis(&v_ray, data,i);
	choose_final_ray(ray, &h_ray, &v_ray);
	if (ray->end.x == h_ray.end.x && ray->end.y == h_ray.end.y)
		data->line_color = create_trgb(0, 255, 0, 0);
	else if (ray->end.x == v_ray.end.x && ray->end.y == v_ray.end.y)
		data->line_color = create_trgb(0, 150, 0, 0);
	return (ray);
}

void	ray_casting(t_point camera, t_pixel *data)
{
	double	angle;

	angle = *data->camera_angle - deeg_to_rad(VIEW_RANGE / 2);
	if (angle < 0)
		angle += deeg_to_rad(360);
	// draw_circle_viewer(camera, data);
	draw_rays(camera, data, angle);
	if (data->mlx->viewer_dir)
		free(data->mlx->viewer_dir);
	data->mlx->viewer_dir = ray_end_coord(*data->camera_angle, camera, data,0);
}
