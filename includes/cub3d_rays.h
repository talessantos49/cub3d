/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_rays.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 21:55:55 by asoler            #+#    #+#             */
/*   Updated: 2024/01/03 17:17:52 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_RAYS_H
# include "cub3d_window.h"
# define CUB3D_RAYS_H

t_point	draw_scenario(t_pixel *data);
void	ray_casting(t_point camera, t_pixel *data);
int		call_put_pixel(int x, int y, t_pixel *data, char swap_sig);
void	calculate_west_rays(t_ray *ray, int i);
void	calculate_est_rays(t_ray *ray, int i);
void	calculate_north_rays(t_ray *ray, int i);
void	calculate_south_rays(t_ray *ray, int i);

void	free_staff(t_mlx *mlx);

#endif
