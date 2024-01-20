/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 20:19:10 by tasantos          #+#    #+#             */
/*   Updated: 2024/01/20 20:22:27 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	route_validation(t_map *map, int x, int y)
{
	if (map->map_aux[x][y] == '2')
			map->fase.problems++;
	if (map->map_aux[x][y] == '1' || map->map_aux[x][y] == 'X')
		return ;
	if (map->map_aux[x][y] == '0' || map->map_aux[x][y] == 'N' ||
		map->map_aux[x][y] == 'E' || map->map_aux[x][y] == 'W' ||
		map->map_aux[x][y] == 'S')
	{
		map->map_aux[x][y] = 'X';
		route_validation(map, x + 1, y);
		route_validation(map, x - 1, y);
		route_validation(map, x, y + 1);
		route_validation(map, x, y - 1);
		return ;
	}
}

void	check_player_position(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < map->n_row)
	{
		y = 0;
		while (y < map->n_col)
		{
			if (map->map_aux[x][y] == 'N' || map->map_aux[x][y] == 'S'
			|| map->map_aux[x][y] == 'E' || map->map_aux[x][y] == 'W')
			{
				map->x_position = x;
				map->y_position = y;
			}
			y++;
		}
		x++;
	}
}

int	check_player(t_map *map)
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
			if (ft_strchr("NSEW", map->map[i][j]))
				map->fase.player++;
			j++;
		}
		i++;
	}
	if (map->fase.player != 1)
		return (1);
	return (0);
}

void	make_square(t_map *map, int row, int k)
{
	int		i;
	char	*tmp;

	i = 0;
	row = 0;
	tmp = malloc(sizeof(char *) * ((map->n_row + 1) * (map->n_col + 1)));
	while (row < map->n_row)
	{
		k = 0;
		while (k < map->n_col)
		{
			if (map->map[row][k] == '1' || map->map[row][k] == '0'
			|| map->map[row][k] == 'N' || map->map[row][k] == 'S'
			|| map->map[row][k] == 'E' || map->map[row][k] == 'W')
				tmp[i++] = map->map[row][k];
			else
				tmp[i++] = '2';
			k++;
		}
		tmp[i++] = '\n';
		row++;
	}
	tmp[i] = '\0';
	map->map_aux = ft_split(tmp, '\n');
}
