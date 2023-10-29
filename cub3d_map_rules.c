/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_map_rules.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 10:00:36 by asoler            #+#    #+#             */
/*   Updated: 2023/10/29 10:27:41 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	verify_map_file_type(char *map_argument)
{
	size_t	len;
	char	*type;

	len = ft_strlen(map_argument);
	type = ft_strnstr(map_argument, ".cub", len);
	if (!type || (*(type + 4) != '\0'))
		return (1);
	return (0);
}

int cub3d_parse_map(char *map_path)
{
    int fd;

    fd = open(map_path, O_RDONLY);
    if (verify_map_file_type(map_path))
        return (ft_printf("File most end with .cub\n"));
    if (fd < 0)
        return (ft_printf("ERROR: %s\n", strerror(errno)));
    ft_printf("Sucess opening file!\n");
    close(fd);
}
