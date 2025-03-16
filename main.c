/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakambou <fakambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:27:55 by fakambou          #+#    #+#             */
/*   Updated: 2025/03/13 21:24:29 by fakambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char**av)
{
	int		i;
	t_stack	*a;
	t_stack	*b;
	t_push	push;
	long	num;

	i = 0;
	b = NULL;
	a = NULL;
	if (ac < 2)
		ft_error_void("insert the correct number of arguments");
	if (!av[1][0] && ac == 2)
		ft_error_void("the argument should not be empty");
	split_arg(&push, av);
	while (i < push.length)
	{
		num = push.tab_int[i];
		check_number(&push);
		check_double(&push);
		init_node((int)num, &a);
		i++;
	}
	push_swap(a, b);
	free_arg(push.tab_number);
	free(push.tab_int);
}

void	push_swap(t_stack *a, t_stack *b)
{
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stack(&a, &b);
	}
	free_stack(a);
}
