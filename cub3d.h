/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 10:01:38 by asoler            #+#    #+#             */
/*   Updated: 2023/10/29 10:25:44 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D_H
# include "includes/get_next_line.h"
# include "includes/libft.h"
# include <errno.h>
# include <fcntl.h>
#include <string.h>
# define FT_CUB3D_H

int cub3d_parse_map(char *map_path);

#endif

