/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_move_camera.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:16:33 by asoler            #+#    #+#             */
/*   Updated: 2024/01/05 15:20:17 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_MOVE_CAMERA_H
# define STEP_SIZE 4.54651
# define CUB3D_MOVE_CAMERA_H

void	move_right(t_ray *camera, t_mlx *mlx);
void	move_left(t_ray *camera, t_mlx *mlx);
void	move_backward(t_ray *camera, t_mlx *mlx);
void	move_forward(t_ray *camera, t_mlx *mlx);

#endif
