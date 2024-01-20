
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:17:09 by root              #+#    #+#             */
/*   Updated: 2024/01/19 23:00:58 by tasantos         ###   ########.fr       */
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
