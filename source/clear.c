/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:56:50 by asoler            #+#    #+#             */
/*   Updated: 2024/01/26 17:18:06 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	clean_before_exit(char *str, int error)
{
	ft_printf("Error\n");
	ft_printf("%s\n", str);
	exit(error);
}

void	clean_str_exit(char	*str, char *line, int error, t_map *map)
{
	free(str);
	free(map->ea_texture);
	free(map->so_texture);
	free(map->no_texture);
	free(map->we_texture);
	clean_before_exit(line, error);
}

void	clean_textures(t_mlx *mlx)
{
	free(mlx->map->ea_texture);
	free(mlx->map->so_texture);
	free(mlx->map->no_texture);
	free(mlx->map->we_texture);
}
void	free_all_parser(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < mlx->map->n_row)
	{
		free(mlx->map->map_aux[i]);
		i++;
	}
	free(mlx->map->map_aux);
}
