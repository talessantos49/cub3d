/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:17:09 by root              #+#    #+#             */
/*   Updated: 2024/01/08 20:04:35 by root             ###   ########.fr       */
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

int	comma_check(char *line, char constant)
{
    int i;
    int j;
    int len;

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

void	parser_map_floor(char *line, t_map *map)
{
    int i;
    char    **split;

    i = 0;
    while (line[i] != '\0' && line[i] != '\n')
    {
        if (line[i] == 'F' || line[i] == 'f')
            i++;
        else if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'
             || line[i] == '\v' || line[i] == '\f' || line[i] == '\r')
            i++;
        else if ((ft_isdigit(line[i]) || line[i] == ',') && map->floor.r == 0)
        {
            if (comma_check(line, ',') == 0)
            	clean_before_exit("Error\nFloor color not valid\n", 0);
            split = ft_split(&line[i], ',');
            map->floor.r = ft_atoi(split[0]);
            map->floor.g = ft_atoi(split[1]);
            map->floor.b = ft_atoi(split[2]);
            free(split);
            if (map->floor.r > 255 || map->floor.g > 255 || map->floor.b > 255)
            	clean_before_exit("Floor color not valid\n", 0);
            ft_printf("Floor:\nr = %d\n", map->floor.r);
            ft_printf("g = %d\n", map->floor.g);
            ft_printf("b = %d\n", map->floor.b);
            if (ft_isdigit(line[i + 1]) || line[i + 1] == ',')
                i++;
        }
        else if (line[i] == '\0' || line[i] == '\n')
            return ;
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
        if (line[i] == 'C' || line[i] == 'c')
            i++;
        else if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'
             || line[i] == '\v' || line[i] == '\f' || line[i] == '\r')
            i++;
        else if ((ft_isdigit(line[i]) || line[i] == ',') && map->ceiling.r == 0)
        {
            if (comma_check(line, ',') == 0)
            	clean_before_exit("Error\nCeiling color not valid\n", 0);
            split = ft_split(&line[i], ',');
            map->ceiling.r = ft_atoi(split[0]);
            map->ceiling.g = ft_atoi(split[1]);
            map->ceiling.b = ft_atoi(split[2]);
            free(split);
            if (map->ceiling.r > 255 || map->ceiling.g > 255 || map->ceiling.b > 255)
            	clean_before_exit("Ceiling color not valid\n", 0);
            ft_printf("Ceiling:\nr = %d\n", map->ceiling.r);
            ft_printf("g = %d\n", map->ceiling.g);
            ft_printf("b = %d\n", map->ceiling.b);
            if (ft_isdigit(line[i + 1]) || line[i + 1] == ',')
                i++;
        }
        else if (line[i] == '\0' || line[i] == '\n')
            return ;
        else
            i++;
    }
    return ;
}

void	parser_map_north(char *line)
{
    int i;
    char *str;

    i = 0;
    str = calloc(sizeof(char), ft_strlen(line)-1);
    while (line[i] == ' ' || line[i] == '\t' || line[i] == '\v' || line[i] == '\f' || line[i] == '\r')
        line++;
    while (line[i] != '\0' && line[i] != '\n' && line[i] != ' ' && line[i] != '\t' && line[i] != '\v' && line[i] != '\f' && line[i] != '\r')
    {
        str[i] = line[i];
        i++;
    }
    if (str == NULL)
    {
        free(str);
    	clean_before_exit("North texture not found\n", 0); 
    }
    if (open(str, O_RDONLY) == -1)
    {
        free(str);
    	clean_before_exit("North texture not found\n", 0);
    }
    else
        free(str);
    ft_printf("parser_map_south - OK, %s\n", line);
}
void	parser_map_south(char *line)
{
    int i;
    char *str;

    i = 0;
    str = calloc(sizeof(char), ft_strlen(line)-1);
    while (line[i] == ' ' || line[i] == '\t' || line[i] == '\v' || line[i] == '\f' || line[i] == '\r')
        line++;
    while (line[i] != '\0' && line[i] != '\n' && line[i] != ' ' && line[i] != '\t' && line[i] != '\v' && line[i] != '\f' && line[i] != '\r')
    {
        str[i] = line[i];
        i++;
    }
    if (str == NULL)
    {
        free(str);
    	clean_before_exit("South texture not found\n", 0); 
    }
    if (open(str, O_RDONLY) == -1)
    {
        free(str);
    	clean_before_exit("South texture not found\n", 0);
    }
    else
        free(str);
    ft_printf("parser_map_south - OK, %s\n", line);
}
void	parser_map_west(char *line)
{
    int i;
    char *str;

    i = 0;
    str = calloc(sizeof(char), ft_strlen(line)-1);
    while (line[i] == ' ' || line[i] == '\t' || line[i] == '\v' || line[i] == '\f' || line[i] == '\r')
        line++;
    while (line[i] != '\0' && line[i] != '\n' && line[i] != ' ' && line[i] != '\t' && line[i] != '\v' && line[i] != '\f' && line[i] != '\r')
    {
        str[i] = line[i];
        i++;
    }
    if (str == NULL)
    {
        free(str);
    	clean_before_exit("West texture not found\n", 0); 
    }
    if (open(str, O_RDONLY) == -1)
    {
        free(str);
    	clean_before_exit("West texture not found\n", 0);
    }
    else
        free(str);
    ft_printf("parser_map_west - OK, %s\n", line);
}
void	parser_map_east(char *line)
{
    int i;
    char *str;

    i = 0;
    str = calloc(sizeof(char), ft_strlen(line)-1);
    while (line[i] == ' ' || line[i] == '\t' || line[i] == '\v' || line[i] == '\f' || line[i] == '\r')
        line++;
    while (line[i] != '\0' && line[i] != '\n' && line[i] != ' ' && line[i] != '\t' && line[i] != '\v' && line[i] != '\f' && line[i] != '\r')
    {
        str[i] = line[i];
        i++;
    }
    if (str == NULL)
    {
        free(str);
    	clean_before_exit("East texture not found\n", 0); 
    }
    if (open(str, O_RDONLY) == -1)
    {
        free(str);
    	clean_before_exit("East texture not found\n", 0);
    }
    else
        free(str);
    ft_printf("parser_map_east - OK, %s\n", line);
}
void	init_matrix(int filename, char *buffer, t_map *map)
{
	char	*line;

	while (1)
	{
		line = get_next_line(filename);
		if (!line)
			break ;
		buffer = ft_strjoin_gnl(buffer, line);
		free(line);
	}
	map->matrix = ft_split(buffer, '\n');
	free(buffer);
}

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
// void	verify_first_last(t_game *game)
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	while (++i < game->map.n_row)
// 	{
// 		j = -1;
// 		while (++j < game->map.n_col)
// 		{
// 			if (!(ft_strchr ("10PCE", game->map.matrix[i][j])))
// 				exit_map("Error-INVALID MAP\nIncorrect Attributes!\n", game);
// 			if (game->map.matrix[0][j] != '1')
// 				exit_map("Error-INVALID MAP\nWall around Invalid!\n", game);
// 			if (game->map.matrix[game->map.n_row - 1][j] != '1')
// 				exit_map("Error-INVALID MAP\nWall around Invalid!\n", game);
// 		}
// 		if (game->map.matrix[i][j - 1] != '1')
// 			exit_map("Error-INVALID MAP\nMap Around Invalid!\n", game);
// 		if (game->map.matrix[i][0] != '1')
// 			exit_map("Error- INVALID MAP\nMap missing wall!\n", game);
// 		if (game->map.matrix[i][game->map.n_col] != game->map.matrix[0][j])
// 			exit_map("Error- INVALID MAP\nMap around Invalid!\n", game);
// 	}
// }

//  Ajustar essa função
void	found_structure(t_map *map)
{
	int i;
    int j;
    // int init_map;
    // int end_map;

    i = 0;
    j =0;
    // init_map = 0;
    // end_map = 0;
    while (i < map->n_row)
    {
        if(map->matrix[i][j] == '1')
            ft_printf("%s\n", map->matrix[i]);
        i++;
    }
}

void	map_dimensions(t_map *map, char *path_map)
{
	int		file;
	char	*buffer;

	buffer = ft_strdup("");
	file = map_file(path_map);
	if (file <= 0)
	{
		free(buffer);
		exit(1);
	}
	init_matrix(file, buffer, map);
	map->n_row = 0;
	while (map->matrix[map->n_row] != NULL)
	{
		map->n_col = 0;
		while (map->matrix[map->n_row][map->n_col] != 0)
			map->n_col++;
		map->n_row++;
	}
	if (map->n_row < 3 || map->n_col < 3)
		clean_before_exit("Error- INVALID MAP\n Map dimensions Invalid!\n", 0);
	found_structure(map);
	// verify_first_last(game);
}


void parser_map_round (t_map *map)
{
    map_dimensions(map, "maps/map_example.cub");
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
            parser_map_north(line + 2);
        else if (line[i] == 'S' && line[i + 1] == 'O')
            parser_map_south(line + 2);
        else if (line[i] == 'W' && line[i + 1] == 'E')
            parser_map_west(line + 2);
        else if (line[i] == 'E' && line[i + 1] == 'A')
            parser_map_east(line + 2);
        else if (line[i] == ' ' || line[i] == '\t' || line[i] == '\v' || line[i] == '\f' || line[i] == '\r')
			i++;
		i++;
	}
	parser_map_round(map);
	return ;
}
