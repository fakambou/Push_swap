/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakambou <fakambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:19:35 by fakambou          #+#    #+#             */
/*   Updated: 2025/02/28 17:40:36 by fakambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_node(t_push *push, t_stack *stack)
{
	t_stack	*new;
	int	i;

	i = 0;
	new = malloc(sizeof(*new));
	if (!new)
		return ;
	new -> data = push->tab_int[i];
	new -> next = NULL;
}