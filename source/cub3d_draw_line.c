/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:56:20 by asoler            #+#    #+#             */
/*   Updated: 2023/12/09 19:32:08 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	call_put_pixel(int x, int y, t_pixel *data)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return (put_pixel(point, data->line_color, data->img));
}

int	draw_vetical_line(t_point p, int size, t_pixel *data, int op)
{
	while (size)
	{
		call_put_pixel(p.x, p.y, data);
		p.y += op;
		size--;
	}
	return (0);
}

t_point	line_diretion_op(t_draw_line bsh)
{
	t_point	op;

	op.x = 1;
	op.y = 1;
	if (bsh.dx < 0)
		op.x = -1;
	if (bsh.dy < 0)
		op.y = -1;
	return (op);
}

void	draw_bresenham_line(t_point init, t_point end, \
							t_draw_line bsh, t_pixel *data)
{
	while (init.x != end.x)
	{
		call_put_pixel(init.x, init.y, data);
		init.x += bsh.op.x;
		if (bsh.p < 0)
			bsh.p = bsh.p + 2 * abs(bsh.dy);
		else
		{
			bsh.p = bsh.p + 2 * abs(bsh.dy) - 2 * abs(bsh.dx);
			init.y += bsh.op.y;
		}
	}
}

int	draw_line(t_point init, t_point end, t_pixel *data)
{
	t_draw_line	bsh;

	bsh.dx = end.x - init.x;
	bsh.dy = end.y - init.y;
	bsh.op = line_diretion_op(bsh);
	bsh.p = 2 * abs(bsh.dy) - abs(bsh.dx);
	if (!bsh.dx)
		return (draw_vetical_line(init, abs(bsh.dy), data, bsh.op.y));
	draw_bresenham_line(init, end, bsh, data);
	return (0);
}
