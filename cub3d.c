/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 09:42:42 by asoler            #+#    #+#             */
/*   Updated: 2023/10/30 21:40:44 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_map	read_map;

	ft_memset((void *)&read_map, 0, sizeof(t_map));
	if (argc == 2)
		return (printf("wrong arguments\n"));
	if (cub3d_read_map(argv[1], &read_map))
		exit (1);
	printf("Success reading map!\n");
	return (0);
}
