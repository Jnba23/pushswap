/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:31:01 by asayad            #+#    #+#             */
/*   Updated: 2024/04/04 21:48:01 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_bonus.h"

t_stck	*ft_lstnew(int i)
{
	t_stck	*node;

	node = malloc(sizeof(t_stck));
	if (!node)
		return (NULL);
	node->num = i;
	node->next = NULL;
	node->previous = NULL;
	return (node);
}
