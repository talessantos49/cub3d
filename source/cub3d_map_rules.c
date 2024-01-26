/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_map_rules.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 10:00:36 by asoler            #+#    #+#             */
/*   Updated: 2024/01/26 20:48:36 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	different_characters(char *line)
{
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
			return (printf("ERROR\n Map most be sorrounded by walls\n"));
	}
	line_width = ft_strlen(read_map->map[map_height]);
	x = 0;
	while (++x < line_width)
	{
		if (read_map->map[map_height][x] != '1')
			return (printf("ERROR\n Map most be sorrounded by walls\n"));
	}
	return (0);
}

int	verify_components(char *line, int len, int i)
{
	t_map	tmp;

	ft_memset((void *)&tmp, 0, sizeof(t_map));
	initialize_map(&tmp);
	while (i < len)
	{
		if (line[i] == 'F' && line[i + 1] == ' ')
			tmp.fase.floor = 1;
		if (line[i] == 'C' && line[i + 1] == ' ')
			tmp.fase.ceiling = 1;
		if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
			tmp.fase.no_texture = 1;
		if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
			tmp.fase.so_texture = 1;
		if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
			tmp.fase.we_texture = 1;
		if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
			tmp.fase.ea_texture = 1;
		i++;
	}
	if (tmp.fase.floor == 0 || tmp.fase.ceiling == 0 || tmp.fase.no_texture == 0
		|| tmp.fase.so_texture == 0 || tmp.fase.we_texture == 0
		|| tmp.fase.ea_texture == 0)
		return (1);
	return (0);
}

void	check_textures_errors(t_map *map, char *line)
{
	if (map->no_texture == NULL)
	{
		free(line);
		clear_texture(map);
		clean_before_exit("North texture not found", 1);
	}
	if (map->so_texture == NULL)
	{
		free(line);
		clear_texture(map);
		clean_before_exit("South texture not found", 1);
	}
	if (map->we_texture == NULL)
	{
		free(line);
		clear_texture(map);
		clean_before_exit("West texture not found", 1);
	}
	if (map->ea_texture == NULL)
	{
		free(line);
		clear_texture(map);
		clean_before_exit("East texture not found", 1);
	}
}

int	cub3d_parse_map(int fd, t_map *read_map, int len)
{
	int		has_error;
	char	*line;
	char	*str_map;

	has_error = FALSE;
	str_map = ft_calloc(1, sizeof(char));
	line = get_next_line(fd);
	if (!line)
		return (ft_printf ("ERROR: Invalid map\n"));
	while (line)
	{
		str_map = ft_strjoin_gnl(str_map, line);
		free(line);
		line = get_next_line(fd);
	}
	parser_atributes(read_map, str_map);
	check_textures_errors(read_map, str_map);
	len = ft_strlen(str_map);
	if (verify_components(str_map, len, 0))
		clean_str_exit(str_map, "Missing components", 1, read_map);
	read_map->original = ft_split(str_map, '\n');
	free(str_map);
	free(line);
	around_map(read_map, len, 0, 0);
	return (has_error);
}
