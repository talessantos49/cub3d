/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:11:20 by root              #+#    #+#             */
/*   Updated: 2024/01/15 17:51:31 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*is_spaces(char *line, char *spaces)
{
	while (line && *spaces)
	{
		if (*line != *spaces)
			spaces++;
		else if (*line == *spaces)
		{
			line++;
			spaces = STR_SPACES;
		}
	}
	return (line);
}

// void	check_first_collum(char **map, int height)
// {
// 	int		i;
// 	int		j;
// 	char	*line;

// 	i = 0;
// 	j = 0;
// 	while (map[i][j] != '1' && map[i][j] != '\0')
// 		i++;
// 	line = is_spaces(map[i], STR_SPACES);
// 	while (map[i][j] == '1' && i < height)
// 	{
// 		i++;
// 		line = is_spaces(map[i], STR_SPACES);
// 		if (*line != '1')
// 			clean_before_exit("Map most be sorrounded by walls\n", 0);
// 	}
// }

// void	check_last_collum(char **map, int height)
// {
// 	int		i;
// 	int		j;
// 	int		len;
// 	char	*line;

// 	i = 0;
// 	j = 0;
// 	while (map[i][j] != '1' && map[i][j] != '\0')
// 		i++;
// 	line = map[i];
// 	len = ft_strlen(line);
// 	while (i < height)
// 	{
// 		len = ft_strlen(line);
// 		if (map[i][len - 1] != '1')
// 			clean_before_exit("Map most be sorrounded by walls", 0);
// 		i++;
// 		line = map[i];
// 	}
// }

// int	line_too_long(t_map *map)
// {
// 	int	i;
// 	int	j;
// 	int	line_width;

// 	i = 0;
// 	line_width = 0;
// 	j = 0;
// 	while (map->map[i][j] != '1' && map->map[i][j] != '\0')
// 		i++;
// 	while ((map->map[i][j] == '1' || map->map[i][j] == ' ') && map->map[i][0] != '\0')
// 	{
// 		while ((map->map[i][j] == '1' || map->map[i][j] == ' ' || map->map[i][j] == '0' || map->map[i][j] == 'E' || map->map[i][j] == 'W' || map->map[i][j] == 'N' || map->map[i][j] == 'S') && (map->map[i][j] != '\0' || map->map[i][j] != '\n'))
// 		{
// 			if (line_width < j)
// 				line_width = j;
// 			j++;
// 		}
// 		j = 0;
// 		i++;
// 	}
// 	check_first_collum(map->map, i);
// 	check_last_collum(map->map, i);
// 	return (1);
// }
