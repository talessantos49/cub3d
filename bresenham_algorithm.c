/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:56:20 by asoler            #+#    #+#             */
/*   Updated: 2023/11/04 22:09:39 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	call_put_pixel(int x, int y, t_pixel *data)
{
	t_point	point;

	point.x = x;
	point.y = y;
	put_pixel(data->mlx, point, data->line_color, data->img);
}

int	print_vetical_line(int x, int y1, int size, t_pixel *data)
{
	int	i;
	int	y;

	i = 0;
	y = y1;
	while (++i < size)
	{
		call_put_pixel(x, y, data);
		y++;
	}
	return (0);
}

int	bresenham(t_point point1, t_point point2, t_pixel *data)
{
	t_bresenham	bsh;
	int			x;
	int			y;

	x = point1.x;
	y = point1.y;
	bsh.dx = point2.x - point1.x;
	bsh.dy = point2.y - point1.y;
	bsh.p = 2 * bsh.dy - bsh.dx;
	if (!bsh.dx)
		return (print_vetical_line(x, y, bsh.dy, data));
	while (x <= point2.x)
	{
		call_put_pixel(x, y, data);
		x++;
		if (bsh.p < 0)
			bsh.p = bsh.p + 2 * bsh.dy;
		else
		{
			bsh.p = bsh.p + 2 * bsh.dy - 2 * bsh.dx;
			y++;
		}
	}
	return (0);
}
