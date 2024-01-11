/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_move_camera.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:15:34 by asoler            #+#    #+#             */
/*   Updated: 2024/01/11 11:35:48 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	take_descition(double angle, t_ray *camera, t_mlx *mlx)
{
	t_point	bckp;

	bckp = camera->init;
	camera->init.x += STEP_SIZE * cos(angle);
	camera->init.y += STEP_SIZE * sin(angle);
	if (camera->angle > deeg_to_rad(360))
		camera->angle -= deeg_to_rad(360);
	if (camera->angle < 0)
		camera->angle += deeg_to_rad(360);
	if (cal_collition(camera, mlx))
	{
		camera->init = bckp;
		return (FALSE);
	}
	return(TRUE);
}

int	read_key_input(int key, t_mlx *mlx)
{
	t_ray	bckp;

	bckp = *mlx->viewer_dir;
	if (key == XK_a)
		mlx->viewer_dir->angle -= deeg_to_rad(90);
	else if (key == XK_d)
		mlx->viewer_dir->angle += deeg_to_rad(90);
	else if (key == XK_s)
		mlx->viewer_dir->angle -= deeg_to_rad(180);
	if (bckp.angle != mlx->viewer_dir->angle || key == XK_w)
	{
		if (take_descition(mlx->viewer_dir->angle, mlx->viewer_dir, mlx))
			return (TRUE);
	}
	else if (key == XK_Left || key == XK_Right)
		return (update_viewer_direction(mlx, key));
	return (FALSE);
}

int	update_viewer_direction(t_mlx *mlx, int key)
{
	if (key == XK_Right)
	{
		mlx->camera_angle += 0.05;
		if (mlx->camera_angle > deeg_to_rad(360))
			mlx->camera_angle = 0;
	}
	else
	{
		mlx->camera_angle -= 0.05;
		if (mlx->camera_angle < 0)
			mlx->camera_angle = deeg_to_rad(360);
	}
	return (TRUE);
}
