/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:10:53 by asoler            #+#    #+#             */
/*   Updated: 2024/01/25 13:01:09 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

#define NORTH "xpm_assets/BRICK_6D.xpm"
#define SOUTH "xpm_assets/HEDGE_1A.xpm"
#define WEST "xpm_assets/LIGHT_1B.xpm"
#define EST "xpm_assets/PIPES_1A.xpm"

void	cub3d_xpm_file_to_image(void *mlx_ptr, char *path, t_data *img)
{
	int	width;
	int	height;

	img->img = mlx_xpm_file_to_image(mlx_ptr, path, &width, &height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
								&img->line_length, &img->endian);
}

void	populate_color_matrix(int **xpm_matrix, t_data img)
{
	t_char_color	col;
	t_point			text;
	int				i;

	ft_memset((void *)&text, 0, sizeof(t_point));
	while (text.y < BLOCK_SIZE)
	{
		while (text.x < BLOCK_SIZE)
		{
			i = text.y * img.line_length + text.x * (img.bits_per_pixel / 8);
			col.r = img.addr[i + 2];
			col.g = img.addr[i + 1];
			col.b = img.addr[i];
			xpm_matrix[text.y][text.x] = create_trgb(0, col.r, col.g, col.b);
			text.x++;
		}
		text.x = 0;
		text.y++;
	}
}

void	alloc_textures(t_mlx *mlx, char *path, int ***text_matrix)
{
	int		**xpm_matrix;
	int		i;
	t_data	img;

	i = 0;
	xpm_matrix = ft_calloc(sizeof(int *), BLOCK_SIZE);
	cub3d_xpm_file_to_image(mlx->init, path, &img);
	while (i < BLOCK_SIZE)
	{
		xpm_matrix[i] = ft_calloc(sizeof(int), BLOCK_SIZE);
		i++;
	}
	populate_color_matrix(xpm_matrix, img);
	mlx_destroy_image(mlx->init, img.img);
	*text_matrix = xpm_matrix;
}

void	cub3d_init_textures(t_mlx *mlx)
{
	alloc_textures(mlx, NORTH, &mlx->north_text);
	alloc_textures(mlx, SOUTH, &mlx->south_text);
	alloc_textures(mlx, WEST, &mlx->west_text);
	alloc_textures(mlx, EST, &mlx->est_text);
}
