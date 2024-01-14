/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 10:01:38 by asoler            #+#    #+#             */
/*   Updated: 2024/01/14 17:52:45 by root             ###   ########.fr       */
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
// # include <mlx.h>
// # include <X11/keysym.h>
# define CUB3D_H
# define TRUE 1
# define FALSE 0
# define WALL_BLOCK_SIZE 20
# define  STR_SPACES	" \t\r\f\v"

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
typedef struct Node {
    char key;
    int value;
    struct Node* next;
} Node;

int	cub3d_read_map(char *map_path, t_map *read_map);
int	cub3d_parse_map(int fd, t_map *read_map);
int	create_trgb(int t, int r, int g, int b);
void	clean_before_exit(char *str, int error);
int	line_too_long(t_map *map);


#endif
