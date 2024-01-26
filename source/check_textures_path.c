/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:09:37 by root              #+#    #+#             */
/*   Updated: 2024/01/26 20:39:25 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	verify_file_existence(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if ((str == NULL) || (fd == -1))
		return (1);
	close(fd);
	return (0);
}

char	*parser_map_north(char *line, int i, int k)
{
	char	*str;

	str = calloc(sizeof(char), ft_strlen(line) + 1);
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\v'
		|| line[i] == '\f' || line[i] == '\r')
		line++;
	while (line[i] != '\0' && line[i] != '\n' && line[i] != ' '
		&& line[i] != '\t' && line[i] != '\v' && line[i] != '\f'
		&& line[i] != '\r')
	{
		str[k] = line[i];
		i++;
		k++;
	}
	if (verify_file_existence(str))
	{
		free(str);
		str = NULL;
	}
	return (str);
}

char	*parser_map_south(char *line, int i, int k)
{
	char	*str;

	str = calloc(sizeof(char), ft_strlen(line) + 1);
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\v'
		|| line[i] == '\f' || line[i] == '\r')
		line++;
	while (line[i] != '\0' && line[i] != '\n' && line[i] != ' '
		&& line[i] != '\t' && line[i] != '\v' && line[i] != '\f'
		&& line[i] != '\r')
	{
		str[k] = line[i];
		i++;
		k++;
	}
	if (verify_file_existence(str))
	{
		free(str);
		str = NULL;
	}
	return (str);
}

char	*parser_map_west(char *line, int i, int k)
{
	char	*str;

	str = calloc(sizeof(char), ft_strlen(line) + 1);
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\v'
		|| line[i] == '\f' || line[i] == '\r')
		line++;
	while (line[i] != '\0' && line[i] != '\n' && line[i] != ' '
		&& line[i] != '\t' && line[i] != '\v' && line[i] != '\f'
		&& line[i] != '\r')
	{
		str[k] = line[i];
		i++;
		k++;
	}
	if (verify_file_existence(str))
	{
		free(str);
		str = NULL;
	}
	return (str);
}

char	*parser_map_east(char *line, int i, int k)
{
	char	*str;

	str = calloc(sizeof(char), ft_strlen(line) + 1);
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\v'
		|| line[i] == '\f' || line[i] == '\r')
		line++;
	while (line[i] != '\0' && line[i] != '\n' && line[i] != ' '
		&& line[i] != '\t' && line[i] != '\v' && line[i] != '\f'
		&& line[i] != '\r')
	{
		str[k] = line[i];
		i++;
		k++;
	}
	if (verify_file_existence(str))
	{
		free(str);
		str = NULL;
	}
	return (str);
}
