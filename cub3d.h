/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 10:01:38 by asoler            #+#    #+#             */
/*   Updated: 2023/10/29 17:55:21 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# include "includes/get_next_line.h"
# include "includes/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# define CUB3D_H
# define TRUE 1
# define FALSE 0

// structure sugestion for the next develop parsing steps
// typedef struct s_texture
// {
// 	void no;
// 	void so;
// 	void we;
// 	void ea;
// }	t_texture;

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

int	cub3d_read_map(char *map_path, t_map *read_map);
int	cub3d_parse_map(int fd, t_map *read_map);

#endif
