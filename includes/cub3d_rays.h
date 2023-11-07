/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_rays.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 21:55:55 by asoler            #+#    #+#             */
/*   Updated: 2023/11/07 18:46:33 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_RAYS_H
# include "cub3d_window.h"
# define CUB3D_RAYS_H

void	ray_casting(t_pixel *data);
int		call_put_pixel(int x, int y, t_pixel *data);

#endif
