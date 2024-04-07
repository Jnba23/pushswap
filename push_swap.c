/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:35:24 by asayad            #+#    #+#             */
/*   Updated: 2024/04/04 17:53:00 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	main(int ac, char **av)
{
	t_stck	**a;
	int		i;

	i = 1;
	if (ac == 1)
		return (1);
	else
	{
		a = malloc(sizeof(t_stck));
		if (!a)
			return (0);
		*a = NULL;
		while (i < ac)
			if (check_arg(av[i++]) == 1)
				return (free(a), write(2, "Error\n", 6), 1);
		i = 1;
		while (i < ac)
			fill_stack_a(av[i++], a);
		indexate_stack(a);
		if (check_args_doubles(a) == 1)
			return (free_stack(a), write(2, "Error\n", 6), 1);
		if (sort_stack(a, 'a') == 1)
			return (free_stack(a), 0);
	}
	return (free_stack(a), 0);
}
