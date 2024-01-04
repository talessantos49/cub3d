/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 09:42:42 by asoler            #+#    #+#             */
/*   Updated: 2024/01/04 16:18:56 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_staff(t_mlx *mlx)
{
	free(mlx->init);
	free_map(mlx->map->map);
}

int	main(int argc, char *argv[])
{
	t_map	read_map;
	t_mlx	mlx;

	ft_memset((void *)&read_map, 0, sizeof(t_map));
	ft_memset((void *)&mlx, 0, sizeof(t_mlx));
	if (argc != 2)
		return (printf("Try something like this: ./cub3d <map>.cub\n"));
	if (cub3d_read_map(argv[1], &read_map))
		exit (1);
	mlx.map = &read_map;
	if (cub3d_open_window(&mlx))
		exit (1);
	return (0);
}
