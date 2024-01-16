/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_read_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:40:49 by asoler            #+#    #+#             */
/*   Updated: 2024/01/16 17:22:54 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	verify_map_file_type(char *map_name)
{
	size_t	len;
	char	*type;

	len = ft_strlen(map_name);
	type = ft_strnstr(map_name, ".cub", len);
	if (!type || (*(type + 4) != '\0'))
		return (1);
	return (0);
}

void	initialize_map(t_map *map)
{
	map->n_row = 0;
	map->n_col = 0;
	map->map = NULL;
	map->original = NULL;
	map->no_texture = NULL;
	map->so_texture = NULL;
	map->we_texture = NULL;
	map->ea_texture = NULL;
	map->ceiling.b = 0;
	map->ceiling.g = 0;
	map->ceiling.r = 0;
	map->floor.b = 0;
	map->floor.g = 0;
	map->floor.r = 0;
	map->fase.ceiling = 0;
	map->fase.floor = 0;
	map->fase.map = 0;
	map->fase.no_texture = 0;
	map->fase.so_texture = 0;
	map->fase.we_texture = 0;
	map->fase.ea_texture = 0;
	map->fase.attributes = 0;
	map->fase.player = 0;
	map->fase.completed = 0;
}

int	cub3d_read_map(char *map_path, t_map *read_map)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (verify_map_file_type(map_path))
		return (printf("File most end with .cub\n"));
	if (fd < 0)
		return (printf("ERROR: %s\n", strerror(errno)));
	initialize_map(read_map);
	cub3d_parse_map(fd, read_map);
	close(fd);
	return (0);
}
