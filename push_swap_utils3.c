/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:16:33 by asayad            #+#    #+#             */
/*   Updated: 2024/03/29 11:35:21 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

t_stck	*min_node(t_stck **h)
{
	t_stck	*tmp;
	int		min_num;
	t_stck	*min_node;

	tmp = *h;
	min_num = tmp->num;
	min_node = tmp;
	tmp = tmp->next;
	while (tmp != NULL)
	{
		if (min_num > tmp->num)
		{
			min_num = tmp->num;
			min_node = tmp;
		}
		tmp = tmp->next;
	}
	return (min_node);
}

t_stck	*max_node(t_stck **h)
{
	t_stck	*tmp1;
	t_stck	*max_node;

	tmp1 = *h;
	max_node = tmp1;
	while (tmp1)
	{
		if (tmp1->num > max_node->num)
			max_node = tmp1;
		tmp1 = tmp1->next;
	}
	return (max_node);
}

void	alg_three(t_stck	**h, char c)
{
	t_stck	*mx_node;

	mx_node = max_node(h);
	if (mx_node->index == 0)
	{
		r(h, c);
		if (check_if_sorted(h) == 1)
			return ;
		s(h, c);
	}
	else if (mx_node->index == 1)
	{
		reverse_r(h, c);
		if (check_if_sorted(h) == 1)
			return ;
		s(h, c);
	}
	else if (mx_node->index == 2)
	{
		if (check_if_sorted(h) == 1)
			return ;
		s(h, c);
	}
}

int	sort_stack(t_stck **h, char c)
{
	if (check_if_sorted(h) == 1)
		return (1);
	else if (stack_lenght(h) == 2)
		s(h, c);
	else if (stack_lenght(h) == 3)
		alg_three(h, c);
	else
		turc_alg(h);
	return (1);
}

void	indexate_stack(t_stck **h)
{
	t_stck	*temp;
	int		i;
	int		s_len;

	if (!h || !(*h))
		return ;
	s_len = stack_lenght(h);
	i = 0;
	temp = *h;
	while (temp)
	{
		temp->index = i;
		if (temp->index <= (s_len / 2))
			temp->above_median = true;
		else
			temp->above_median = false;
		i++;
		temp = temp->next;
	}
}
