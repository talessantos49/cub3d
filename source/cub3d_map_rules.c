/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_map_rules.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 10:00:36 by asoler            #+#    #+#             */
/*   Updated: 2024/01/15 21:19:06 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	different_characters(char *line)
{
	int	len;

	len = ft_strlen(line) - 1;
	if (line[0] != '1' || line[len] != '1')
		return (printf("ERROR: Map most be sorrounded by walls\n"));
	while (*line)
	{
		if (*line != 'N' && *line != 'E' && *line != 'W' && \
			*line != 'S' && *line != '0' && *line != '1')
			return (1);
		line++;
	}
	return (0);
}

int	wall_sorrounded(t_map *read_map)
{
	int	x;
	int	line_width;
	int	map_height;

	line_width = ft_strlen(read_map->map[0]);
	map_height = read_map->n_col - 1;
	x = 0;
	while (++x < line_width)
	{
		if (read_map->map[0][x] != '1')
			return (printf("ERROR: Map most be sorrounded by walls\n"));
	}
	line_width = ft_strlen(read_map->map[map_height]);
	x = 0;
	while (++x < line_width)
	{
		if (read_map->map[map_height][x] != '1')
			return (printf("ERROR: Map most be sorrounded by walls\n"));
	}
	return (0);
}

int	verify_map(t_map *read_map)
{
	int	i;

	i = 0;
	// if (wall_sorrounded(read_map))
	// if (line_too_long(read_map))
	// 	return (1);
	while (read_map->map[i])
	{
		if (different_characters(read_map->map[i]))
			return (1);
		i++;
	}
	return (0);
}

int	cub3d_parse_map(int fd, t_map *read_map)
{
	int		has_error;
	char	*line;
	char	*str_map;

	has_error = FALSE;
	str_map = ft_calloc(1, sizeof(char));
	line = get_next_line(fd);
	if (!line || *line == '\n')
		return (printf ("ERROR: Invalid map\n"));
	while (line)
	{
		str_map = ft_strjoin_gnl(str_map, line);
		free(line);
		line = get_next_line(fd);
	}
	parser_atributes(read_map, str_map);
	read_map->original = ft_split(str_map, '\n');
	around_map(read_map, ft_strlen(str_map), 0, 0);
	// has_error = verify_map(read_map);
	// free(str_map);
	free(line);
	return (has_error);
}
