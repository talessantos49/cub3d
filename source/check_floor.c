/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_floor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:42:32 by root              #+#    #+#             */
/*   Updated: 2024/01/26 10:11:08 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	comma_check(char *line, char constant)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_strlen(line);
	while (i < len)
	{
		if (line[i] == constant)
			j++;
		if (j == 2)
			return (1);
		i++;
	}
	return (0);
}

void	check_rgb_and_split(char *line, t_map *map, char constant, char type)
{
	char	**split;

	if (comma_check(line, constant) == 0)
		clean_before_exit("Error\nFloor or Ceiling color not valid\n", 0);
	split = ft_split(line, constant);
	if (type == 'f')
	{
		map->floor.r = ft_atoi(split[0]);
		map->floor.g = ft_atoi(split[1]);
		map->floor.b = ft_atoi(split[2]);
	}
	else if (type == 'c')
	{
		map->ceiling.r = ft_atoi(split[0]);
		map->ceiling.g = ft_atoi(split[1]);
		map->ceiling.b = ft_atoi(split[2]);
	}
	free_map(split);
	if (map->floor.r > 255 || map->floor.g > 255 || map->floor.b > 255
		|| map->floor.r < 0 || map->floor.g < 0 || map->floor.b < 0)
		clean_before_exit("Floor color not valid\n", 0);
	if (map->ceiling.r > 255 || map->ceiling.g > 255 || map->ceiling.b > 255
		|| map->ceiling.r < 0 || map->ceiling.g < 0 || map->ceiling.b < 0)
		clean_before_exit("Floor color not valid\n", 0);
}

void	parser_map_floor(char *line, t_map *map)
{
	int			i;
	static int	first;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] == 'F' || line[i] == 'f')
			i++;
		else if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'
			|| line[i] == '\v' || line[i] == '\f' || line[i] == '\r')
			i++;
		else if ((ft_isdigit(line[i]) || line[i] == ',') && !first)
		{
			first = 1;
			check_rgb_and_split(&line[i], map, ',', 'f');
			if (ft_isdigit(line[i + 1]) || line[i + 1] == ',')
				i++;
		}
		else if (line[i] == '\0' || line[i] == '\n')
			return ;
		else
			i++;
	}
	map->fase.floor = 1;
	return ;
}

void	parser_map_ceiling(char *line, t_map *map)
{
	int	i;
	static int	first;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] == 'C' || line[i] == 'c')
			i++;
		else if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'
			|| line[i] == '\v' || line[i] == '\f' || line[i] == '\r')
		i++;
		else if ((ft_isdigit(line[i]) || line[i] == ',')  && !first)
		{
			first = 1;
			check_rgb_and_split(&line[i], map, ',', 'c');
			if (ft_isdigit(line[i + 1]) || line[i + 1] == ',')
				i++;
		}
		else if (line[i] == '\0' || line[i] == '\n')
			return ;
		else
			i++;
	}
	map->fase.ceiling = 1;
	return ;
}
