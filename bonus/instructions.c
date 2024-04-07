/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:33:08 by asayad            #+#    #+#             */
/*   Updated: 2024/04/04 21:58:03 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_bonus.h"

void	s(t_stck **h, char c)
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
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
}

void	ss(t_stck **a, t_stck **b)
{
	s(a, 'a');
	s(b, 'b');
}

void	r(t_stck **h, char c)
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
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
	else if (c == 'r')
		write(1, "rr\n", 3);
	else
		return ;
}

void	r_both_stacks(t_stck **a, t_stck **b)
{
	r(a, 'r');
	r(b, 'd');
}

void	reverse_r(t_stck **h, char c)
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
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
	else if (c == 'r')
		write(1, "rrr\n", 4);
	else
		return ;
}
