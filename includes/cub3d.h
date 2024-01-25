/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 10:01:38 by asoler            #+#    #+#             */
/*   Updated: 2024/01/25 15:34:51 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# include "get_next_line.h"
# include "libft.h"
# include "cub3d_parser.h"
# include "cub3d_rays.h"
# include "cub3d_window.h"
# include "cub3d_move_camera.h"
# include <errno.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <mlx.h>
# include <X11/keysym.h>
# include <math.h>
# define CUB3D_H
# define TRUE 1
# define FALSE 0
# define BLOCK_SIZE 64
# define VIEWER_SIZE 21.3
# define ONE_DEGREE 0.01745200698
# define VIEW_RANGE 60
# define N_RAYS WIDTH
# define MAP_OFFSET 0
# define CUB3D_H

typedef struct s_draw_line
{
	int		dx;
	int		p;
	int		dy;
	t_point	op;
	char	swap_sig;
}	t_draw_line;

int		cub3d_read_map(char *map_path, t_map *read_map);
int		cub3d_parse_map(int fd, t_map *read_map);
int		create_trgb(int t, int r, int g, int b);
void	swap(int *a, int *b);
int		update_viewer_direction(t_mlx *mlx, int key);
void	draw_quads(t_pixel *data);
void	draw_circle_viewer(t_point coord, t_pixel *data);
int		check_collition(t_point map, t_mlx *mlx);
double	deeg_to_rad(int deegres);
int		map_height(char **map, t_point map_coord);
void	clean_before_exit(char *str, int error);
int		line_too_long(t_map *map);
void	free_map(char **map);
void	cub3d_init_textures(t_mlx *mlx);
void	draw_texture(t_ray ray, t_ray *ray2d, t_pixel *data);

#endif
