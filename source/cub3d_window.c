/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:56:06 by asoler            #+#    #+#             */
/*   Updated: 2024/01/26 17:54:34 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_viewer(t_mlx *mlx, int key)
{
	if (read_key_input(key, mlx))
		render_image(mlx);
}

int	key_input(int key, t_mlx *mlx)
{
	if (key == XK_Escape)
		cub3d_close_window(mlx);
	else if (key == XK_w || key == XK_a || key == XK_s || key == XK_d || \
			key == XK_Right || key == XK_Left)
		move_viewer(mlx, key);
	return (0);
}

int	cub3d_close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->init, mlx->window);
	mlx_destroy_display(mlx->init);
	free_all_parser(mlx->map);
	free_staff(mlx);
	clean_textures(mlx->map);
	exit (0);
}

int	cub3d_open_window(t_mlx *mlx)
{
	mlx->init = mlx_init();
	cub3d_init_textures(mlx);
	mlx->window = mlx_new_window(mlx->init, WIDTH, HEIGHT, "cub3d, get fun!");
	mlx_hook(mlx->window, 2, 1L << 0, key_input, mlx);
	mlx_hook(mlx->window, 17, 0, &cub3d_close_window, mlx);
	render_image(mlx);
	mlx_loop(mlx->init);
	return (0);
}
