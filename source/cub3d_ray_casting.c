/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_ray_casting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 22:43:57 by asoler            #+#    #+#             */
/*   Updated: 2023/12/03 15:14:30 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_camera_direction(t_point p, t_point cord, t_pixel *data)
{
	if (data->camera_dir == 'N' || data->camera_dir == 'S')
		if (p.y <= (cord.y - VIEWER_SIZE) && \
			p.y >= (cord.y - (VIEWER_SIZE * 2)))
			call_put_pixel(p.x, p.y, data);
	if (data->camera_dir == 'N' && \
		p.y <= (cord.y - VIEWER_SIZE * 2) && \
		p.x <= (cord.x - VIEWER_SIZE) && \
		p.x >= (cord.x - (VIEWER_SIZE * 2)))
		call_put_pixel(p.x, p.y, data);
	else if (data->camera_dir == 'S' && \
			p.y >= (cord.y - VIEWER_SIZE) && \
			p.x <= (cord.x - VIEWER_SIZE) && \
			p.x >= (cord.x - (VIEWER_SIZE * 2)))
		call_put_pixel(p.x, p.y, data);
	if (data->camera_dir == 'E' || data->camera_dir == 'W')
		if (p.x <= (cord.x - VIEWER_SIZE) && \
			p.x >= (cord.x - (VIEWER_SIZE * 2)))
			call_put_pixel(p.x, p.y, data);
	if (data->camera_dir == 'E' && \
		p.y <= (cord.y - VIEWER_SIZE) && \
		p.y >= (cord.y - (VIEWER_SIZE * 2)) && \
		p.x <= (cord.x - (VIEWER_SIZE * 2)))
		call_put_pixel(p.x, p.y, data);
	else if (data->camera_dir == 'W' && \
			p.y <= (cord.y - VIEWER_SIZE) && \
			p.y >= (cord.y - VIEWER_SIZE * 2) && \
			p.x >= (cord.x - VIEWER_SIZE))
		call_put_pixel(p.x, p.y, data);
}

void	draw_blocks(t_point point, t_pixel *data, int size)
{
	t_point	p;
	t_point	cord;

	p.x = point.x * BLOCK_SIZE;
	p.y = point.y * BLOCK_SIZE;
	cord.x = BLOCK_SIZE + (point.x * BLOCK_SIZE);
	cord.y = BLOCK_SIZE + (point.y * BLOCK_SIZE);
	while (++p.x < cord.x)
	{
		while (++p.y < cord.y)
		{
			if (size == VIEWER_SIZE)
				draw_camera_direction(p, cord, data);
			else
				call_put_pixel(p.x, p.y, data);
		}
		p.y = (point.y * BLOCK_SIZE);
	}
}

void	draw_viewer(t_point point, t_pixel *data, char dir)
{
	t_point	point2;
	int		bckp_color;

	bckp_color = data->line_color;
	data->line_color = create_trgb(0, 0, 100, 200);
	data->camera_dir = dir;
	draw_blocks(point, data, VIEWER_SIZE);
	data->line_color = bckp_color;
	point.x *= BLOCK_SIZE;
	point.y *= BLOCK_SIZE;
	point2 = point;
	point2.x += BLOCK_SIZE;
	point2.y += BLOCK_SIZE;
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
				draw_blocks(p, data, BLOCK_SIZE);
			else if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
			{
				draw_viewer(p, data, c);
				viewer_pos = p;
			}
			p.x++;
		}
		p.x = 0;
		p.y++;
	}
	return (viewer_pos);
}

// void	ray_casting(t_pixel *data)
// {
	
// }
