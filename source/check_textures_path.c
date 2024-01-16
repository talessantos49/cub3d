/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:09:37 by root              #+#    #+#             */
/*   Updated: 2024/01/15 12:37:49 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	parser_map_north(char *line)
{
	int		i;
	char	*str;

	i = 0;
	str = calloc(sizeof(char), ft_strlen(line)-1);
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\v'
		|| line[i] == '\f' || line[i] == '\r')
		line++;
	while (line[i] != '\0' && line[i] != '\n' && line[i] != ' '
		&& line[i] != '\t' && line[i] != '\v' && line[i] != '\f'
		&& line[i] != '\r')
	{
		str[i] = line[i];
		i++;
	}
	if ((str == NULL) || (open(str, O_RDONLY) == -1))
	{
		free(str);
		clean_before_exit("North texture not found\n", 0);
	}
	else
		free(str);
	return (1);
}

int	parser_map_south(char *line)
{
	int		i;
	char	*str;

	i = 0;
	str = calloc(sizeof(char), ft_strlen(line)-1);
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\v'
		|| line[i] == '\f' || line[i] == '\r')
		line++;
	while (line[i] != '\0' && line[i] != '\n' && line[i] != ' '
		&& line[i] != '\t' && line[i] != '\v' && line[i] != '\f'
		&& line[i] != '\r')
	{
		str[i] = line[i];
		i++;
	}
	if ((str == NULL) || (open(str, O_RDONLY) == -1))
	{
		free(str);
		clean_before_exit("South texture not found\n", 0);
	}
	else
		free(str);
	return (1);
}

int	parser_map_west(char *line)
{
	int		i;
	char	*str;

	i = 0;
	str = calloc(sizeof(char), ft_strlen(line)-1);
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\v'
		|| line[i] == '\f' || line[i] == '\r')
		line++;
	while (line[i] != '\0' && line[i] != '\n' && line[i] != ' '
		&& line[i] != '\t' && line[i] != '\v' && line[i] != '\f'
		&& line[i] != '\r')
	{
		str[i] = line[i];
		i++;
	}
	if ((str == NULL) || (open(str, O_RDONLY) == -1))
	{
		free(str);
		clean_before_exit("West texture not found\n", 0);
	}
	else
		free(str);
	return (1);
}

int	parser_map_east(char *line)
{
	int		i;
	char	*str;

	i = 0;
	str = calloc(sizeof(char), ft_strlen(line)-1);
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\v'
		|| line[i] == '\f' || line[i] == '\r')
		line++;
	while (line[i] != '\0' && line[i] != '\n' && line[i] != ' '
		&& line[i] != '\t' && line[i] != '\v' && line[i] != '\f'
		&& line[i] != '\r')
	{
		str[i] = line[i];
		i++;
	}
	if ((str == NULL) || (open(str, O_RDONLY) == -1))
	{
		free(str);
		clean_before_exit("Error\nEast texture not found\n", 0);
	}
	else
		free(str);
	return (1);
}
