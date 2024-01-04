/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_debug_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 13:46:42 by asoler            #+#    #+#             */
/*   Updated: 2024/01/01 13:49:17 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_quads_x_loop(t_pixel *data)
{
	t_point	window;
	t_point	init;

	ft_memset((void *)&window, 0, sizeof(t_point));
	ft_memset((void *)&init, 0, sizeof(t_point));
	window.x = WIDTH;
	while (window.y <= HEIGHT)
	{
		draw_line(init, window, data);
		window.y += BLOCK_SIZE;
		init.y = window.y;
	}
}

void	draw_quads_y_loop(t_pixel *data)
{
	t_point	window;
	t_point	init;

	ft_memset((void *)&window, 0, sizeof(t_point));
	ft_memset((void *)&init, 0, sizeof(t_point));
	window.y = HEIGHT;
	while (window.x <= WIDTH)
	{
		draw_line(init, window, data);
		window.x += BLOCK_SIZE;
		init.x = window.x;
	}
}

void	draw_quads(t_pixel *data)
{
	int		bckp_color;

	bckp_color = data->line_color;
	data->line_color = create_trgb(0, 255, 255, 255);
	draw_quads_y_loop(data);
	draw_quads_x_loop(data);
	data->line_color = bckp_color;
}
