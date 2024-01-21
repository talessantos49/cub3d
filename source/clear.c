/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:56:50 by asoler            #+#    #+#             */
/*   Updated: 2024/01/20 21:57:04 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	clean_before_exit(char *str, int error)
{
	ft_printf("Error\n");
	ft_printf("%s\n", str);
	exit(error);
}

void	clean_str_exit(char	*str, char *line, int error)
{
	free(str);
	clean_before_exit(line, error);
}

void	free_all_parser(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < mlx->map->n_row)
	{
		free(mlx->map->map_aux[i]);
		i++;
	}
	free(mlx->map->map_aux);
}
