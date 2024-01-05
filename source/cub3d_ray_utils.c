/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_ray_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:16:44 by asoler            #+#    #+#             */
/*   Updated: 2024/01/05 16:20:27 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#define OFFSET 0.0001

void	calculate_west_rays(t_ray *ray)
{
	double	ntan = -tan(ray->angle);

	ray->end.x = ((ray->init.x / BLOCK_SIZE) * BLOCK_SIZE) - OFFSET;
	ray->end.y = (ray->init.x - ray->end.x) * ntan + ray->init.y;
	ray->offset.x = - BLOCK_SIZE;
	ray->offset.y = - ray->offset.x * ntan;
}

void	calculate_est_rays(t_ray *ray)
{
	double	ntan = -tan(ray->angle);

	ray->end.x = ((ray->init.x / BLOCK_SIZE) * BLOCK_SIZE) + BLOCK_SIZE;
	ray->end.y = (ray->init.x - ray->end.x) * ntan + ray->init.y;
	ray->offset.x = BLOCK_SIZE;
	ray->offset.y = - ray->offset.x * ntan;
}

void	calculate_north_rays(t_ray *ray)
{
	double	atan = -1/tan(ray->angle);

	ray->end.y = ((ray->init.y / BLOCK_SIZE) * BLOCK_SIZE) - OFFSET;
	ray->end.x = (ray->init.y - ray->end.y) * atan + ray->init.x;
	ray->offset.y = - BLOCK_SIZE;
	ray->offset.x = - ray->offset.y * atan;
}

void	calculate_south_rays(t_ray *ray)
{
	double	atan = -1/tan(ray->angle);

	ray->end.y = ((ray->init.y / BLOCK_SIZE) * BLOCK_SIZE) - OFFSET;
	ray->end.x = (ray->init.y - ray->end.y) * atan + ray->init.x;
	ray->offset.y = BLOCK_SIZE;
	ray->offset.x = - ray->offset.y * atan;
	ray->len = cos(deeg_to_rad(ray->angle))*(ray->end.x-ray->init.x)-sin(deeg_to_rad(ray->angle))*(ray->end.y-ray->init.y);
}
