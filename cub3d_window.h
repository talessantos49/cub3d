/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_window.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:56:49 by asoler            #+#    #+#             */
/*   Updated: 2023/11/04 22:10:03 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_WINDOW_H
# include <mlx.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <string.h>
# define CUB3D_WINDOW_H
# define HEIGHT 480
# define WIDTH 640

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_mlx
{
	void	*init;
	void	*window;
}	t_mlx;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_pixel
{
	t_mlx	*mlx;
	int		line_color;
	t_data	*img;
}	t_pixel;

int	cub3d_close_window(t_mlx *mlx);
int	cub3d_open_window(t_mlx *mlx);
int	paint_something(t_mlx *mlx);
int	put_pixel(t_mlx *mlx, t_point point, int trgb, t_data *img);
int	bresenham(t_point point1, t_point point2, t_pixel *data);

#endif