/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:17:09 by root              #+#    #+#             */
/*   Updated: 2024/01/16 19:39:42 by asoler           ###   ########.fr       */
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
/*
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

// int check_first_row(t_map *map)
// {
    
// }

//  Ajustar essa função
// void	found_structure(t_map *map)
// {
// 	int i;
//     int j;

//     i = 0;
//     j =0;
//     while (i < map->n_row)
//     {
//         if (map->fase.floor == 1 && map->fase.ceiling == 1)
//             if (map->matrix[i][j] == '1')
//             {
// 				// ft_printf("\nline %d - %s",i, map->matrix[i]);
//                 map->fase.map = 1;
//                 // break;
//             }
//         i++;
//     }
// }

// void	map_dimensions(t_map *map, char *path_map)
// {
// 	int		file;
// 	char	*buffer;

// 	buffer = ft_strdup("");
// 	file = map_file(path_map);
// 	if (file <= 0)
// 	{
// 		free(buffer);
// 		exit(1);
// 	}
// 	init_matrix(file, buffer, map);
// 	map->n_row = 0;
// 	while (map->matrix[map->n_row] != NULL)
// 	{
// 		map->n_col = 0;
// 		while (map->matrix[map->n_row][map->n_col] != 0)
// 			map->n_col++;
// 		map->n_row++;
// 	}
// 	found_structure(map);
// 	// verify_first_last(game);
// }

// void parser_map_round (t_map *map)
// {
//     map_dimensions(map, "maps/map_example.cub");
// }


// void	parser_atributes(t_map *map, char *line)
// {
// 	int		i;
// 	int		k;
// 	char	*tmp;

// 	i = 0;
// 	k = 0;
// 	tmp = ft_strdup("");
// 	while (line[i] != '\0')
// 	{
// 		k = 0;
// 		if (line[i] == 'F')
// 		{
// 			k = 0;
// 			while (line[i] != '\n' && line[i] != '\0')
// 				tmp[k++] = line[i++];
// 			parser_map_floor(tmp, map);
// 		}
// 		else if (line[i] == 'C')
// 		{
// 			k = 0;
// 			while (line[i] != '\n' && line[i] != '\0')
// 				tmp[k++] = line[i++];
// 			parser_map_ceiling(tmp, map);
// 		}
// 		else if (line[i] == 'N' && line[i + 1] == 'O')
// 		{
// 			k = 0;
// 			while (line[i] != '\n' && line[i] != '\0')
// 				tmp[k++] = line[i++];
// 			map->fase.no_texture = parser_map_north(tmp + 2);
// 			free(tmp);
// 			tmp = ft_strdup("");
// 		}
// 		else if (line[i] == 'S' && line[i + 1] == 'O')
// 		{
// 			k = 0;
// 			while (tmp[k] != '\0')
// 				tmp[k++] = '\0';
// 			k = 0;
// 			while (line[i] != '\n' && line[i] != '\0')
// 				tmp[k++] = line[i++];
// 			map->fase.so_texture = parser_map_south(tmp + 2);
// 		}
// 		else if (line[i] == 'W' && line[i + 1] == 'E')
// 		{
// 			k = 0;
// 			while (tmp[k] != '\0')
// 				tmp[k++] = '\0';
// 			k = 0;
// 			while (line[i] != '\n' && line[i] != '\0')
// 				tmp[k++] = line[i++];
// 			map->fase.we_texture = parser_map_west(tmp + 2);
// 		}
// 		else if (line[i] == 'E' && line[i + 1] == 'A')
// 		{
// 			k = 0;
// 			while (tmp[k] != '\0')
// 				tmp[k++] = '\0';
// 			k = 0;
// 			while (line[i] != '\n' && line[i] != '\0')
// 				tmp[k++] = line[i++];
// 			map->fase.ea_texture = parser_map_east(tmp + 2);
// 		}
// 		i++;
// 	}
// 	map->fase.attributes = 1;
// 	return ;
// }



// void insertt_node(t_node** head, char key, int value) {
//     t_node* newt_node = createt_node(key, value);
//     newt_node->next = *head;
//     *head = newt_node;
// }

// t_node* createt_node(char key,int value) {
//     t_node* newt_node = (t_node*)malloc(sizeof(t_node));
//     if (newt_node == NULL) {
//         ft_printf(stderr, "Erro ao alocar memória para o novo nó\n");
//         exit(EXIT_FAILURE);
//     }
//     strcpy(newt_node->key, key);
//     newt_node->value = value;
//     newt_node->next = NULL;
//     return newt_node;
// }

// // void insertt_node(t_node** head, char key, int value) {
//     t_node* newt_node = createt_node(key, value);
//     newt_node->next = *head;
//     *head = newt_node;
// }

// int searcht_node(t_node* head, char key) {
//     t_node* current = head;
//     while (current != NULL) {
//         if (ft_strcmp(current->key, key) == 0) {
//             return current->value;
//         }
//         current = current->next;
//     }
//     return -1;


// void	parser_map_line(t_map *map, char *line)
// {
// 	int		i;
// 	int		j;
// 	char	*buffer;

// 	i = 0;
// 	j = 0;
// 	buffer = ft_strdup("");
// 	// ft_printf("Line:\n%s", line);
// 	while (line[i] != '\0')
// 	{
// 		if (line[i] == 'F')
// 		{
// 			parser_map_floor(line, map);
// 			while (line[i] != '\n' && line[i] != '\0')
// 				i++;
// 		}
// 		else if (line[i] == 'C')
// 		{
// 			parser_map_ceiling(line, map);
// 			while (line[i] != '\n' && line[i] != '\0')
// 				i++;
// 		}
// 		else if (line[i] == 'N' && line[i + 1] == 'O')
// 		{
// 			ft_printf("NO: %s\n", line);
// 			map->fase.no_texture = parser_map_north(line + 2);
// 			ft_printf("NO: %s\n", map->fase.no_texture);
// 			while (line[i] != '\n' && line[i] != '\0')
// 				i++;
// 		}
// 		else if (line[i] == 'S' && line[i + 1] == 'O')
// 		{
// 			map->fase.so_texture = parser_map_south(line + 2);
// 			while (line[i] != '\n' && line[i] != '\0')
// 				i++;
// 		}
// 		else if (line[i] == 'W' && line[i + 1] == 'E')
// 		{
// 			map->fase.we_texture = parser_map_west(line + 2);
// 			while (line[i] != '\n' && line[i] != '\0')
// 				i++;
// 		}
// 		else if (line[i] == 'E' && line[i + 1] == 'A')
// 		{
// 			map->fase.ea_texture = parser_map_east(line + 2);
// 			while (line[i] != '\n' && line[i] != '\0')
// 				i++;
// 		}
// 		buffer[j] = line[i];
// 		// else if (line[i++] == '1' && map->fase.floor == 1 && map->fase.ceiling == 1)
// 		// 	parser_map_round();
// 		i++;
// 		j++;
// 	}
// 	ft_printf("Buffer: %s\n", buffer);
// 	return ;
// }
*/