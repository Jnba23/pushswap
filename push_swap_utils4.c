/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:27:52 by asayad            #+#    #+#             */
/*   Updated: 2024/04/05 10:50:08 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	set_targets_a(t_stck **a, t_stck **b)
{
	t_stck	*tmp1;
	t_stck	*tmp2;
	long	tmp_target_num;

	tmp1 = (*a);
	while (tmp1)
	{
		tmp2 = *b;
		tmp_target_num = INT_MIN;
		while (tmp2)
		{
			if (tmp1->num > tmp2->num && tmp_target_num < tmp2->num)
			{
				tmp1->target = tmp2;
				tmp_target_num = tmp2->num;
			}
			tmp2 = tmp2->next;
		}
		if (tmp_target_num == INT_MIN)
			tmp1->target = max_node(b);
		tmp1 = tmp1->next;
	}
}

void	find_cost(t_stck **src, t_stck **dst)
{
	t_stck	*tmp;
	int		src_l;
	int		dst_l;

	src_l = stack_lenght(src);
	dst_l = stack_lenght(dst);
	tmp = *src;
	while (tmp)
	{
		tmp->cost = tmp->index;
		if (!(tmp->above_median))
			tmp->cost = src_l - tmp->index;
		if (tmp->target->above_median)
			tmp->cost += tmp->target->index;
		else
			tmp->cost += dst_l - tmp->target->index;
		tmp = tmp->next;
	}
}

void	initialize_nodes_a(t_stck **a, t_stck **b)
{
	indexate_stack(a);
	indexate_stack(b);
	set_targets_a(a, b);
	find_cost(a, b);
}

void	mediane(t_stck **src, t_stck **dst)
{
	int	i;
	int	*arr;

	while (stack_lenght(src) > 3)
	{
		arr = lst_to_arr(src);
		if (!arr)
			return ;
		sort_arr(arr, stack_lenght(src));
		i = find_mediane(arr, stack_lenght(src));
		free(arr);
		indexate_stack(src);
		mv_above_mediane_nums(src, dst, i);
		indexate_stack(src);
		indexate_stack(dst);
	}
}

void	turc_alg(t_stck **h)
{
	t_stck	**b;

	b = malloc(sizeof(t_stck));
	if (!b)
		return ;
	*b = NULL;
	mediane(h, b);
	if (stack_lenght(h) == 3 && !check_if_sorted(h))
		alg_three(h, 'a');
	while (stack_lenght(b) > 0)
	{
		initialize_nodes_b(b, h);
		find_cheapest(b);
		optimize_alg(b, h);
		set_src(b, 'b');
		set_dst(b, h, 'a');
		p(b, h, 'a');
	}
	free_stack(b);
	final_moves(h);
}
