/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 09:42:42 by asoler            #+#    #+#             */
/*   Updated: 2023/12/07 21:51:58 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_staff(t_mlx *mlx)
{
	free(mlx->init);
	free_map(mlx->map->map);
	free(mlx->c_compass);
	ft_lstclear(&mlx->l_compass);
}

void	init_somestaff(t_mlx *mlx)
{
	t_list	*temp;
	t_list	*prev_node;
	int		i;

	mlx->c_compass = ft_strdup("NWSE");
	prev_node = NULL;
	i = 0;
	while (mlx->c_compass[i])
	{
		temp = ft_lstnew(&mlx->c_compass[i]);
		temp->prev = prev_node;
		if (prev_node)
			prev_node->next = temp;
		else
			mlx->l_compass = temp;
		prev_node = temp;
		i++;
	}
	temp = ft_lstlast(mlx->l_compass);
	temp->next = mlx->l_compass;
	mlx->l_compass->prev = temp;
}

int	main(int argc, char *argv[])
{
	t_map	read_map;
	t_mlx	mlx;

	ft_memset((void *)&read_map, 0, sizeof(t_map));
	if (argc != 2)
		return (printf("Try something like this: ./cub3d <map>.cub\n"));
	if (cub3d_read_map(argv[1], &read_map))
		exit (1);
	mlx.map = &read_map;
	init_somestaff(&mlx);
	if (cub3d_open_window(&mlx))
		exit (1);
	return (0);
}
