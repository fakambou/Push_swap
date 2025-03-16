/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakambou <fakambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:19:39 by fakambou          #+#    #+#             */
/*   Updated: 2025/03/13 17:40:46 by fakambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_instruction(t_stack **stack)
{
	t_stack	*last_node;
	t_stack	*second_last;

	if (!(*stack))
		return ;
	last_node = *stack;
	while (last_node->next != NULL)
		last_node = last_node->next;
	second_last = *stack;
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	last_node->next = *stack;
	second_last->next = NULL;
	*stack = last_node;
}

void	rra(t_stack **stack_a)
{
	reverse_instruction(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_stack **stack_b)
{
	reverse_instruction(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack	**stack_a, t_stack **stack_b)
{
	reverse_instruction(stack_a);
	reverse_instruction(stack_b);
	ft_printf("rrr\n");
}

void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b);
	current_index(*a);
	current_index(*b);
}
