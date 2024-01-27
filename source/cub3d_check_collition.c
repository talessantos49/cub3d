/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_check_collition.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:43:15 by asoler            #+#    #+#             */
/*   Updated: 2024/01/26 21:25:22 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	cal_collition(t_ray *camera, t_mlx *mlx)
{
	camera->map.y = camera->init.y / BLOCK_SIZE;
	camera->map.x = camera->init.x / BLOCK_SIZE;
	return (check_collition(camera->map, mlx));
}
