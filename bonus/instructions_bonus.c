/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:33:08 by asayad            #+#    #+#             */
/*   Updated: 2024/04/02 15:00:14 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_bonus.h"

void	s_bonus(t_stck **h)
{
	t_stck	*tmp;
	t_stck	*snd_node;

	if (!(*h) || !((*h)->next))
		return ;
	if (stack_lenght(h) < 2)
		return ;
	tmp = *h;
	snd_node = (*h)->next;
	tmp->next = snd_node->next;
	if (tmp->next)
		tmp->next->previous = tmp;
	tmp->previous = snd_node;
	snd_node->next = tmp;
	snd_node->previous = NULL;
	*h = snd_node;
	indexate_stack(h);
}

void	ss_bonus(t_stck **a, t_stck **b)
{
	s_bonus(a);
	s_bonus(b);
}

void	r_bonus(t_stck **h)
{
	t_stck	*l_node;
	t_stck	*new_first;

	if (!(*h) || !((*h)->next))
		return ;
	if (stack_lenght(h) < 2)
		return ;
	new_first = (*h)->next;
	l_node = last_node(h);
	l_node->next = *h;
	(*h)->previous = l_node;
	(*h)->next = NULL;
	new_first->previous = NULL;
	*h = new_first;
	indexate_stack(h);
}

void	r_both_stacks_bonus(t_stck **a, t_stck **b)
{
	r_bonus(a);
	r_bonus(b);
}

void	reverse_r_bonus(t_stck **h)
{
	t_stck	*l_node;

	if (!(*h) || !((*h)->next))
		return ;
	if (stack_lenght(h) < 2)
		return ;
	l_node = last_node(h);
	if (l_node->previous)
		(l_node->previous)->next = NULL;
	l_node->previous = NULL;
	l_node->next = *h;
	(*h)->previous = l_node;
	*h = l_node;
	indexate_stack(h);
}
