/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:56:06 by asoler            #+#    #+#             */
/*   Updated: 2023/12/02 17:06:02 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_player(t_mlx *mlx, int x, int y, int key)
{
	t_point		next;
	static int	moves;

	next.x = x;
	next.y = y;
	if (key == XK_w || key == XK_Up)
		next.y--;
	else if (key == XK_a || key == XK_Left)
		next.x--;
	else if (key == XK_d || key == XK_Right)
		next.x++;
	else if (key == XK_s || key == XK_Down)
		next.y++;
	if (mlx->map->map[next.y][next.x] == '0')
	{
		mlx_clear_window(mlx->init, mlx->window);
		mlx->map->map[y][x] = '0';
		// [TODO] Tratar orientação
		mlx->map->map[next.y][next.x] = 'N';
		render_image(mlx);
		moves++;
		ft_printf("Move Counter: %d\n", moves);
	}
}

int	key_input(int key, t_mlx *mlx)
{
	if (key == XK_Escape)
		cub3d_close_window(mlx);
	else if (key == XK_w || key == XK_a || key == XK_s || key == XK_d || \
	key == XK_Up || key == XK_Down || key == XK_Right || key == XK_Left)
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
	mlx_key_hook(mlx->window, &key_input, mlx);
	render_image(mlx);
	mlx_hook(mlx->window, 17, 0, &cub3d_close_window, mlx);
	//TODO: avoid misterious end leak
	//		related with these vars
	free(mlx->data_img);
	free(mlx->temp_img);
	mlx_loop(mlx->init);
	return (0);
}
