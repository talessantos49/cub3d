/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:48:51 by asoler            #+#    #+#             */
/*   Updated: 2024/01/04 20:10:31 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_point	verify_viewer_draw_rules(t_point coord, t_pixel *data)
{
	t_point	center;

	center.y = coord.y + VIEWER_SIZE / 2;
	center.x = coord.x + VIEWER_SIZE / 2;
	if (!data->mlx->viewer_dir)
	{
		// center.y = coord.y + VIEWER_SIZE / 2;
		// center.x = coord.x + VIEWER_SIZE / 2;
		if (data->camera_dir == 'N')
			*data->camera_angle = ONE_DEGREE * 270;
		else if (data->camera_dir == 'E')
			*data->camera_angle = 0;
		else if (data->camera_dir == 'S')
			*data->camera_angle = ONE_DEGREE * 90;
		else if (data->camera_dir == 'W')
			*data->camera_angle = ONE_DEGREE * 180;
		printf("this is the first time\n");
	}
	else
	{
		// center = data->mlx->viewer_dir->init;
		printf("center: (%d,%d)\nmlx->viewer_dir->init: (%d,%d)\n", \
		center.x,center.y,data->mlx->viewer_dir->init.x,data->mlx->viewer_dir->init.y);
	}
	ray_casting(center, data);
	return (center);
}

// returns top-left block coordinates
t_point	draw_block(t_point coord, t_pixel *data, int size)
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
		{
			if (size == VIEWER_SIZE)
				break ;
			call_put_pixel(p.x, p.y, data, 0);
		}
		p.y = coord.y;
	}
	return (coord);
}

t_ray	draw_viewer(t_point coord, t_pixel *data, char dir)
{
	int		bckp_color;
	// t_point	ab_view_pos;
	// t_point	viewer;
	t_ray	ret;

	ret.map = coord;
	bckp_color = data->line_color;
	data->line_color = create_trgb(0, 0, 100, 200);
	data->camera_dir = dir;
	ret.init = verify_viewer_draw_rules(draw_block(coord, data, VIEWER_SIZE), data);
	// ab_view_pos = verify_viewer_draw_rules(viewer, data);
	data->line_color = bckp_color;
	// printf("absolute viewer pos: (%d,%d)\n", ab_view_pos.x,ab_view_pos.y);
	// printf("viewer pos: (%d,%d)\n", viewer.x,viewer.y);
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
	// draw_quads(data);
	while (map->map[p.y])
	{
		while (map->map[p.y][p.x])
		{
			c = map->map[p.y][p.x];
			if (c == '1')
				draw_block(p, data, BLOCK_SIZE);
			else if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
				viewer_infos = draw_viewer(p, data, c);
			p.x++;
		}
		p.x = 0;
		p.y++;
	}
	return (viewer_infos.map);
}
