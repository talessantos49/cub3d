/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:17:09 by root              #+#    #+#             */
/*   Updated: 2023/11/12 23:08:03 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	parser_map_floor(char *line, t_map *map)
{
    int i;
    char    **split;

    i = 0;
    while (line[i] != '\0' && line[i] != '\n')
    {
        ft_printf("inside floor, %svalor de i:%d\n", line, i);
        if (line[i] == 'F' || line[i] == 'f')
        {
            ft_printf("position, %c\n", line[i]);
            i++;
        }
        else if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'
             || line[i] == '\v' || line[i] == '\f' || line[i] == '\r')
        {
            ft_printf("space\n");
            i++;
        }
        else if ((ft_isdigit(line[i]) || line[i] == ',') && map->floor.r == 0)
        {
            split = ft_split(&line[i], ',');
            map->floor.r = ft_atoi(split[0]);
            map->floor.g = ft_atoi(split[1]);
            map->floor.b = ft_atoi(split[2]);
            ft_printf("r = %d\n", map->floor.r);
            ft_printf("g = %d\n", map->floor.g);
            ft_printf("b = %d\n", map->floor.b);
            if (ft_isdigit(line[i + 1]) || line[i + 1] == ',')
                i++;
        }
        else if (line[i] == '\0' || line[i] == '\n')
        {
            ft_printf("end of line\n");
            return ;
        }
        else
            i++;
    }
    return ;
}

void	parser_map_ceiling(char *line, t_map *map)
{
    int i;
    char    **split;

    i = 0;
    while (line[i] != '\0' && line[i] != '\n')
    {
        ft_printf("inside ceiling, %svalor de i:%d\n", line, i);
        if (line[i] == 'C' || line[i] == 'c')
        {
            ft_printf("position, %c\n", line[i]);
            i++;
        }
        else if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'
             || line[i] == '\v' || line[i] == '\f' || line[i] == '\r')
        {
            ft_printf("space\n");
            i++;
        }
        else if ((ft_isdigit(line[i]) || line[i] == ',') && map->ceiling.r == 0)
        {
            split = ft_split(&line[i], ',');
            map->ceiling.r = ft_atoi(split[0]);
            map->ceiling.g = ft_atoi(split[1]);
            map->ceiling.b = ft_atoi(split[2]);
            ft_printf("r = %d\n", map->ceiling.r);
            ft_printf("g = %d\n", map->ceiling.g);
            ft_printf("b = %d\n", map->ceiling.b);
            if (ft_isdigit(line[i + 1]) || line[i + 1] == ',')
                i++;
        }
        else if (line[i] == '\0' || line[i] == '\n')
        {
            ft_printf("end of line\n");
            return ;
        }
        else
            i++;
    }
    return ;
}

void	parser_map_north(char *line)
{
    ft_printf("parser_map_north, %s\n", line);
}
void	parser_map_south(char *line)
{
    ft_printf("parser_map_south, %s\n", line);
}
void	parser_map_west(char *line)
{
    ft_printf("parser_map_west, %s\n", line);
}
void	parser_map_east(char *line)
{
    ft_printf("parser_map_east, %s\n", line);
}

void	parser_map_line(char *line, t_map *map)
{
	int i;

	i = 0;
    while (line[i] != '\0' && line[i] != '\n')
	{
        if (line[i] == 'F')
            parser_map_floor(line, map);
        else if (line[i] == 'C')
            parser_map_ceiling(line, map);
        else if (line[i] == 'N' && line[i + 1] == 'O')
            parser_map_north(line);
        else if (line[i] == 'S' && line[i + 1] == 'O')
            parser_map_south(line);
        else if (line[i] == 'W' && line[i + 1] == 'E')
            parser_map_west(line);
        else if (line[i] == 'E' && line[i + 1] == 'A')
            parser_map_east(line);
        else if (line[i] == ' ' || line[i] == '\t' || line[i] == '\v' || line[i] == '\f' || line[i] == '\r')
            i++;
        i++;
    }
    return ;
}