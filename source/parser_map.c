/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:42:15 by asoler            #+#    #+#             */
/*   Updated: 2024/01/26 23:27:12 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	map_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\n File \"%s\" doesn't exist\n", filename);
		close(fd);
		return (fd);
	}
	return (fd);
}

void	check_map_exist(t_map *read_map)
{
	int	i;

	i = 0;
	while (read_map->original[i])
		i++;
	if (i < 7)
	{
		ft_printf("Error\nMap must exist\n");
		clear_texture(read_map);
		free_map(read_map->original);
		exit (1);
	}
}
