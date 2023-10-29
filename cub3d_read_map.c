/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_read_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:40:49 by asoler            #+#    #+#             */
/*   Updated: 2023/10/29 17:47:13 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	verify_map_file_type(char *map_name)
{
	size_t	len;
	char	*type;

	len = ft_strlen(map_name);
	type = ft_strnstr(map_name, ".cub", len);
	if (!type || (*(type + 4) != '\0'))
		return (1);
	return (0);
}

int	cub3d_read_map(char *map_path, t_map *read_map)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (verify_map_file_type(map_path))
		return (printf("File most end with .cub\n"));
	if (fd < 0)
		return (printf("ERROR: %s\n", strerror(errno)));
	cub3d_parse_map(fd, read_map);
	close(fd);
	return (0);
}
