/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakambou <fakambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:07:55 by fakambou          #+#    #+#             */
/*   Updated: 2025/03/13 17:43:44 by fakambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_instruction(t_stack **ptr)
{
	t_stack	*tmp;

	if (!(*ptr))
		return ;
	tmp = (*ptr)-> next;
	(*ptr)->next = (*ptr)->next->next;
	tmp->next = *ptr;
	*ptr = tmp;
}

void	sa(t_stack	**stack_a)
{
	swap_instruction(stack_a);
	ft_printf("sa\n");
}

void	sb(t_stack	**stack_b)
{
	swap_instruction(stack_b);
	ft_printf("sb\n");
}

void	ss(t_stack	**stack_a, t_stack **stack_b)
{
	swap_instruction(stack_a);
	swap_instruction(stack_b);
	ft_printf("ss\n");
}
