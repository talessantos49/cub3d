/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:51:52 by tasantos          #+#    #+#             */
/*   Updated: 2024/01/26 20:53:13 by tasantos         ###   ########.fr       */
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

void	clean_textures(t_map *map)
{
	free(map->ea_texture);
	free(map->so_texture);
	free(map->no_texture);
	free(map->we_texture);
}

void	free_all_parser(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->n_row)
	{
		free(map->map_aux[i]);
		i++;
	}
	free(map->map_aux);
}

void	clean_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->n_row)
	{
		free(map->original[i]);
		i++;
	}
	free(map->original);
}
