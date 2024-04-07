/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils6_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:34:20 by asayad            #+#    #+#             */
/*   Updated: 2024/04/05 10:48:30 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_bonus.h"

void	initialize_nodes_b(t_stck **b, t_stck **a)
{
	indexate_stack(b);
	indexate_stack(a);
	set_targets_b(b, a);
	find_cost(b, a);
}

void	optimize_alg(t_stck **src, t_stck **dst)
{
	t_stck	*tmp;

	tmp = *src;
	while (tmp)
	{
		if (tmp->cheapest && tmp->above_median && tmp->target->above_median)
		{
			while (tmp->index != 0 && tmp->target->index != 0)
				r_both_stacks(src, dst);
		}
		else if (tmp->cheapest && !tmp->above_median
			&& !tmp->target->above_median)
		{
			while (tmp->index != 0 && tmp->target->index != 0)
				reverse_r_both_stacks(src, dst);
		}
		tmp = tmp->next;
	}
}

void	final_moves(t_stck **h)
{
	int	l;
	int	min_nd_indx;

	indexate_stack(h);
	min_nd_indx = min_node(h)->index;
	l = stack_lenght(h) - min_nd_indx;
	if (min_node(h)->above_median)
	{
		while (min_nd_indx-- > 0)
		{
			if (!check_if_sorted(h))
				r(h, 'a');
		}
	}
	else
	{
		while (l-- > 0)
		{
			if (!check_if_sorted(h))
				reverse_r(h, 'a');
		}
	}
}

void	find_cheapest(t_stck **h)
{
	t_stck	*cheapest_n;
	t_stck	*tmp;

	tmp = *h;
	while (tmp)
	{
		tmp->cheapest = false;
		tmp = tmp->next;
	}
	cheapest_n = (*h);
	cheapest_n->cheapest = true;
	tmp = *h;
	tmp = tmp->next;
	while (tmp)
	{
		if (cheapest_n->cost > tmp->cost)
		{
			cheapest_n->cheapest = false;
			cheapest_n = tmp;
			cheapest_n->cheapest = true;
		}
		tmp = tmp->next;
	}
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free (arr);
}
