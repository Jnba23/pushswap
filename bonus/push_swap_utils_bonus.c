/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:34:39 by asayad            #+#    #+#             */
/*   Updated: 2024/04/04 21:48:16 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_bonus.h"

int	ft_isspace(int c)
{
	if (c == 32)
		return (1);
	return (0);
}

int	ft_isdigit(int c, int next)
{
	if ((c >= 48 && c <= 57) && (next != 43 && next != 45))
	{
		return (1);
	}
	return (0);
}

int	is_sign(int c, int r)
{
	if ((c == 43 || c == 45) && (r >= 48 && r <= 57))
		return (1);
	return (0);
}

int	check_double_sign(char *s)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (s[i])
	{
		if (s[i] == 43 | s[i] == 45)
			index++;
		i++;
	}
	return (index);
}

int	check_arg(char *s)
{
	int		i;
	int		j;
	char	**ar;

	i = 0;
	j = 0;
	ar = NULL;
	if (just_spaces(s) || !(*s))
		return (1);
	ar = ft_split(s, ' ');
	return (after_split_check(ar));
}
