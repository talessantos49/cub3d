/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_scenario_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:30:38 by asoler            #+#    #+#             */
/*   Updated: 2024/01/25 15:29:06 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_ceiling(t_ray ray, t_pixel *data)
{
	t_color	l_ceiling;
	t_point	l_init;
	int		bckp_color;

	l_ceiling = data->mlx->map->ceiling;
	bckp_color = data->line_color;
	data->line_color = create_trgb(0, l_ceiling.r, l_ceiling.g, l_ceiling.b);
	l_init.x = ray.end.x;
	l_init.y = 0;
	draw_line(l_init, ray.init, data);
	data->line_color = bckp_color;
}

void	draw_floor(t_ray ray, t_pixel *data)
{
	t_color	l_floor;
	t_point	l_end;
	int		bckp_color;

	l_floor = data->mlx->map->floor;
	bckp_color = data->line_color;
	data->line_color = create_trgb(0, l_floor.r, l_floor.g, l_floor.b);
	l_end.x = ray.init.x;
	l_end.y = HEIGHT;
	draw_line(ray.end, l_end, data);
	data->line_color = bckp_color;
}
