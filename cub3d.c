/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 09:42:42 by asoler            #+#    #+#             */
/*   Updated: 2023/10/29 10:05:09 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char *argv[])
{
    if (argc > 2)
        return (ft_printf("too many arguments\n"));
    if (cub3d_parse_map(argv[1]))
        return (ft_printf("somethink went wrong with your map\n"));
}