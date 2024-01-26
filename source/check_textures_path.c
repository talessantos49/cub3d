/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:09:37 by root              #+#    #+#             */
/*   Updated: 2024/01/26 11:36:28 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	verify_file_existence(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if ((str == NULL) || (fd == -1))
	{
		free(str);
		clean_before_exit("North texture not found\n", 0);
	}
	close(fd);
}

char	*parser_map_north(char *line, int i, int k)
{
	char	*str;

	str = calloc(sizeof(char), ft_strlen(line)-1);
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
	if ((str == NULL) || (open(str, O_RDONLY) == -1))
	{
		free(str);
		clean_before_exit("North texture not found\n", 0);
	}
	return (str);
}

char	*parser_map_south(char *line, int i, int k)
{
	char	*str;

	str = calloc(sizeof(char), ft_strlen(line)-1);
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
	verify_file_existence(str);
	return (str);
}

char	*parser_map_west(char *line, int i, int k)
{
	char	*str;

	str = calloc(sizeof(char), ft_strlen(line)-1);
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
	verify_file_existence(str);
	return (str);
}

char	*parser_map_east(char *line, int i, int k)
{
	char	*str;

	str = calloc(sizeof(char), ft_strlen(line)-1);
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
	verify_file_existence(str);
	return (str);
}
