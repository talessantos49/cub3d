/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:56:50 by asoler            #+#    #+#             */
/*   Updated: 2024/01/16 18:56:50 by tasantos         ###   ########.fr       */
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