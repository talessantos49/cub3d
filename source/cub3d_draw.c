/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:48:51 by asoler            #+#    #+#             */
/*   Updated: 2024/01/14 20:40:40 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_point	verify_viewer_draw_rules(t_point coord, t_pixel *data)
{
	t_point	center;

	if (!data->mlx->viewer_dir)
	{
		center.y = coord.y + VIEWER_SIZE / 2;
		center.x = coord.x + VIEWER_SIZE / 2;
		if (data->camera_dir == 'N')
			*data->camera_angle = ONE_DEGREE * 270;
		else if (data->camera_dir == 'E')
			*data->camera_angle = 0;
		else if (data->camera_dir == 'S')
			*data->camera_angle = ONE_DEGREE * 90;
		else if (data->camera_dir == 'W')
			*data->camera_angle = ONE_DEGREE * 180;
	}
	else
		center = data->mlx->viewer_dir->init;
	return (center);
}

// returns top-left block coordinates
t_point	draw_block(t_point coord, int size)
{
	t_point	p;
	t_point	end_coord;

	coord.x *= BLOCK_SIZE;
	coord.y *= BLOCK_SIZE;
	if (size == VIEWER_SIZE)
	{
		coord.x += size;
		coord.y += size;
	}
	p = coord;
	end_coord.x = size + p.x;
	end_coord.y = size + p.y;
	while (++p.x < end_coord.x)
	{
		while (++p.y < end_coord.y)
			;
		p.y = coord.y;
	}
	return (coord);
}

t_ray	draw_viewer(t_point coord, t_pixel *data, char dir)
{
	int		bckp_color;
	t_ray	ret;

	ret.map = coord;
	bckp_color = data->line_color;
	data->line_color = create_trgb(0, 0, 100, 200);
	data->camera_dir = dir;
	ret.init = verify_viewer_draw_rules(draw_block(coord, VIEWER_SIZE), data);
	data->line_color = bckp_color;
	return (ret);
}

t_point	draw_scenario(t_pixel *data)
{
	t_map	*map;
	t_point	p;
	t_ray	viewer_infos;
	char	c;

	ft_memset((void *)&p, 0, sizeof(t_point));
	map = data->mlx->map;
	while (map->map[p.y])
	{
		while (map->map[p.y][p.x])
		{
			c = map->map[p.y][p.x];
			if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
				viewer_infos = draw_viewer(p, data, c);
			p.x++;
		}
		p.x = 0;
		p.y++;
	}
	ray_casting(viewer_infos.init, data);
	return (viewer_infos.map);
}
