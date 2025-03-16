/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakambou <fakambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:19:35 by fakambou          #+#    #+#             */
/*   Updated: 2025/03/13 18:05:15 by fakambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_instruction(t_stack **ptr)
{
	t_stack	*first_node;
	t_stack	*last_node;

	if (!(*ptr))
		return ;
	first_node = *ptr;
	last_node = find_last_node(ptr);
	*ptr = first_node->next;
	first_node->next = NULL;
	last_node->next = first_node;
}

void	ra(t_stack **stack_a)
{
	rotate_instruction(stack_a);
	ft_printf("ra\n");
}

void	rb(t_stack **stack_b)
{
	rotate_instruction(stack_b);
	ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate_instruction(stack_a);
	rotate_instruction(stack_b);
	ft_printf("rr\n");
}

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b);
	current_index(*a);
	current_index(*b);
}
