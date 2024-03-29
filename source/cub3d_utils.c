/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 23:13:13 by asoler            #+#    #+#             */
/*   Updated: 2024/01/14 18:15:15 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	deeg_to_rad(int deegres)
{
	return (ONE_DEGREE * deegres);
}

void	draw_circle_viewer(t_point coord, t_pixel *data)
{
	double	init_angle;
	t_point	dir;

	dir = coord;
	init_angle = 0;
	while (init_angle < ONE_DEGREE * 360)
	{
		dir.x += (VIEWER_SIZE / 2) * cos(init_angle);
		dir.y += (VIEWER_SIZE / 2) * sin(init_angle);
		draw_line(coord, dir, data);
		init_angle += ONE_DEGREE;
		dir = coord;
	}
}

int	map_height(char **map, t_point map_coord)
{
	int	y;

	y = 0;
	while (map[y])
	{
		y++;
	}
	if (map_coord.y >= y)
		return (1);
	return (0);
}

int	check_collition(t_point map, t_mlx *mlx)
{
	if (map.y < 0 || map.x < 0 \
		|| map_height(mlx->map->map, map) \
		|| ft_strlen(mlx->map->map[map.y]) <= (size_t)map.x)
		return (-1);
	if (mlx->map->map[map.y][map.x] == '1')
		return (TRUE);
	return (FALSE);
}

void	swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}
