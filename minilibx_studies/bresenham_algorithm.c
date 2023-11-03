#include "color_studies.h"

int	call_put_pixel(int x, int y, t_pixel *data)
{
	put_pixel(data->mlx, x, y, data->line_color, data->img);
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
	int	x = point1.x; //x init point
	int	y = point1.y; //y init point
	int	dx = point2.x - point1.x; //difference between x's (x line size)
	int	dy = point2.y - point1.y; //difference between y's (z line size)
	int	p = 2 * dy - dx; //decision parameter

	if (!dx)
		return (print_vetical_line(x, y, dy, data));
	while (x <= point2.x)
	{
		call_put_pixel(x, y, data);
		x++;
		if (p < 0)
			p = p + 2 *dy;
		else
		{
			p = p + 2 *dy - 2 * dx;
			y++;
		}
	}
}