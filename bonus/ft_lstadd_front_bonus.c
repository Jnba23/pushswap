/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:34:44 by asayad            #+#    #+#             */
/*   Updated: 2024/04/04 21:47:56 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_bonus.h"

void	ft_lstadd_front(t_stck **lst, t_stck *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
	(*lst)->previous = NULL;
}
