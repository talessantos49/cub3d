/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_to_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 20:28:55 by asoler            #+#    #+#             */
/*   Updated: 2024/01/14 20:31:20 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_hex_to_int(char *n_hex)
{
	int				i;
	int				base;
	unsigned int	result;

	i = ft_strlen(n_hex) - 1;
	base = 1;
	result = 0;
	while (i >= 0)
	{
		if(n_hex[i] >= '0' && n_hex[i] <= '9')
			result += (n_hex[i] - 48) * base;
		else if(n_hex[i] >= 'A' && n_hex[i] <= 'F')
			result += (n_hex[i] - 55) * base;
		base *= 16;
		i--;
	}
	return (result);
}
