/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_check_collition.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:43:15 by asoler            #+#    #+#             */
/*   Updated: 2024/01/06 08:36:57 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	calculate_west(t_ray *ray)
{
	ray->map.x = ((ray->init.x) / BLOCK_SIZE);
	ray->map.y = (ray->init.y - (ray->init.y % BLOCK_SIZE)) / BLOCK_SIZE;
}

void	calculate_est(t_ray *ray)
{
	ray->map.x = ray->init.x / BLOCK_SIZE;
	ray->map.y = (ray->init.y - (ray->init.y % BLOCK_SIZE)) / BLOCK_SIZE;
}

void	calculate_north(t_ray *ray)
{
	ray->map.y = (ray->init.y / BLOCK_SIZE);
	ray->map.x = (ray->init.x - (ray->init.x % BLOCK_SIZE)) / BLOCK_SIZE;
}

void	calculate_south(t_ray *ray)
{
	ray->map.y = ray->init.y / BLOCK_SIZE;
	ray->map.x = (ray->init.x - (ray->init.x % BLOCK_SIZE)) / BLOCK_SIZE;
}

int	cal_collition(t_ray *camera, t_mlx *mlx)
{
	int	flag;

	flag = 0;
	if (camera->angle < deeg_to_rad(270) && camera->angle > deeg_to_rad(90))
		calculate_west(camera);
	else if (camera->angle > deeg_to_rad(270) || camera->angle < deeg_to_rad(90))
		calculate_est(camera);
	flag += check_collition(camera->map, mlx);
	if (camera->angle < deeg_to_rad(180))
		calculate_south(camera);
	if (camera->angle > deeg_to_rad(180))
		calculate_north(camera);
	flag += check_collition(camera->map, mlx);
	return (flag);
}
