/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:35:02 by asayad            #+#    #+#             */
/*   Updated: 2024/04/04 21:48:20 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_bonus.h"

void	fill_stack_a(char *arg, t_stck **h)
{
	char	**num_txt;
	int		j;

	j = 0;
	num_txt = ft_split(arg, ' ');
	while (num_txt[j])
		ft_lstadd_back(h, ft_lstnew(ft_atoi(num_txt[j++])));
	j = 0;
	free_arr(num_txt);
}

int	check_args_doubles(t_stck **h)
{
	t_stck	*temp1;
	t_stck	*temp2;

	temp1 = *h;
	while (temp1)
	{
		temp2 = *h;
		while (temp2->next)
		{
			if (temp1->num == temp2->num && temp1 != temp2)
				return (1);
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	return (0);
}

int	stack_lenght(t_stck **h)
{
	t_stck	*tmp;
	int		i;

	i = 0;
	if (!(*h))
		return (i);
	tmp = *h;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	check_if_sorted(t_stck **h)
{
	t_stck	*tmp;
	int		num_tmp;

	tmp = *h;
	num_tmp = tmp->num;
	tmp = tmp->next;
	while (tmp)
	{
		if (num_tmp > tmp->num)
			return (0);
		num_tmp = tmp->num;
		tmp = tmp->next;
	}
	return (1);
}

t_stck	*last_node(t_stck **h)
{
	t_stck	*tmp;

	tmp = *h;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
