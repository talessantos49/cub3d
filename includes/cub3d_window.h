/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_window.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:56:49 by asoler            #+#    #+#             */
/*   Updated: 2023/12/31 18:58:05 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_WINDOW_H
# include <stdlib.h>
# include <string.h>
# define CUB3D_WINDOW_H
# define HEIGHT 480
# define WIDTH 640
# define LINE_SIZE 15

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_map
{
	char	**map;
	int		height;
	t_color	floor;
	t_color	ceiling;
}	t_map;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_point
{
	int		x;
	int		y;
}	t_point;

typedef struct s_mlx
{
	void	*init;
	void	*window;
	t_map	*map;
	t_point	camera_pos;
	t_point	camera_dir;
	void	*data_img;
	void	*temp_img;
	char	change_dir;
	double	camera_angle;
}	t_mlx;

typedef struct s_pixel
{
	t_mlx	*mlx;
	int		line_color;
	t_data	*img;
	char	camera_dir;
	double	*camera_angle;
}	t_pixel;

int	cub3d_close_window(t_mlx *mlx);
int	cub3d_open_window(t_mlx *mlx);
int	render_image(t_mlx *mlx);
int	put_pixel(t_point point, int trgb, t_data *img);
int	draw_line(t_point point1, t_point point2, t_pixel *data);
void	draw_block(t_point coord, t_pixel *data, int size);

#endif