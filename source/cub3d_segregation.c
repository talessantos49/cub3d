/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_segregation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:36:23 by tasantos          #+#    #+#             */
/*   Updated: 2024/01/26 12:37:14 by tasantos         ###   ########.fr       */
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

int	cleaner_before_map(t_map *map, int i, int k)
{
	while (map->original[i][k] != '\0')
	{
		k = 0;
		while (map->original[i][k] != '\n' && map->original[i][k] != '\0')
		{
			if (map->original[i][k] == 'F' || map->original[i][k] == 'C'
			|| (map->original[i][k] == 'N' && map->original[i][k + 1] == 'O')
			|| (map->original[i][k] == 'S' && map->original[i][k + 1] == 'O')
			|| (map->original[i][k] == 'W' && map->original[i][k + 1] == 'E')
			|| (map->original[i][k] == 'W' && map->original[i][k + 1] == 'E')
			|| (map->original[i][k] == 'E' && map->original[i][k + 1] == 'A'))
			{
				i++;
				break ;
			}
			k++;
		}
	}
	return (i);
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
		tmp[i++] = ' ';
		tmp[i++] = '\n';
		row++;
	}
	map->map = ft_split(tmp, '\n');
	count_data(map);
	make_square(map, 0, 0, -1);
	if (character_check(map))
		clean_before_exit("ERROR: Wrong character inside map\n", 0);
	if (night_watcher(map))
		clean_before_exit("ERROR: Invalid Map must be arround Walls\n", 0);
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
		map->no_texture = parser_map_north(tmp + 2, 0, 0);
	else if (direction == 'S')
		map->so_texture = parser_map_south(tmp + 2, 0, 0);
	else if (direction == 'W')
		map->we_texture = parser_map_west(tmp + 2, 0, 0);
	else if (direction == 'E')
		map->ea_texture = parser_map_east(tmp + 2, 0, 0);
	free (tmp);
}

void	parser_atributes(t_map *map, char *line)
{
	while (*line != '\0')
	{
		if (*line == 'F' && *(line + 1) == ' ')
			cut_strings(map, line, 'F');
		else if (*line == 'C' && *(line + 1) == ' ')
			cut_strings(map, line, 'C');
		else if (*line == 'N' && *(line + 1) == 'O' && *(line + 2) == ' ')
			cut_strings(map, line, 'N');
		else if (*line == 'S' && *(line + 1) == 'O' && *(line + 2) == ' ')
			cut_strings(map, line, 'S');
		else if (*line == 'W' && *(line + 1) == 'E' && *(line + 2) == ' ')
			cut_strings(map, line, 'W');
		else if (*line == 'E' && *(line + 1) == 'A' && *(line + 2) == ' ')
			cut_strings(map, line, 'E');
		line++;
	}
	return ;
}
