/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:33:08 by asayad            #+#    #+#             */
/*   Updated: 2024/04/04 21:58:16 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_bonus.h"

void	reverse_r_both_stacks(t_stck **a, t_stck **b)
{
	reverse_r(a, 'r');
	reverse_r(b, 'f');
}

void	ft_return_p(char c)
{
	if (c == 'a')
		write(1, "pa\n", 3);
	else if (c == 'b')
		write(1, "pb\n", 3);
}

void	p(t_stck **src, t_stck **dst, char c)
{
	t_stck	*tmp;

	if (!dst)
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
		ft_return_p(c);
		return ;
	}
	*dst = tmp;
	if ((*dst)->next)
		(*dst)->next->previous = (*dst);
	indexate_stack(src);
	indexate_stack(dst);
	ft_return_p(c);
}
