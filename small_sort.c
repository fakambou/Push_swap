/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakambou <fakambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:25:19 by fakambou          #+#    #+#             */
/*   Updated: 2025/03/13 18:05:04 by fakambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	sort_three(t_stack **stack)
{
	t_stack	*biggest_node;

	biggest_node = find_max(stack);
	if (biggest_node == (*stack))
		ra(stack);
	else if ((*stack)->next == biggest_node)
		rra(stack);
	if ((*stack)->data > (*stack)->next->data)
		sa(stack);
}

t_stack	*find_max(t_stack **stack)
{
	t_stack	*current;
	t_stack	*biggest;

	current = *stack;
	biggest = *stack;
	if (*stack == NULL)
		return (NULL);
	while (current)
	{
		if (biggest->data < current->data)
			biggest = current;
		current = current->next;
	}
	return (biggest);
}

int	stack_len(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

t_stack	*find_last_node(t_stack **stack)
{
	if (*stack == NULL)
		return (NULL);
	while ((*stack)->next)
	{
		*stack = (*stack)->next;
	}
	return (*stack);
}
