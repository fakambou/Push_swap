/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakambou <fakambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:16:24 by fakambou          #+#    #+#             */
/*   Updated: 2025/03/13 17:40:01 by fakambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_instruction(t_stack **src, t_stack **dest)
{
	t_stack	*node;

	if (!*src)
		return ;
	node = *src;
	*src = (*src)->next;
	node->next = *dest;
	*dest = node;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push_instruction(stack_b, stack_a);
	ft_printf("pa\n");
}

void	pb(t_stack	**stack_a, t_stack **stack_b)
{
	push_instruction(stack_a, stack_b);
	ft_printf("pb\n");
}
