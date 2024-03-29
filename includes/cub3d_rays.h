/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_rays.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 21:55:55 by asoler            #+#    #+#             */
/*   Updated: 2024/01/26 20:39:47 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_RAYS_H
# include "cub3d_window.h"
# define CUB3D_RAYS_H

t_point	draw_scenario(t_pixel *data);
void	draw_ceiling(t_ray ray, t_pixel *data);
void	draw_floor(t_ray ray, t_pixel *data);
void	ray_casting(t_point camera, t_pixel *data);
int		call_put_pixel(int x, int y, t_pixel *data, char swap_sig);
void	calculate_west_rays(t_ray *ray, int i);
void	calculate_east_rays(t_ray *ray, int i);
void	calculate_north_rays(t_ray *ray, int i);
void	calculate_south_rays(t_ray *ray, int i);
t_ray	*ray_end_coord(double angle, t_point init_coord, t_pixel *data);
t_ray	*draw_rays(t_point ray_init, t_pixel *data, double angle);
int		cal_collition(t_ray *camera, t_mlx *mlx);

void	free_staff(t_mlx *mlx);

#endif
