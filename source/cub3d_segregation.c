/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_segregation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:36:23 by tasantos          #+#    #+#             */
/*   Updated: 2024/01/20 13:21:39 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_strjoin_gnl(char	*string1, const char	*string2)
{
	char	*join;
	int		t;
	int		k;

	k = -1;
	t = -1;
	if (!string1)
	{
		string1 = (char *)malloc(1 * sizeof(char));
		string1[0] = '\0';
	}
	if (!string1 || !string2)
		return (NULL);
	join = malloc((ft_strlen(string2) + ft_strlen(string1) + 1) * sizeof(char));
	if (!join)
		return (NULL);
	while (string1[++t])
		join[t] = string1[t];
	while (string2[++k])
		join[t + k] = string2[k];
	join[t + k] = '\0';
	free (string1);
	return (join);
}

int	cleaner_before_map(t_map *map, int row, int col)
{
	while (map->original[row][col] != '\0')
	{
		if (map->original[row][col] == 'F')
			row++;
		if (map->original[row][col] == 'C')
			row++;
		if (map->original[row][col] == 'N'
			&& map->original[row][col + 1] == 'O')
			row++;
		if (map->original[row][col] == 'S'
			&& map->original[row][col + 1] == 'O')
			row++;
		if (map->original[row][col] == 'W'
			&& map->original[row][col + 1] == 'E')
			row++;
		if (map->original[row][col] == 'E'
			&& map->original[row][col + 1] == 'A')
			row++;
		col++;
	}
	return (row);
}

void	around_map(t_map *map, int len, int row, int k)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = calloc(len, sizeof(char));
	row = cleaner_before_map(map, 0, 0);
	while (map->original[row])
	{
		k = 0;
		while (map->original[row][k] != '\0')
			tmp[i++] = map->original[row][k++];
		tmp[i++] = '\n';
		row++;
	}
	map->map = ft_split(tmp, '\n');
	count_data(map);
	if (character_check(map))
		clean_before_exit("ERROR: Invalid map\n", 0);
	if (night_watcher(map))
		clean_before_exit("ERROR: Invalid Night map\n", 0);
	change_zero(map);
	free_map(map->original);
	free (tmp);
}

void	cut_strings(t_map *map, char *line, char direction)
{
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	len = ft_strlen(line);
	tmp = calloc(len, sizeof(char));
	while (line[i] != '\n' && line[i] != '\0')
	{
		tmp[i] = line[i];
		i++;
	}
	if (direction == 'F')
		parser_map_floor(tmp, map);
	else if (direction == 'C')
		parser_map_ceiling(tmp, map);
	else if (direction == 'N')
		map->fase.no_texture = parser_map_north(tmp + 2);
	else if (direction == 'S')
		map->fase.so_texture = parser_map_south(tmp + 2);
	else if (direction == 'W')
		map->fase.we_texture = parser_map_west(tmp + 2);
	else if (direction == 'E')
		map->fase.ea_texture = parser_map_east(tmp + 2);
	free (tmp);
}

void	parser_atributes(t_map *map, char *line)
{
	while (*line != '\0')
	{
		if (*line == 'F')
			cut_strings(map, line, 'F');
		else if (*line == 'C')
			cut_strings(map, line, 'C');
		else if (*line == 'N' && *line++ == 'O')
			cut_strings(map, line, 'N');
		else if (*line == 'S' && *line++ == 'O')
			cut_strings(map, line, 'S');
		else if (*line == 'W' && *line++ == 'E')
			cut_strings(map, line, 'W');
		else if (*line == 'E' && *line++ == 'A')
			cut_strings(map, line, 'E');
		else if (*line == '1' && map->fase.floor == 1 && map->fase.ceiling == 1)
			map->fase.attributes = 1;
		line++;
	}
	return ;
}
