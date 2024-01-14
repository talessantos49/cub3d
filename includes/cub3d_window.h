/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_window.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:56:49 by asoler            #+#    #+#             */
/*   Updated: 2024/01/14 19:07:14 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_WINDOW_H
# include <stdlib.h>
# include <string.h>
# define CUB3D_WINDOW_H
# define HEIGHT 420
# define WIDTH 680

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_fase
{
	int	floor;
	int	ceiling;
	int	map;
	int	no_texture;
	int	so_texture;
	int	we_texture;
	int	ea_texture;
	int	player;
	int	completed;
}	t_fase;

typedef struct s_map
{
	char	**map;
	char	**matrix;
	int		height;
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	int		n_row;
	int		n_col;
	t_fase	fase;
	t_color	floor;
	t_color	ceiling;
}	t_map;

typedef struct s_point
{
	int		x;
	int		y;
}	t_point;

typedef struct s_ray
{
	int		len;
	double	angle;
	t_point	init;
	t_point	end;
	t_point	map;
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
int		put_pixel(t_point	 point, int trgb, t_data *img);
int		draw_line(t_point point1, t_point point2, t_pixel *data);
int		bresenham(t_point point1, t_point point2, t_pixel *data);
int		parser_map_north(char *line);
int		parser_map(char *path_map, t_map *map);
int		parser_map_south(char *line);
int		parser_map_west(char *line);
int		parser_map_east(char *line);
int		comma_check(char *line, char constant);
void	parser_map_line(char *line, t_map *map);
void	clean_before_exit(char *message, int fd);
void	check_rgb_and_split(char *line, t_map *map, char constant, char type);
void	parser_map_floor(char *line, t_map *map);
void	parser_map_ceiling(char *line, t_map *map);

#endif