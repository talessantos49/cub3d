/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_ray_casting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 22:43:57 by asoler            #+#    #+#             */
/*   Updated: 2023/11/12 21:46:04 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_wall_block(t_point point, t_pixel *data);

void	print_viewer(t_point point, t_pixel *data)
{
	t_point	point2;
	int		bckp_color;

	bckp_color = data->line_color;
	data->line_color = create_trgb(0, 0, 100, 200);
	print_wall_block(point, data);
	data->line_color = bckp_color;
	point.x *= WALL_BLOCK_SIZE;
	point.y *= WALL_BLOCK_SIZE;
	point2 = point;
	point2.x += WALL_BLOCK_SIZE;
	point2.y += WALL_BLOCK_SIZE;
	bresenham(point, point2, data);
}

void	print_wall_block(t_point point, t_pixel *data)
{
	t_point	p;

	p.x = point.x * WALL_BLOCK_SIZE;
	p.y = point.y * WALL_BLOCK_SIZE;
	while (++p.x < WALL_BLOCK_SIZE + (point.x * WALL_BLOCK_SIZE))
	{
		while (++p.y < WALL_BLOCK_SIZE + (point.y * WALL_BLOCK_SIZE))
			call_put_pixel(p.x, p.y, data);
		p.y = (point.y * WALL_BLOCK_SIZE);
	}
}

void	print_cenario(t_pixel *data)
{
	t_map	*map;
	t_point	p;
	char	c;

	ft_memset((void *)&p, 0, sizeof(t_point));
	map = data->mlx->map;
	while (map->map[p.y])
	{
		while (map->map[p.y][p.x])
		{
			c = map->map[p.y][p.x];
			if (c == '1')
				print_wall_block(p, data);
			else if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
				print_viewer(p, data);
			p.x++;
		}
		p.x = 0;
		p.y++;
	}
}

void	ray_casting(t_pixel *data)
{
	print_cenario(data);
}
