/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_read_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:40:49 by asoler            #+#    #+#             */
/*   Updated: 2024/01/26 23:34:27 by tasantos         ###   ########.fr       */
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
	map->map_aux = NULL;
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
	cub3d_parse_map(fd, read_map, 0);
	close(fd);
	return (0);
}

void	count_data(t_map *map, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map[i])
	{
		j = ft_strlen(map->map[i]);
		if (j > map->n_col)
			map->n_col = j;
		i++;
	}
	map->n_row = i;
	if (map->n_col < 3 || map->n_row < 3)
	{
		clear_texture(map);
		free_map(map->original);
		clean_map_map(map);
		free(line);
		clean_before_exit("Map most be at least 3x3", 1);
	}
}

int	character_check(t_map *map)
{
	int	i;
	int	j;
	int	len_col;

	i = 0;
	j = 0;
	len_col = 0;
	while (i < map->n_row)
	{
		j = 0;
		len_col = ft_strlen(map->map[i]);
		while (j < len_col)
		{
			if (ft_strchr(" 01NSEW", map->map[i][j]) == NULL)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
