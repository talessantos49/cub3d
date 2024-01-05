/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:56:06 by asoler            #+#    #+#             */
/*   Updated: 2024/01/05 12:32:32 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	read_key_input(int key, t_mlx *mlx)
{
	t_point	bckp;

	bckp = mlx->viewer_dir->init;
	if (key == XK_w)
		move_forward(mlx->viewer_dir, mlx);
	else if (key == XK_a)
		move_left(mlx->viewer_dir, mlx);
	else if (key == XK_d)
		move_right(mlx->viewer_dir, mlx);
	else if (key == XK_s)
		move_backward(mlx->viewer_dir, mlx);
	if (bckp.x != mlx->viewer_dir->init.x || bckp.y != mlx->viewer_dir->init.y)
		return (TRUE);
	else if (key == XK_Left || key == XK_Right)
		return (update_viewer_direction(mlx, key));
	return (FALSE);
}

void	move_viewer(t_mlx *mlx, int key)
{
	if (read_key_input(key, mlx))
	{
		mlx_clear_window(mlx->init, mlx->window);
		render_image(mlx);
		mlx_destroy_image(mlx->init, mlx->data_img);
		mlx_destroy_image(mlx->init, mlx->temp_img);
	}
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
	free_staff(mlx);
	exit (0);
}

int	cub3d_open_window(t_mlx *mlx)
{
	mlx->init = mlx_init();
	mlx->window = mlx_new_window(mlx->init, WIDTH, HEIGHT, "cub3d, get fun!");
	mlx_hook(mlx->window, 2, 1L << 0, key_input, mlx);
	mlx_hook(mlx->window, 17, 0, &cub3d_close_window, mlx);
	render_image(mlx);
	mlx_destroy_image(mlx->init, mlx->data_img);
	mlx_destroy_image(mlx->init, mlx->temp_img);
	mlx_loop(mlx->init);
	return (0);
}
