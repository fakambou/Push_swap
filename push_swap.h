/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakambou <fakambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:02:01 by fakambou          #+#    #+#             */
/*   Updated: 2025/03/13 21:47:10 by fakambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/header/libft.h"
# include "libft/header/ft_printf.h"
# include <limits.h>

typedef struct s_push
{
	char	**tab_number;
	int		*tab_int;
	int		length;
	char	*temp;
	char	*res;
	int		sign;
	long	result;
}	t_push;

typedef struct s_stack
{
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	int				data;
	struct s_stack	*target_node;
	struct s_stack *next;
}	t_stack;

int		ft_error_void(char *msg);
void	check_number(t_push *push);
void	split_arg(t_push *push, char **av);
char	*ft_strjoin1(char *s1, char *s2);
void	ft_error(char *str, t_push *push);
long	ft_atoi_min_max(const char *nptr, t_push *push);
void	check_double(t_push *push);
void	free_arg(char **arg);
void	init_node(int num, t_stack **stack);
void	print_stack(t_stack	*stack);
void	free_stack(t_stack *stack);
void	sa(t_stack	**stack_a);
void	sb(t_stack	**stack_b);
void	ss(t_stack	**stack_a, t_stack **stack_b);
void	rotate_instruction(t_stack **ptr);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
t_stack	*find_last_node(t_stack **stack);
void	reverse_instruction(t_stack **stack);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack	**stack_a, t_stack **stack_b);
void	push_instruction(t_stack **dest, t_stack **src);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack	**stack_a, t_stack **stack_b);
bool	stack_sorted(t_stack *stack);
t_stack	*find_max(t_stack **stack);
void	sort_three(t_stack **stack);
int		stack_len(t_stack *stack);
void	current_index(t_stack *stack);
void	init_nodes_a(t_stack *a, t_stack *b);
void	set_target_a(t_stack *a, t_stack *b);
void	cost_analysis_a(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *stack);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name);
t_stack	*get_cheapest(t_stack *stack);
void	set_target_b(t_stack *a, t_stack *b);
void	init_nodes_b(t_stack *a, t_stack *b);
t_stack	*find_smallest(t_stack *stack);
void	sort_stack(t_stack **a, t_stack **b);
void	push_swap(t_stack *a, t_stack *b);
void	move_a_to_b(t_stack **a, t_stack **b);
void	move_b_to_a(t_stack **a, t_stack **b);
void	min_on_top(t_stack **a);

#endif