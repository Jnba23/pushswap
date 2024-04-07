/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus_utils1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 20:31:27 by asayad            #+#    #+#             */
/*   Updated: 2024/04/05 10:39:09 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_bonus.h"

int	a_checker(char *line, t_stck **a, t_stck **b)
{
	if (ft_strcmp(line, "sa\n") == 0)
		s_bonus(a);
	else if (ft_strcmp(line, "ra\n") == 0)
		r_bonus(a);
	else if (ft_strcmp(line, "rra\n") == 0)
		reverse_r_bonus(a);
	else if (ft_strcmp(line, "pa\n") == 0)
		p_bonus(b, a);
	else
		return (1);
	return (0);
}

int	b_checker(char *line, t_stck **a, t_stck **b)
{
	if (ft_strcmp(line, "pb\n") == 0)
		p_bonus(a, b);
	else if (ft_strcmp(line, "sb\n") == 0)
		s_bonus(b);
	else if (ft_strcmp(line, "rb\n") == 0)
		r_bonus(b);
	else if (ft_strcmp(line, "rrb\n") == 0)
		reverse_r_bonus(b);
	else if (ft_strcmp(line, "rr\n") == 0)
		r_both_stacks_bonus(a, b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		reverse_r_both_stacks_bonus(a, b);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss_bonus(a, b);
	else
		return (1);
	return (0);
}

int	next(int ac, char **av, t_stck **a, t_stck **b)
{
	int		i;
	char	*line;

	i = 1;
	while (i < ac)
		if (check_arg(av[i++]) == 1)
			return (free(a), free(b), write(2, "Error\n", 6), 1);
	i = 1;
	while (i < ac)
		fill_stack_a(av[i++], a);
	indexate_stack(a);
	if (check_args_doubles(a) == 1)
		return (free_stack(a), free_stack(b), write(2, "Error\n", 6), 1);
	line = get_next_line(0);
	while (line)
	{
		if (check_line(line, a, b) == 1)
			return (free(line), free_stack(a),
				free_stack(b), write(2, "Error\n", 6), 1);
		free(line);
		line = get_next_line(0);
	}
	if (line)
		free(line);
	return (0);
}
