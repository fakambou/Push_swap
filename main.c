/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakambou <fakambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:27:55 by fakambou          #+#    #+#             */
/*   Updated: 2025/02/28 17:32:03 by fakambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char**av)
{
	int	i;

	i = 1;
	t_stack stack;
	t_push push;
	if (!av[1][0] && ac == 2)
		ft_error("the argument should not be empty");
	if (ac < 2)
	{
		return(ft_printf("insert the correct number of arguments"), 1);
	}
	split_arg(&push, av);
	while (av[i])
	{
		check_number(&push);
		check_double(&push);
		i++;
	}
	init_node(&push, &stack);
	if(push.tab_number)
		free_arg(push.tab_number);
	if(push.tab_int)
		free(push.tab_int);
}
