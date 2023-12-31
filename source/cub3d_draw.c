/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:48:51 by asoler            #+#    #+#             */
/*   Updated: 2023/12/30 23:03:42 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_block(t_point coord, t_pixel *data, int size)
{
	t_point	p;
	t_point	end_coord;

	if (size == BLOCK_SIZE)
	{
		coord.x *= size;
		coord.y *= size;
	}
	p = coord;
	end_coord.x = size + p.x;
	end_coord.y = size + p.y;
	while (++p.x < end_coord.x)
	{
		while (++p.y < end_coord.y)
			call_put_pixel(p.x, p.y, data, 0);
		p.y = coord.y;
	}
}

void	verify_viewer_draw_rules(t_point coord, t_pixel *data)
{
	t_point	dir;
	t_point	center;

	dir.y = coord.y + VIEWER_SIZE / 2;
	dir.x = coord.x + VIEWER_SIZE / 2;
	center = dir;
	if (data->camera_dir == 'N')
		*data->camera_angle = M_PI + (M_PI / 2);
	else if (data->camera_dir == 'E')
		*data->camera_angle = 0;
	else if (data->camera_dir == 'S')
		*data->camera_angle = M_PI / 2;
	else if (data->camera_dir == 'W')
		*data->camera_angle = M_PI;
	dir.x += LINE_SIZE * cos(*data->camera_angle);
	dir.y += LINE_SIZE * sin(*data->camera_angle);
	if (data->camera_dir != 27)
		data->camera_dir = 27;
	draw_line(center, dir, data);
	draw_block(coord, data, VIEWER_SIZE);
}

void	draw_viewer_size_block(t_point coord, t_pixel *data)
{
	t_point	p;
	t_point	viewer;
	t_point	init_coord;

	viewer.x = coord.x * BLOCK_SIZE;
	viewer.y = coord.y * BLOCK_SIZE;
	init_coord = viewer;
	ft_memset((void *)&p, 0, sizeof(t_point));
	p.y = 1;
	p.x = 1;
	viewer.x = init_coord.x + (VIEWER_SIZE * p.x);
	viewer.y = init_coord.y + (VIEWER_SIZE * p.y);
	verify_viewer_draw_rules(viewer, data);
}

t_point	draw_viewer(t_point coord, t_pixel *data, char dir)
{
	int		bckp_color;

	bckp_color = data->line_color;
	data->line_color = create_trgb(0, 0, 100, 200);
	data->camera_dir = dir;
	draw_viewer_size_block(coord, data);
	data->line_color = bckp_color;
	return (coord);
}

t_point	draw_scenario(t_pixel *data)
{
	t_map	*map;
	t_point	p;
	t_point	viewer_pos;
	char	c;

	ft_memset((void *)&p, 0, sizeof(t_point));
	map = data->mlx->map;
	while (map->map[p.y])
	{
		while (map->map[p.y][p.x])
		{
			c = map->map[p.y][p.x];
			if (c == '1')
				draw_block(p, data, BLOCK_SIZE);
			else if (c == 'N' || c == 'E' || c == 'S' || c == 'W' || c == 27)
				viewer_pos = draw_viewer(p, data, c);
			p.x++;
		}
		p.x = 0;
		p.y++;
	}
	return (viewer_pos);
}
