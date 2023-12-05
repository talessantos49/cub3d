/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 10:01:38 by asoler            #+#    #+#             */
/*   Updated: 2023/12/05 19:36:27 by asoler           ###   ########.fr       */
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
# define CUB3D_H
# define TRUE 1
# define FALSE 0
# define BLOCK_SIZE 18
# define VIEWER_SIZE 6
# define N_MINICUBES BLOCK_SIZE / VIEWER_SIZE

// structure sugestion for the next develop parsing steps
// typedef struct s_texture
// {
// 	void no;
// 	void so;
// 	void we;
// 	void ea;
// }	t_texture;

typedef struct s_bresenham
{
	int	dx;
	int	dy;
	int	p;
}	t_bresenham;

int	cub3d_read_map(char *map_path, t_map *read_map);
int	cub3d_parse_map(int fd, t_map *read_map);
int	create_trgb(int t, int r, int g, int b);

#endif
