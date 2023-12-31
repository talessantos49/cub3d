/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 23:13:13 by asoler            #+#    #+#             */
/*   Updated: 2023/12/30 23:17:07 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

void	update_viewer_direction(t_mlx *mlx, int key)
{
	if (key == XK_Right)
	{
		mlx->camera_angle += 0.1;
		if (mlx->camera_angle > M_PI * 2)
			mlx->camera_angle = 0;
	}
	else
	{
		mlx->camera_angle -= 0.1;
		if (mlx->camera_angle < 0)
			mlx->camera_angle = M_PI * 2;
	}
}
