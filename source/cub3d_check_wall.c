/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_check_wall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 23:35:57 by tasantos          #+#    #+#             */
/*   Updated: 2024/01/20 13:33:08 by tasantos         ###   ########.fr       */
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

int	check_collum(t_map *map)
{
	int	row;
	int	col;
	int	first_collum;
	int	last_collum;
	int	len_col;

	row = 0;
	col = 0;
	first_collum = 0;
	last_collum = 0;
	len_col = 0;
	while (row < map->n_row)
	{
		col = 0;
		first_collum = 0;
		last_collum = 0;
		len_col = ft_strlen(map->map[row]);
		while (col < len_col && map->map[row][col] != '\0')
		{
			ft_printf("map->map[%d][%d] = %c\n", row, col, map->map[row][col]);
			if (map->map[row][col] == '1'  && first_collum == 0)
				first_collum = 1;
			if (map->map[row][col] == '1' && (map->map[row][col + 1] == ' ' || map->map[row][col + 1] == '\n') && first_collum == 1)
				last_collum = 1;
			col++;
		}
		if (first_collum != 1 && last_collum != 1)
			return (1);
		row++;
	}
	return (0);
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

int	night_watcher(t_map *map)
{
	if (check_first_and_last_row(map))
		return (1);
	if (check_player(map))
		return (1);
	// if (check_collum(map))
	// 	return (1);
	return (0);
}
void	change_zero(t_map *map)
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
		len_col = ft_strlen(map->map[row]);
		while (col < len_col)
		{
			if (map->map[row][col] == ' ')
				map->map[row][col] = '0';
			col++;
		}
		ft_printf("%s\n", map->map[row]);
		row++;
	}
}
