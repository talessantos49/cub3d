/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_rays.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 21:55:55 by asoler            #+#    #+#             */
/*   Updated: 2023/11/04 23:37:41 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_RAYS_H
# define CUB3D_RAYS_H

void	ray_casting(t_pixel *data);
int		call_put_pixel(int x, int y, t_pixel *data);

#endif
