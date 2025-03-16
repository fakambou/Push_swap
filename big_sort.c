/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakambou <fakambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:43:40 by fakambou          #+#    #+#             */
/*   Updated: 2025/03/13 17:17:51 by fakambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(a, b);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(a, b);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}

void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->target_node != NULL)
	{
		if (cheapest_node->above_median
			&& cheapest_node->target_node->above_median)
			rotate_both(a, b, cheapest_node);
		else if (!(cheapest_node->above_median)
			&& !(cheapest_node->target_node->above_median))
			rev_rotate_both(a, b, cheapest_node);
		prep_for_push(a, cheapest_node, 'a');
		prep_for_push(b, cheapest_node->target_node, 'b');
		pb(a, b);
	}
}

void	move_b_to_a(t_stack **a, t_stack **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b);
}

void	min_on_top(t_stack **a)
{
	while ((*a)->data != find_smallest(*a)->data)
	{
		if (find_smallest(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}
