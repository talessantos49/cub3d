/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_move_camera.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:15:34 by asoler            #+#    #+#             */
/*   Updated: 2024/01/04 21:22:53 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_right(t_ray *camera, t_mlx *mlx)
{
	double	angle;

	angle = camera->angle + deeg_to_rad(90);
	if (angle > deeg_to_rad(360))
		angle -= deeg_to_rad(360);
	camera->init.x += STEP_SIZE * cos(angle);
	camera->init.y += STEP_SIZE * sin(angle);
	printf("camera angle: %f\n", mlx->camera_angle);
}

void	move_left(t_ray *camera, t_mlx *mlx)
{
	double	angle;

	angle = camera->angle - deeg_to_rad(90);
	if (angle < 0)
		angle += deeg_to_rad(360);
	camera->init.x += STEP_SIZE * cos(angle);
	camera->init.y += STEP_SIZE * sin(angle);
	printf("camera angle: %f\n", mlx->camera_angle);
}

void	move_backward(t_ray *camera, t_mlx *mlx)
{
	double	angle;

	angle = camera->angle - deeg_to_rad(180);
	if (angle < 0)
		angle += deeg_to_rad(360);
	camera->init.x += STEP_SIZE * cos(angle);
	camera->init.y += STEP_SIZE * sin(angle);
	printf("camera angle: %f\n", mlx->camera_angle);
}

void	move_forward(t_ray *camera, t_mlx *mlx)
{
	// t_point bckp;

	// bckp = camera->init;
	camera->init.x += STEP_SIZE * cos(camera->angle);
	camera->init.y += STEP_SIZE * sin(camera->angle);
	// if (check_collition(camera->init, mlx))
		// camera.init = bckp;
	printf("camera angle: %f\n", mlx->camera_angle);
}
