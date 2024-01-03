/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_ray_casting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 22:43:57 by asoler            #+#    #+#             */
/*   Updated: 2024/01/03 13:46:44 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_rays_colition_on_x_axis(t_point camera, t_pixel *data, int *h_ray_length, t_point *h_ray_end, double ray_angle)
{
	t_point	map;
	int		i = 0;
	int		flag = 0;

	*h_ray_length = 0;
	ft_memset((void *)h_ray_end, 0, sizeof(t_point));
	while (TRUE)
	{
		if (ray_angle < ONE_DEGREE * 270 && ray_angle > ONE_DEGREE * 90) // looking west
		{
			h_ray_end->x = ((camera.x - (VIEWER_SIZE / 2)) - VIEWER_SIZE) - (BLOCK_SIZE * i);
			*h_ray_length = (h_ray_end->x - camera.x) / cos(ray_angle);
			h_ray_end->y = camera.y + abs(*h_ray_length) * sin(ray_angle);
			map.x = ((h_ray_end->x - BLOCK_SIZE) / BLOCK_SIZE);
			map.y = (h_ray_end->y - (h_ray_end->y % BLOCK_SIZE)) / BLOCK_SIZE;
		}
		if (ray_angle > ONE_DEGREE * 270 || ray_angle < ONE_DEGREE * 90) //looking est
		{
			h_ray_end->x = ((camera.x + (VIEWER_SIZE / 2)) + VIEWER_SIZE) + (BLOCK_SIZE * i);
			*h_ray_length = (h_ray_end->x - camera.x) / cos(ray_angle);
			h_ray_end->y = camera.y + abs(*h_ray_length) * sin(ray_angle);
			map.x = h_ray_end->x / BLOCK_SIZE;
			map.y = (h_ray_end->y - (h_ray_end->y % BLOCK_SIZE)) / BLOCK_SIZE;
		}
		i++;
		flag = check_wall(map, data);
		if (flag > 0)
			break ;
		else if (flag < 0)
		{
			*h_ray_length = 0;
			return (-1);
		}
	}
	printf("\nH-i = %d\n", i - 1);
	printf("ray angle:%f", ray_angle * ONE_DEGREE);
	return (0);
}

int	check_rays_colition_on_y_axis(t_point camera, t_pixel *data, int *v_ray_length, t_point *v_ray_end, double ray_angle)
{
	t_point	map;
	int		i = 0;
	int		flag=0;

	*v_ray_length = 0;
	ft_memset((void *)v_ray_end, 0, sizeof(t_point));
	while (TRUE)
	{
		if (ray_angle < M_PI) //looking south
		{
			v_ray_end->y = (camera.y + (VIEWER_SIZE / 2) + VIEWER_SIZE) + (BLOCK_SIZE * i);
			*v_ray_length = (v_ray_end->y - camera.y) / sin(ray_angle);
			v_ray_end->x = camera.x + abs(*v_ray_length) * cos(ray_angle);
			map.y = v_ray_end->y / BLOCK_SIZE;
			map.x = (v_ray_end->x - (v_ray_end->x % BLOCK_SIZE)) / BLOCK_SIZE;
		}
		if (ray_angle > M_PI) // looking north
		{
			v_ray_end->y = ((camera.y - (VIEWER_SIZE / 2)) - VIEWER_SIZE) - (BLOCK_SIZE * i);
			*v_ray_length = (v_ray_end->y - camera.y) / sin(ray_angle);
			v_ray_end->x = camera.x + abs(*v_ray_length) * cos(ray_angle);
			map.y = ((v_ray_end->y - BLOCK_SIZE) / BLOCK_SIZE);
			map.x = (v_ray_end->x - (v_ray_end->x % BLOCK_SIZE)) / BLOCK_SIZE;
		}
		i++;
		flag = check_wall(map, data);
		if (flag > 0)
			break ;
		else if (flag < 0)
		{
			*v_ray_length = 0;
			return (-1);
		}
	}
	printf("\nV-i = %d\n", i - 1);
	printf("ray angle: %f", ray_angle * ONE_DEGREE);
	return (0);
}

t_point	ray_end_coord(double angle, t_point init_coord, t_pixel *data)
{
	t_point	ray_end;
	ft_memset((void *)&ray_end, 0, sizeof(t_point));

	int		h_ray_length;
	t_point	h_ray_end;
	check_rays_colition_on_y_axis(init_coord, data, &h_ray_length, &h_ray_end, angle);

	int		v_ray_length;
	t_point	v_ray_end;
	check_rays_colition_on_x_axis(init_coord, data, &v_ray_length, &v_ray_end, angle);

	printf("\n====debug===\n");
	printf("vray_end: (%d, %d)\n", v_ray_end.x, v_ray_end.y);
	printf("hray_end: (%d, %d)\n", h_ray_end.x, h_ray_end.y);
	printf("vray_len: %d\n", v_ray_length);
	printf("hray_len: %d\n", h_ray_length);
	if (v_ray_length < h_ray_length)
		ray_end = v_ray_end;
	else if (v_ray_length > h_ray_length)
		ray_end = h_ray_end;
	else
		ray_end = h_ray_end;
	if (!h_ray_length)
		ray_end = v_ray_end;
	if (!v_ray_length)
		ray_end = h_ray_end;
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

	draw_circle_viewer(camera, data); //draw viewer
	bckp_color = data->line_color;
	data->line_color = create_trgb(0, 255, 255, 255);
	draw_rays(camera, data, *data->camera_angle + ONE_DEGREE * 30, *data->camera_angle - ONE_DEGREE * 30); //draw view range
	data->line_color = bckp_color;
}
