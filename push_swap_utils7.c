/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils7.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 22:14:02 by asayad            #+#    #+#             */
/*   Updated: 2024/04/02 16:20:33 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	*lst_to_arr(t_stck **h)
{
	int		*stack;
	t_stck	*tmp;
	int		i;

	if (!h || !(*h))
		return (NULL);
	i = 0;
	stack = malloc (sizeof(int) * stack_lenght(h));
	if (!stack)
		return (NULL);
	tmp = *h;
	while (tmp)
	{
		stack[i] = tmp->num;
		tmp = tmp->next;
		i++;
	}
	return (stack);
}

void	sort_arr(int *arr, int size)
{
	int	tmp;
	int	i;
	int	j;

	if (!arr)
		return ;
	i = 0;
	j = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	find_mediane(int *arr, int size)
{
	int	mediane_index;

	if (!arr)
		return (0);
	mediane_index = size / 2;
	return (arr[mediane_index]);
}

void	mv_above_mediane_nums(t_stck **src, t_stck **dst, int i)
{
	t_stck	*tmp;
	int		moves_cnt;

	tmp = *src;
	while (tmp && stack_lenght(src) > 3)
	{
		indexate_stack(src);
		moves_cnt = tmp->index;
		if (tmp->above_median && tmp->num < i)
		{
			set_stck_r(moves_cnt, src, 'a');
			p(src, dst, 'b');
			tmp = *src;
			continue ;
		}
		else if (!tmp->above_median && tmp->num < i)
		{
			moves_cnt = stack_lenght(src) - tmp->index;
			set_stck_rev_r(moves_cnt, src, 'a');
			p(src, dst, 'b');
			tmp = *src;
			continue ;
		}
		tmp = tmp->next;
	}
}

void	free_stack(t_stck **h)
{
	t_stck	*temp;

	if (!*h)
		return (free(h));
	while (*h)
	{
		temp = *h;
		(*h) = (*h)->next;
		if (temp)
		{
			free(temp);
			temp = NULL;
		}
	}
	if (h)
	{
		free(h);
		h = NULL;
	}
}
