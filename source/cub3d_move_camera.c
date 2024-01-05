/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_move_camera.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:15:34 by asoler            #+#    #+#             */
/*   Updated: 2024/01/05 13:23:53 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_right(t_ray *camera, t_mlx *mlx)
{
	double	angle;
	t_point	bckp;

	bckp = camera->init;
	angle = camera->angle + deeg_to_rad(90);
	if (angle > deeg_to_rad(360))
		angle -= deeg_to_rad(360);
	camera->init.x += STEP_SIZE * cos(angle);
	camera->init.y += STEP_SIZE * sin(angle);
	if (cal_collition(camera, mlx) > 0)
		camera->init = bckp;
	printf("camera angle: %f\n", mlx->camera_angle);
}

void	move_left(t_ray *camera, t_mlx *mlx)
{
	double	angle;
	t_point	bckp;

	bckp = camera->init;
	angle = camera->angle - deeg_to_rad(90);
	if (angle < 0)
		angle += deeg_to_rad(360);
	camera->init.x += STEP_SIZE * cos(angle);
	camera->init.y += STEP_SIZE * sin(angle);
	if (cal_collition(camera, mlx) > 0)
		camera->init = bckp;
	printf("camera angle: %f\n", mlx->camera_angle);
}

void	move_backward(t_ray *camera, t_mlx *mlx)
{
	double	angle;
	t_point	bckp;

	bckp = camera->init;
	angle = camera->angle - deeg_to_rad(180);
	if (angle < 0)
		angle += deeg_to_rad(360);
	camera->init.x += STEP_SIZE * cos(angle);
	camera->init.y += STEP_SIZE * sin(angle);
	if (cal_collition(camera, mlx) > 0)
		camera->init = bckp;
	printf("camera angle: %f\n", mlx->camera_angle);
}

void	move_forward(t_ray *camera, t_mlx *mlx)
{
	t_point	bckp;

	bckp = camera->init;
	camera->init.x += STEP_SIZE * cos(camera->angle);
	camera->init.y += STEP_SIZE * sin(camera->angle);
	if (cal_collition(camera, mlx) > 0)
		camera->init = bckp;
	printf("camera angle: %f\n", mlx->camera_angle);
}

int	update_viewer_direction(t_mlx *mlx, int key)
{
	if (key == XK_Right)
	{
		mlx->camera_angle += 0.1;
		if (mlx->camera_angle > deeg_to_rad(360))
			mlx->camera_angle = 0;
	}
	else
	{
		mlx->camera_angle -= 0.1;
		if (mlx->camera_angle < 0)
			mlx->camera_angle = deeg_to_rad(360);
	}
	return (TRUE);
}
