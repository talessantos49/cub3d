/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:28:50 by asoler            #+#    #+#             */
/*   Updated: 2023/12/09 19:30:15 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*aux;
	t_list	*aux1;
	int		i;

	i = 0;
	aux = *lst;
	aux1 = *lst;
	while (i < 4)
	{
		aux1 = aux->next;
		free(aux);
		aux = NULL;
		aux = aux1;
		i++;
	}
}
