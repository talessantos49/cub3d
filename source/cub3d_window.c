/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:56:06 by asoler            #+#    #+#             */
/*   Updated: 2023/12/30 23:16:45 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	read_key_input(int key, t_point *next, t_mlx *mlx)
{
	if (key == XK_w)
		next->y--;
	else if (key == XK_a)
		next->x--;
	else if (key == XK_d)
		next->x++;
	else if (key == XK_s)
		next->y++;
	else if (key == XK_Left || key == XK_Right)
	{
		update_viewer_direction(mlx, key);
		mlx->change_dir = TRUE;
		return ;
	}
	mlx->change_dir = FALSE;
}

void	move_player(t_mlx *mlx, int x, int y, int key)
{
	t_point	next;
	char	viewer_bck;

	next.x = x;
	next.y = y;
	viewer_bck = mlx->map->map[y][x];
	read_key_input(key, &next, mlx);
	if (mlx->map->map[next.y][next.x] == '0' || mlx->change_dir)
	{
		mlx_clear_window(mlx->init, mlx->window);
		mlx->map->map[y][x] = '0';
		if (mlx->change_dir)
			mlx->map->map[next.y][next.x] = 27;
		else
			mlx->map->map[next.y][next.x] = viewer_bck;
		render_image(mlx);
		free(mlx->data_img);
		free(mlx->temp_img);
	}
}

int	key_input(int key, t_mlx *mlx)
{
	if (key == XK_Escape)
		cub3d_close_window(mlx);
	else if (key == XK_w || key == XK_a || key == XK_s || key == XK_d || \
			key == XK_Right || key == XK_Left)
		move_player(mlx, mlx->camera_pos.x, \
		mlx->camera_pos.y, key);
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
	free(mlx->data_img);
	free(mlx->temp_img);
	mlx_loop(mlx->init);
	return (0);
}
