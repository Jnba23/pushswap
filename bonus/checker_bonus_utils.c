/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 20:31:27 by asayad            #+#    #+#             */
/*   Updated: 2024/04/07 17:22:48 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_bonus.h"

int	check_line(char *line, t_stck **a, t_stck **b)
{
	if (check_character(line) == 1)
	{
		if (a_checker(line, a, b) == 1)
			return (1);
		return (0);
	}
	else
	{
		if (b_checker(line, a, b) == 1)
			return (1);
		return (0);
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
		{
			return (1);
		}
		s1++;
		s2++;
	}
	return (0);
}

int	check_if_a_sorted(t_stck **h)
{
	t_stck	*tmp;
	int		num_tmp;

	tmp = *h;
	if (!tmp)
		return (0);
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

int	check_character(char *s)
{
	int	a_count;
	int	b_count;

	a_count = 0;
	b_count = 0;
	while (*s)
	{
		if (s[a_count] == 'a')
			a_count++;
		else if (s[b_count] == 'b')
			b_count++;
		s++;
	}
	if (a_count == 1 && b_count == 0)
		return (1);
	else
		return (0);
}
