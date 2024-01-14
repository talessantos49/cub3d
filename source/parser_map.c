/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:17:09 by root              #+#    #+#             */
/*   Updated: 2024/01/14 19:13:27 by asoler           ###   ########.fr       */
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

// int check_first_row(t_map *map)
// {
    
// }

//  Ajustar essa função
void	found_structure(t_map *map)
{
	int i;
    int j;

    i = 0;
    j =0;
    while (i < map->n_row)
    {
        if (map->fase.floor == 1 && map->fase.ceiling == 1)
            if (map->matrix[i][j] == '1')
            {
                //ft_printf("ROW: %d : %s, \n", map->n_row, map->matrix[i]);
                map->fase.map = 1;
                break;
            }
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
    while ((line[i] != '\0' && line[i] != '\n') || map->fase.completed == 1)
	{
        if (line[i] == 'F')
            parser_map_floor(line, map);
        else if (line[i] == 'C')
            parser_map_ceiling(line, map);
        else if (line[i] == 'N' && line[i + 1] == 'O')
            map->fase.no_texture = parser_map_north(line + 2);
        else if (line[i] == 'S' && line[i + 1] == 'O')
            map->fase.so_texture = parser_map_south(line + 2);
        else if (line[i] == 'W' && line[i + 1] == 'E')
            map->fase.we_texture = parser_map_west(line + 2);
        else if (line[i] == 'E' && line[i + 1] == 'A')
            map->fase.ea_texture = parser_map_east(line + 2);
        else if (line[i] == '1' && line[i + 1] == '1' && line[i + 2] == '1' && map->fase.floor == 1 && map->fase.ceiling == 1)
            parser_map_round(map);
        else if (line[i] == ' ' || line[i] == '\t' || line[i] == '\v' || line[i] == '\f' || line[i] == '\r')
			i++;
		i++;
	}
	parser_map_round(map);
	return ;
}
// void insertNode(Node** head, char key, int value) {
//     Node* newNode = createNode(key, value);
//     newNode->next = *head;
//     *head = newNode;
// }

// Node* createNode(char key,int value) {
//     Node* newNode = (Node*)malloc(sizeof(Node));
//     if (newNode == NULL) {
//         ft_printf(stderr, "Erro ao alocar memória para o novo nó\n");
//         exit(EXIT_FAILURE);
//     }
//     strcpy(newNode->key, key);
//     newNode->value = value;
//     newNode->next = NULL;
//     return newNode;
// }

// // void insertNode(Node** head, char key, int value) {
//     Node* newNode = createNode(key, value);
//     newNode->next = *head;
//     *head = newNode;
// }

// int searchNode(Node* head, char key) {
//     Node* current = head;
//     while (current != NULL) {
//         if (ft_strcmp(current->key, key) == 0) {
//             return current->value;
//         }
//         current = current->next;
//     }
//     return -1;