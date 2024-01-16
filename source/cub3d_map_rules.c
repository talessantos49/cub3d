/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_map_rules.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 10:00:36 by asoler            #+#    #+#             */
/*   Updated: 2024/01/16 18:59:30 by tasantos         ###   ########.fr       */
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

int	verify_components(char *string, int len, int i)
{
	t_map	tmp;

	ft_memset((void *)&tmp, 0, sizeof(t_map));
	initialize_map(&tmp);
	while (i < len)
	{
		if (string[i] == 'F')
			tmp.fase.floor = 1;
		if (string[i] == 'C')
			tmp.fase.ceiling = 1;
		if (string[i] == 'N' && string[i + 1] == 'O')
			tmp.fase.no_texture = 1;
		if (string[i] == 'S' && string[i + 1] == 'O')
			tmp.fase.so_texture = 1;
		if (string[i] == 'W' && string[i + 1] == 'E')
			tmp.fase.we_texture = 1;
		if (string[i] == 'E' && string[i + 1] == 'A')
			tmp.fase.ea_texture = 1;
		i++;
	}
	if (tmp.fase.floor == 0 || tmp.fase.ceiling == 0 || tmp.fase.no_texture == 0
		|| tmp.fase.so_texture == 0 || tmp.fase.we_texture == 0
		|| tmp.fase.ea_texture == 0)
		return (1);
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
	if (!line)
		return (printf ("ERROR: Invalid map\n"));
	while (line)
	{
		str_map = ft_strjoin_gnl(str_map, line);
		free(line);
		line = get_next_line(fd);
	}
	parser_atributes(read_map, str_map);
	if (verify_components(str_map, ft_strlen(str_map), 0))
		clean_str_exit(str_map, "ERROR: Missing components\n", 0);
	read_map->original = ft_split(str_map, '\n');
	around_map(read_map, ft_strlen(str_map), 0, 0);
	free(line);
	return (has_error);
}
