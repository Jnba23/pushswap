/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:33:08 by asayad            #+#    #+#             */
/*   Updated: 2024/04/02 00:58:25 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_bonus.h"

void	reverse_r_both_stacks_bonus(t_stck **a, t_stck **b)
{
	reverse_r_bonus(a);
	reverse_r_bonus(b);
}

void	p_bonus(t_stck **src, t_stck **dst)
{
	t_stck	*tmp;

	if (!(*src))
		return ;
	tmp = *src;
	*src = (*src)->next;
	if ((*src))
		(*src)->previous = NULL;
	tmp->next = *dst;
	if (!(*dst))
	{
		*dst = tmp;
		(*dst)->previous = NULL;
		return ;
	}
	*dst = tmp;
	if ((*dst)->next)
		(*dst)->next->previous = (*dst);
	indexate_stack(src);
	indexate_stack(dst);
}
