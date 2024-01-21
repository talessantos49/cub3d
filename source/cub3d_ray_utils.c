/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_ray_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:16:44 by asoler            #+#    #+#             */
/*   Updated: 2024/01/20 19:32:57 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	calculate_west_rays(t_ray *ray, int i)
{
	ray->end.x = (ray->init.x / BLOCK_SIZE) * BLOCK_SIZE \
				- (BLOCK_SIZE * i);
	ray->len = (ray->end.x - ray->init.x) / cos(ray->angle);
	ray->end.y = ray->init.y + fabs(ray->len) * sin(ray->angle);
	ray->map.x = ((ray->end.x - BLOCK_SIZE) / BLOCK_SIZE);
	ray->map.y = ray->end.y / BLOCK_SIZE;
}

void	calculate_est_rays(t_ray *ray, int i)
{
	ray->end.x = ((ray->init.x + BLOCK_SIZE) / BLOCK_SIZE) * BLOCK_SIZE \
				+ (BLOCK_SIZE * i);
	ray->len = (ray->end.x - ray->init.x) / cos(ray->angle);
	ray->end.y = ray->init.y + fabs(ray->len) * sin(ray->angle);
	ray->map.x = ray->end.x / BLOCK_SIZE;
	ray->map.y = ray->end.y / BLOCK_SIZE;
}

void	calculate_north_rays(t_ray *ray, int i)
{
	ray->end.y = (ray->init.y / BLOCK_SIZE) * BLOCK_SIZE - \
				(BLOCK_SIZE * i);
	ray->len = (ray->end.y - ray->init.y) / sin(ray->angle);
	ray->end.x = ray->init.x + fabs(ray->len) * cos(ray->angle);
	ray->map.y = ((ray->end.y - BLOCK_SIZE) / BLOCK_SIZE);
	ray->map.x = ray->end.x / BLOCK_SIZE;
}

void	calculate_south_rays(t_ray *ray, int i)
{
	ray->end.y = (ray->init.y + BLOCK_SIZE) / BLOCK_SIZE * BLOCK_SIZE \
				+ (BLOCK_SIZE * i);
	ray->len = (ray->end.y - ray->init.y) / sin(ray->angle);
	ray->end.x = ray->init.x + fabs(ray->len) * cos(ray->angle);
	ray->map.y = ray->end.y / BLOCK_SIZE;
	ray->map.x = ray->end.x / BLOCK_SIZE;
}
