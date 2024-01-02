/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_ray_casting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 22:43:57 by asoler            #+#    #+#             */
/*   Updated: 2024/01/02 00:52:02 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_wall(t_point map, t_pixel *data)
{
	if (data->mlx->map->map[map.y][map.x] == '1')
	{
		printf("\nfound wall at map[%d][%d]\n", map.y, map.x);
		return (TRUE);
	}
	return (FALSE);
}

t_point	check_rays_colition_on_x_axis(t_point camera, t_pixel *data, int *h_ray_length)
{
	double	ray_angle;
	t_point	h_ray_end;
	t_point	map;
	int		i = 0;

	ray_angle = *data->camera_angle; //substituir por ray angle, que virá dinamicamente de draw rays
	*h_ray_length = 0;
	ft_memset((void *)&h_ray_end, 0, sizeof(t_point));
	while (TRUE)
	{
		if (ray_angle == ONE_DEGREE * 90 || ray_angle == ONE_DEGREE * 270)
			return (h_ray_end);
		if (ray_angle < ONE_DEGREE * 270 && ray_angle > ONE_DEGREE * 90) // looking west
		{
			h_ray_end.x = ((camera.x - (VIEWER_SIZE / 2)) - VIEWER_SIZE) - (BLOCK_SIZE * i);
			*h_ray_length = (h_ray_end.x - camera.x) / cos(ray_angle); // sometimes is too long
			h_ray_end.y = camera.y + abs(*h_ray_length) * sin(ray_angle);
			map.x = ((h_ray_end.x - BLOCK_SIZE) / BLOCK_SIZE);
			map.y = (h_ray_end.y - (h_ray_end.y % BLOCK_SIZE)) / BLOCK_SIZE;
		}
		if (ray_angle > ONE_DEGREE * 270 || ray_angle < ONE_DEGREE * 90) //looking est
		{
			h_ray_end.x = ((camera.x + (VIEWER_SIZE / 2)) + VIEWER_SIZE) + (BLOCK_SIZE * i);
			*h_ray_length = (h_ray_end.x - camera.x) / cos(ray_angle); // sometimes is too long
			h_ray_end.y = camera.y + abs(*h_ray_length) * sin(ray_angle);
			map.x = h_ray_end.x / BLOCK_SIZE;
			map.y = (h_ray_end.y - (h_ray_end.y % BLOCK_SIZE)) / BLOCK_SIZE;
		}
		i++;
		printf("\n collition index %d\n", i);
		printf("\ncheck colition at map[%d][%d] = %c\n", map.y, map.x, data->mlx->map->map[map.y][map.x]);
		if (check_wall(map, data)) //segfault - undeterminete values of map
			break ;
	}
	// return (h_ray_end);
	int	bckp_color;

	bckp_color = data->line_color;
	data->line_color = create_trgb(0, 255, 255, 0);
	draw_line(camera, h_ray_end, data);
	data->line_color = bckp_color;
	printf("\t|end coord| radians | camera |\n\t| x = %d |\n\t| y = %d |\n\t\t  | %f |\n\t\t\t\t|x: %d y: %d\n\t\t\t\t\t|cos: %f sin: %f |\n=====\n",\
		h_ray_end.x, h_ray_end.y, *data->camera_angle, camera.x, camera.y,cos(*data->camera_angle),sin(*data->camera_angle));
	return (h_ray_end);
}

t_point	check_rays_colition_on_y_axis(t_point camera, t_pixel *data, int *v_ray_length)
{
	double	ray_angle;
	t_point	v_ray_end;
	t_point	map;
	int		i = 0;

	ray_angle = *data->camera_angle; //substituir por ray angle, que virá dinamicamente de draw rays
	*v_ray_length = 0;
	ft_memset((void *)&v_ray_end, 0, sizeof(t_point));
	while (TRUE)
	{
		if (!ray_angle || ray_angle == ONE_DEGREE * 360)
			return (v_ray_end);
		if (ray_angle < M_PI) //looking south
		{
			v_ray_end.y = (camera.y + (VIEWER_SIZE / 2) + VIEWER_SIZE) + BLOCK_SIZE* i;
			*v_ray_length = (v_ray_end.y - camera.y) / sin(ray_angle); // sometimes is too long
			v_ray_end.x = camera.x + abs(*v_ray_length) * cos(ray_angle);
			map.y = v_ray_end.y / BLOCK_SIZE;
			map.x = (v_ray_end.x - (v_ray_end.x % BLOCK_SIZE)) / BLOCK_SIZE;
		}
		if (ray_angle > M_PI) // looking north
		{
			v_ray_end.y = ((camera.y - (VIEWER_SIZE / 2)) - VIEWER_SIZE) - BLOCK_SIZE - i;
			*v_ray_length = (v_ray_end.y - camera.y) / sin(ray_angle); // sometimes is too long
			v_ray_end.x = camera.x + abs(*v_ray_length) * cos(ray_angle);
			map.y = ((v_ray_end.y - BLOCK_SIZE) / BLOCK_SIZE);
			map.x = (v_ray_end.x - (v_ray_end.x % BLOCK_SIZE)) / BLOCK_SIZE;
		}
		i++;
		printf("\n collition index %d\n", i);
		printf("\ncheck colition at map[%d][%d] = %c\n", map.y, map.x, data->mlx->map->map[map.y][map.x]);
		if (check_wall(map, data)) //segfault - undeterminete values of map
			break ;
	}
	// return (v_ray_end);
	int	bckp_color;

	bckp_color = data->line_color;
	data->line_color = create_trgb(0, 255, 0, 0);
	draw_line(camera, v_ray_end, data);
	data->line_color = bckp_color;
	return (v_ray_end);
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

	draw_rays(camera, data, ONE_DEGREE * 360, 0, LINE_SIZE / 3); //draw viewer
	// bckp_color = data->line_color;
	// data->line_color = create_trgb(0, 255, 255, 50);
	// draw_rays(camera, data, *data->camera_angle + ONE_DEGREE * 30, *data->camera_angle - ONE_DEGREE * 30, LINE_SIZE * 4); //draw view range
	// data->line_color = bckp_color;


	int		h_ray_length;
	t_point	h_ray_end;
	h_ray_end = check_rays_colition_on_y_axis(camera, data, &h_ray_length);


	// int		v_ray_length;
	// t_point	v_ray_end;
	// v_ray_end = check_rays_colition_on_x_axis(camera, data, &v_ray_length);

	// ======= PRINT LINE ========
	// bckp_color = data->line_color;
	// if (v_ray_length < h_ray_length)
	// {
	// 	data->line_color = create_trgb(0, 255, 0, 0);
	// 	draw_line(camera, v_ray_end, data);
	// }
	// else
	// {
	// 	data->line_color = create_trgb(0, 255, 0, 0);
	// 	draw_line(camera, h_ray_end, data);
	// }
	// data->line_color = bckp_color;
	(void) bckp_color;
	(void) h_ray_end;
}
