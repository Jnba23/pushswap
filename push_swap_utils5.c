/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:16:48 by asayad            #+#    #+#             */
/*   Updated: 2024/03/28 23:35:07 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	set_targets_b(t_stck **b, t_stck **a)
{
	t_stck	*tmp1;
	t_stck	*tmp2;
	long	tmp_target_num;

	tmp1 = *b;
	while (tmp1)
	{
		tmp2 = *a;
		tmp_target_num = INT_MAX;
		while (tmp2)
		{
			if (tmp2->num > tmp1->num && tmp_target_num > tmp2->num)
			{
				tmp1->target = tmp2;
				tmp_target_num = tmp2->num;
			}
			tmp2 = tmp2->next;
		}
		if (tmp_target_num == INT_MAX)
			tmp1->target = min_node(a);
		tmp1 = tmp1-> next;
	}
}

void	set_stck_r(int i, t_stck **h, char c)
{
	while (i > 0)
	{
		r(h, c);
		i--;
	}
}

void	set_stck_rev_r(int i, t_stck **h, char c)
{
	while (i > 0)
	{
		reverse_r(h, c);
		i--;
	}
}

void	set_src(t_stck **src, char c)
{
	t_stck	*tmp;
	int		stck_l;

	tmp = *src;
	while (tmp)
	{
		if (tmp->cheapest)
		{
			if (tmp->above_median)
			{
				stck_l = tmp->index;
				set_stck_r(stck_l, src, c);
			}
			else
			{
				stck_l = stack_lenght(src) - tmp->index;
				set_stck_rev_r(stck_l, src, c);
			}
		}
		tmp = tmp->next;
	}
}

void	set_dst(t_stck **src, t_stck **dst, char c)
{
	t_stck	*tmp;
	int		stck_l;

	tmp = *src;
	while (tmp)
	{
		if (tmp->cheapest)
		{
			if (tmp->target->above_median)
			{
				stck_l = tmp->target->index;
				set_stck_r(stck_l, dst, c);
			}
			else
			{
				stck_l = stack_lenght(dst) - tmp->target->index;
				set_stck_rev_r(stck_l, dst, c);
			}
		}
		tmp = tmp->next;
	}
}
