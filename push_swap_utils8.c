/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils8.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 00:15:48 by asayad            #+#    #+#             */
/*   Updated: 2024/04/02 17:06:40 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	just_spaces(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] != 32)
			return (0);
		i++;
	}
	return (1);
}

int	after_split_check(char **ar)
{
	int	i;
	int	j;

	i = 0;
	while (ar[i])
	{
		j = 0;
		while (ar[i][j])
		{
			if (!(ft_isdigit(ar[i][j], ar[i][j + 1])) && !(ft_isspace(ar[i][j]))
			&& !(is_sign(ar[i][j], ar[i][j + 1])))
				return (free_arr(ar), 1);
			j++;
		}
		if (check_double_sign(ar[i]) > 1)
			return (free_arr(ar), 1);
		if (ft_atoi(ar[i]) > INT_MAX || ft_atoi(ar[i]) < INT_MIN)
			return (free_arr(ar), 1);
		i++;
	}
	return (free_arr(ar), 0);
}
