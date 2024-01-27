/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:56:50 by asoler            #+#    #+#             */
/*   Updated: 2024/01/26 23:39:19 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	clean_map_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->n_row)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}

void	clear_watcher(char *str, char *line, int error, t_map *map)
{
	free(str);
	free(map->ea_texture);
	free(map->so_texture);
	free(map->no_texture);
	free(map->we_texture);
	clean_map_map(map);
	free_all_parser(map);
	clean_before_exit(line, error);
}

void	clear_texture(t_map *map)
{
	if (map->no_texture)
		free(map->no_texture);
	if (map->so_texture)
		free(map->so_texture);
	if (map->we_texture)
		free(map->we_texture);
	if (map->ea_texture)
		free(map->ea_texture);
}

void	clear_character(char *str, char *line, int error, t_map *map)
{
	free(str);
	free(map->ea_texture);
	free(map->so_texture);
	free(map->no_texture);
	free(map->we_texture);
	clean_map_map(map);
	free_all_parser(map);
	clean_before_exit(line, error);
}
