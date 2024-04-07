/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:57:43 by asayad            #+#    #+#             */
/*   Updated: 2024/04/04 17:41:12 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_bonus.h"

int	main(int ac, char **av)
{
	t_stck	**a;
	t_stck	**b;

	if (ac == 1 || !av[1][0])
		return (1);
	a = malloc(sizeof(t_stck));
	if (!a)
		return (0);
	*a = NULL;
	b = malloc(sizeof(t_stck));
	if (!b)
		return (1);
	*b = NULL;
	if (next(ac, av, a, b) == 1)
		return (1);
	if (check_if_a_sorted(a) == 1 && stack_lenght(b) == 0)
		return (free_stack(a), free_stack(b), write(1, "OK\n", 3), 0);
	else
		return (free_stack(a), free_stack(b), write(1, "KO\n", 3), 0);
	return (free_stack(a), free_stack(b), 0);
}
