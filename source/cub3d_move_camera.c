/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_move_camera.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:15:34 by asoler            #+#    #+#             */
/*   Updated: 2024/01/06 09:16:44 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


int	verify_step_size(t_ray *camera, t_point	bckp, t_mlx *mlx)
{
	t_ray	h_ray;
	t_ray	v_ray;
	t_ray	*ray;
	int		len;

	ray = ft_calloc(1, sizeof(t_ray));
	h_ray.init = bckp;
	h_ray.angle = camera->angle;
	v_ray.init = bckp;
	v_ray.angle = camera->angle;
	check_rays_colition_on_y_axis(&h_ray, mlx);
	check_rays_colition_on_x_axis(&v_ray, mlx);
	choose_final_ray(ray, &h_ray, &v_ray);

	// ray = ray_end_coord(camera->angle, bckp, 0);
	printf("\n==antes==\nray len: %d\n", ray->len);
	len = cos(deeg_to_rad(ray->angle))*(ray->end.x-ray->init.x)- \
			sin(deeg_to_rad(ray->angle))*(ray->end.y-ray->init.y);
	printf("\n==depois==\nray len: %d\n", len);
	if (len < STEP_SIZE)
	{
		free(ray);
		return (TRUE);
	}
	free(ray);
	return (FALSE);
}

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
	// verify_step_size(camera, bckp, mlx);
	// if (cal_collition(camera, mlx) && verify_step_size(camera, bckp, mlx))
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
