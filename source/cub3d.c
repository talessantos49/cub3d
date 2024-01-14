/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 09:42:42 by asoler            #+#    #+#             */
/*   Updated: 2024/01/11 19:00:41 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_map	read_map;
	// t_mlx	mlx;

	ft_memset((void *)&read_map, 0, sizeof(t_map));
	if (argc != 2)
		return (printf("Try something like this: ./cub3d <map>.cub\n"));
	if (cub3d_read_map(argv[1], &read_map))
		exit (1);
	// mlx.map = &read_map;
	// if (cub3d_open_window(&mlx))
		// exit (1);
	return (0);
}
