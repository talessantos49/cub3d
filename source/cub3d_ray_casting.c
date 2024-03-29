/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_ray_casting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 22:43:57 by asoler            #+#    #+#             */
/*   Updated: 2024/01/26 20:48:44 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_rays_colition_on_x_axis(t_ray *ray, t_pixel *data)
{
	int		i;
	int		flag;

	i = 0;
	if (ray->angle == ONE_DEGREE * 90 || ray->angle == ONE_DEGREE * 270)
		return ;
	while (TRUE)
	{
		if (ray->angle < deeg_to_rad(270) && ray->angle > deeg_to_rad(90))
			calculate_west_rays(ray, i);
		if (ray->angle > deeg_to_rad(270) || ray->angle < deeg_to_rad(90))
			calculate_east_rays(ray, i);
		i++;
		flag = check_collition(ray->map, data->mlx);
		if (flag > 0)
			break ;
		else if (flag < 0)
		{
			ray->len = 0;
			break ;
		}
	}
}

void	check_rays_colition_on_y_axis(t_ray *ray, t_pixel *data)
{
	int		i;
	int		flag;

	i = 0;
	if (!ray->angle || ray->angle == ONE_DEGREE * 180)
		return ;
	while (TRUE)
	{
		if (ray->angle < deeg_to_rad(180))
			calculate_south_rays(ray, i);
		if (ray->angle > deeg_to_rad(180))
			calculate_north_rays(ray, i);
		i++;
		flag = check_collition(ray->map, data->mlx);
		if (flag > 0)
			break ;
		else if (flag < 0)
		{
			ray->len = 0;
			break ;
		}
	}
}

void	choose_final_ray(t_ray *ray, t_ray *h_ray, t_ray *v_ray)
{
	if (v_ray->len < h_ray->len)
		ft_memcpy((void *)ray, (void *)v_ray, sizeof(t_ray));
	else if (v_ray->len > h_ray->len)
		ft_memcpy((void *)ray, (void *)h_ray, sizeof(t_ray));
	if (!h_ray->len)
		ft_memcpy((void *)ray, (void *)v_ray, sizeof(t_ray));
	if (!v_ray->len)
		ft_memcpy((void *)ray, (void *)h_ray, sizeof(t_ray));
	if (ray->len == h_ray->len)
		ray->is_hor = TRUE;
	else if (ray->len == v_ray->len)
		ray->is_hor = FALSE;
}

t_ray	*ray_end_coord(double angle, t_point init_coord, t_pixel *data)
{
	t_ray	h_ray;
	t_ray	v_ray;
	t_ray	*ray;

	ray = ft_calloc(1, sizeof(t_ray));
	ft_memset((void *)&h_ray, 0, sizeof(t_ray));
	ft_memset((void *)&v_ray, 0, sizeof(t_ray));
	h_ray.init = init_coord;
	h_ray.angle = angle;
	v_ray.init = init_coord;
	v_ray.angle = angle;
	check_rays_colition_on_y_axis(&h_ray, data);
	check_rays_colition_on_x_axis(&v_ray, data);
	choose_final_ray(ray, &h_ray, &v_ray);
	return (ray);
}

void	ray_casting(t_point camera, t_pixel *data)
{
	double	angle;

	angle = *data->camera_angle - deeg_to_rad(VIEW_RANGE / 2);
	if (angle < 0)
		angle += deeg_to_rad(360);
	draw_rays(camera, data, angle);
	if (data->mlx->viewer_dir)
		free(data->mlx->viewer_dir);
	data->mlx->viewer_dir = ray_end_coord(*data->camera_angle, camera, data);
}
