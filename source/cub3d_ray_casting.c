/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_ray_casting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 22:43:57 by asoler            #+#    #+#             */
/*   Updated: 2024/01/03 17:17:30 by asoler           ###   ########.fr       */
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
		if (ray->angle < ONE_DEGREE * 270 && ray->angle > ONE_DEGREE * 90)
			calculate_west_rays(ray, i);
		if (ray->angle > ONE_DEGREE * 270 || ray->angle < ONE_DEGREE * 90)
			calculate_est_rays(ray, i);
		i++;
		flag = check_wall(ray->map, data);
		if (flag > 0)
		{
			printf("\nV-i = %d\n", i - 1);
			printf("ray angle: %f", ray->angle * ONE_DEGREE);
			break ;
		}
		else if (flag < 0)
		{
			ray->len = 0;
			break ;
		}
	}
	printf("\nH-i = %d\n", i - 1);
	printf("ray angle:%f", ray->angle * ONE_DEGREE);
}

void	check_rays_colition_on_y_axis(t_ray *ray, t_pixel *data)
{
	int		i;
	int		flag;

	i = 0;
	while (TRUE)
	{
		if (ray->angle < ONE_DEGREE * 180)
			calculate_south_rays(ray, i);
		if (ray->angle > ONE_DEGREE * 180)
			calculate_north_rays(ray, i);
		i++;
		flag = check_wall(ray->map, data);
		if (flag > 0)
		{
			printf("\nV-i = %d\n", i - 1);
			printf("ray angle: %f", ray->angle * ONE_DEGREE);
			break ;
		}
		else if (flag < 0)
		{
			ray->len = 0;
			break ;
		}
	}
	printf("\nH-i = %d\n", i - 1);
	printf("ray angle:%f", ray->angle * ONE_DEGREE);
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
	printf("\n====debug===\n");
	printf("vray_end: (%d, %d)\n", v_ray.end.x, v_ray.end.y);
	printf("hray_end: (%d, %d)\n", h_ray.end.x, h_ray.end.y);
	printf("vray_len: %d\n", v_ray.len);
	printf("hray_len: %d\n", h_ray.len);
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
	printf("ray end: (%d, %d)\n", ray_end.x, ray_end.y);
	return (ray_end);
}

void	draw_rays(t_point coord,t_pixel *data, double final_angle, double init_angle)
{
	t_point	dir;

	dir = coord;
	while (init_angle < final_angle)
	{
		dir = ray_end_coord(init_angle, coord, data);
		draw_line(coord, dir, data);
		init_angle += ONE_DEGREE;
		dir = coord;
	}
}

void	ray_casting(t_point camera, t_pixel *data)
{
	int	bckp_color;

	draw_circle_viewer(camera, data);
	bckp_color = data->line_color;
	data->line_color = create_trgb(0, 255, 255, 255);
	draw_rays(camera, data, *data->camera_angle + ONE_DEGREE * 30, *data->camera_angle - ONE_DEGREE * 30); //draw view range
	data->line_color = bckp_color;
}
