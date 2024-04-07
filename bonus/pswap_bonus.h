/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:54:15 by asayad            #+#    #+#             */
/*   Updated: 2024/04/05 10:47:50 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSWAP_BONUS_H
# define PSWAP_BONUS_H
# include "./gnl/get_next_line.h"
# include <stdio.h>
# include <libc.h>
# include <limits.h>
# include <stdbool.h>

typedef struct stack
{
	int				num ;
	int				index;
	int				cost;
	bool			above_median;
	bool			cheapest;
	struct stack	*target;
	struct stack	*next;
	struct stack	*previous;
}	t_stck;

void		s(t_stck **h, char c);
void		ss(t_stck **a, t_stck **b);
void		r(t_stck **h, char c);
void		r_both_stacks(t_stck **a, t_stck **b);
void		reverse_r(t_stck **h, char c);
void		reverse_r_both_stacks(t_stck **a, t_stck **b);
void		p(t_stck **src, t_stck **dst, char c);
void		s_bonus(t_stck **h);
void		ss_bonus(t_stck **a, t_stck **b);
void		r_bonus(t_stck **h);
void		r_both_stacks_bonus(t_stck **a, t_stck **b);
void		reverse_r_bonus(t_stck **h);
void		reverse_r_both_stacks_bonus(t_stck **a, t_stck **b);
void		p_bonus(t_stck **src, t_stck **dst);
char		**ft_split(char *s, char c);
int			check_arg(char *s);
t_stck		*ft_lstnew(int i);
void		fill_stack_a(char *arg, t_stck	**h);
long long	ft_atoi(char *str);
int			ft_isdigit(int c, int next);
int			ft_isspace(int c);
int			is_sign(int c, int r);
int			check_double_sign(char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
void		ft_lstadd_back(t_stck **lst, t_stck *new);
t_stck		*ft_lstnew(int i);
int			check_args_doubles(t_stck **h);
int			sort_stack(t_stck **h, char c);
int			stack_lenght(t_stck **h);
int			check_if_sorted(t_stck **h);
t_stck		*last_node(t_stck **h);
int			check_if_a_sorted(t_stck **h);
void		alg_three(t_stck **h, char c);
t_stck		*min_node(t_stck **h);
t_stck		*max_node(t_stck **h);
void		indexate_stack(t_stck **h);
void		s_bonus(t_stck **h);
void		ss_bonus(t_stck **a, t_stck **b);
void		r_bonus(t_stck **h);
void		r_both_stacks_bonus(t_stck **a, t_stck **b);
void		reverse_r_bonus(t_stck **h);
void		reverse_r_both_stacks_bonus(t_stck **a, t_stck **b);
void		p_bonus(t_stck **src, t_stck **dst);
void		turc_alg(t_stck **h);
void		set_targets_a(t_stck **h, t_stck **b);
void		find_cost(t_stck **src, t_stck **dst);
void		initialize_nodes_a(t_stck **a, t_stck **b);
void		find_cheapest(t_stck **h);
void		initialize_nodes_b(t_stck **b, t_stck **a);
void		set_targets_b(t_stck **b, t_stck **a);
void		final_moves(t_stck **h);
void		ft_lstadd_front(t_stck **lst, t_stck *new);
void		set_src(t_stck **src, char c);
void		set_stck_r(int i, t_stck **h, char c);
void		set_stck_rev_r(int i, t_stck **h, char c);
void		set_dst(t_stck **src, t_stck **dst, char c);
void		optimize_alg(t_stck **src, t_stck **dst);
int			*lst_to_arr(t_stck **h);
void		sort_arr(int *arr, int size);
void		mv_above_mediane_nums(t_stck **src, t_stck **dst, int mediane);
int			find_mediane(int *arr, int size);
void		mediane(t_stck **src, t_stck **dst);
void		free_stack(t_stck **h);
void		free_arr(char **arr);
int			check_line(char *line, t_stck **a, t_stck **b);
int			ft_strcmp(char *s1, char *s2);
void		s(t_stck **h, char c);
void		ss(t_stck **a, t_stck **b);
void		r(t_stck **h, char c);
void		r_both_stacks(t_stck **a, t_stck **b);
void		reverse_r(t_stck **h, char c);
void		reverse_r_both_stacks(t_stck **a, t_stck **b);
void		p(t_stck **src, t_stck **dst, char c);
int			just_spaces(char *arg);
int			after_split_check(char **ar);
int			check_character(char *s);
int			a_checker(char *line, t_stck **a, t_stck **b);
int			b_checker(char *line, t_stck **a, t_stck **b);
int			next(int ac, char **av, t_stck **a, t_stck **b);

#endif
