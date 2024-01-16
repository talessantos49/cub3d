/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_scenario.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:17:56 by asoler            #+#    #+#             */
/*   Updated: 2024/01/15 21:21:17 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	fish_eye_correction(t_pixel *data, t_ray *ray)
{
	double	correction;

	correction = *data->camera_angle - ray->angle;
	return (cos(correction));
}

void	draw_3d_wall(t_ray *ray, t_pixel *data, int i)
{
	double	wall_row;
	double	center;
	int		j;

	if (ray->len == 1)
	{
		printf("len was 0\n ray: %d\n\n", i);
		return ;
	}

	wall_row = (BLOCK_SIZE * HEIGHT) / ray->len;
	if (wall_row > HEIGHT)
		wall_row = HEIGHT;
	center = (HEIGHT / 2) - (wall_row / 2);
	ray->init.x = (i * 1) + MAP_OFFSET;
	ray->init.y = center;
	ray->end.x = (i * 1) + MAP_OFFSET;
	ray->end.y = (ray->init.y + wall_row);
	j = 0;
	while (j < 1)
	{
		draw_line(ray->init, ray->end, data);
		ray->end.x++;
		ray->init.x++;
		j++;
	}
	// if (i > 135 && i < 145)
	// {
	// 	printf("wall row: %f\tindex: %d\n", wall_row, i);
	// 	printf("len: %d\n", ray->len);
	// }
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

// void	debug_rays(t_ray *ray, int i)
// {
// 	if (i > 137 && i < 140)
// 	{
// 		printf("index: %d\n", i);
// 		printf("len: %d\n", ray->len);
// 		printf("map: y: %d x:%d \n", ray->map.y, ray->map.x);
// 	}
// 	// printf("len: %d\n", ray->len);
// 	// // if (ray->map.y != 1 && ray->map.y != 2 && ray->map.y != 3)
// 	// // {
// 	// printf("index: %d\n\n", i);
// 	// printf("map: y: %d x:%d \n", ray->map.y, ray->map.x);
		
// 	// // }
	
// }

t_ray	*draw_rays(t_point ray_init, t_pixel *data, double angle)
{
	t_ray	*ray;
	int		i;

	i = 0;
	while (i <= N_RAYS /3)
	{
		ray = ray_end_coord(angle, ray_init, data, i);
		// debug_rays(ray, i);
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
