/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_window.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:56:49 by asoler            #+#    #+#             */
/*   Updated: 2024/01/26 20:39:41 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_WINDOW_H
# include <stdlib.h>
# include <string.h>
# define CUB3D_WINDOW_H
# define HEIGHT 480
# define WIDTH 640

typedef struct s_pointd
{
	double	x;
	double	y;
}	t_pointd;

typedef struct s_point
{
	int		x;
	int		y;
}	t_point;

typedef struct s_ray
{
	double	len;
	double	angle;
	t_point	init;
	t_point	end;
	t_point	map;
	char	is_hor;
}	t_ray;

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
	t_map	*map;
	t_point	camera_pos;
	void	*data_img;
	void	*temp_img;
	char	change_dir;
	double	camera_angle;
	t_ray	*viewer_dir;
	int		**north_text;
	int		**south_text;
	int		**west_text;
	int		**east_text;
}	t_mlx;

typedef struct s_pixel
{
	t_mlx	*mlx;
	int		line_color;
	t_data	*img;
	char	camera_dir;
	double	*camera_angle;
}	t_pixel;

int		cub3d_close_window(t_mlx *mlx);
int		cub3d_open_window(t_mlx *mlx);
int		render_image(t_mlx *mlx);
int		put_pixel(t_point point, int trgb, t_data *img);
int		draw_line(t_point point1, t_point point2, t_pixel *data);
int		bresenham(t_point point1, t_point point2, t_pixel *data);
void	free_all_parser(t_mlx *mlx);

#endif