/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 10:01:38 by asoler            #+#    #+#             */
/*   Updated: 2024/01/03 23:44:25 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# include "get_next_line.h"
# include "libft.h"
# include "cub3d_rays.h"
# include "cub3d_window.h"
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
# define BLOCK_SIZE 18
# define VIEWER_SIZE 6
# define ONE_DEGREE 0.01745200698
# define VIEW_RANGE 60
# define N_RAYS 320
# define CUB3D_H

// structure sugestion for the next develop parsing steps
// typedef struct s_texture
// {
// 	void no;
// 	void so;
// 	void we;
// 	void ea;
// }	t_texture;

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
void	update_viewer_direction(t_mlx *mlx, int key);
void	draw_quads(t_pixel *data);
t_point	draw_block(t_point coord, t_pixel *data, int size);
void	draw_circle_viewer(t_point coord, t_pixel *data);
int		check_wall(t_point map, t_pixel *data);
double	deeg_to_rad(int deegres);

#endif
