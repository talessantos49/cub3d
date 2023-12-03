/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_ray_casting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 22:43:57 by asoler            #+#    #+#             */
/*   Updated: 2023/12/03 17:48:46 by asoler           ###   ########.fr       */
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
			call_put_pixel(p.x, p.y, data);
		p.y = coord.y;
	}
}

void	draw_viewer_size_block(t_point coord, t_pixel *data)
{
	t_point	p;
	t_point	coord2;
	t_point	init_coord;

	coord2.x = coord.x * BLOCK_SIZE;
	coord2.y = coord.y * BLOCK_SIZE;
	init_coord = coord2;
	ft_memset((void *)&p, 0, sizeof(t_point));
	while (++p.x < 3)
	{
		while (++p.y < 3)
		{
			// if ((!p.x || p.x == 2) && (!p.y || p.y == 2))
			// 	continue;
			draw_block(coord2, data, VIEWER_SIZE);
			coord2.y += VIEWER_SIZE * (p.y + 1);
		}
		p.y = 0;
		coord2.y = init_coord.y;
		coord2.x = init_coord.x + VIEWER_SIZE * (p.x + 1);
	}
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
			else if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
				viewer_pos = draw_viewer(p, data, c);
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
