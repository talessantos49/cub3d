/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_check_wall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 23:35:57 by tasantos          #+#    #+#             */
/*   Updated: 2024/01/20 20:20:39 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_first_and_last_row(t_map *map)
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
			if (i == 0 || i == map->n_row - 1)
				if (!(ft_strchr(" 1", map->map[i][j])))
					return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	night_watcher(t_map *map)
{
	map->fase.problems = 0;
	if (check_first_and_last_row(map))
		return (1);
	if (check_player(map))
		return (1);
	change_spaces(map);
	check_player_position(map);
	route_validation(map, map->x_position, map->y_position);
	if (map->fase.problems > 0)
		return (1);
	return (0);
}

void	change_spaces(t_map *map)
{
	int	row;
	int	col;
	int	len_col;

	row = 0;
	col = 0;
	len_col = 0;
	while (row < map->n_row)
	{
		col = 0;
		len_col = ft_strlen(map->map_aux[row]);
		while (col < len_col)
		{
			if (map->map_aux[row][col] == ' ')
				map->map_aux[row][col] = '2';
			if (map->map_aux[row][col] == '\n')
				map->map_aux[row][col] = '2';
			col++;
		}
		row++;
	}
}
