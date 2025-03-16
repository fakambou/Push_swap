/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakambou <fakambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:53:03 by fakambou          #+#    #+#             */
/*   Updated: 2025/03/13 21:39:31 by fakambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error_void(char *msg)
{
	ft_printf(msg);
	exit (0);
}

void	check_number(t_push *push)
{
	int	i;
	int	j;

	i = -1;
	while (push->tab_number[++i])
	{
		j = -1;
		while (push->tab_number[i][++j])
		{
			if (push->tab_number[i][j] == '+' || push->tab_number[i][j] == '-')
			{
				if (push->tab_number[i][j + 1] == '+'
					|| push->tab_number[i][j + 1] == '-')
					ft_error("put a valid sign", push);
				if (!(ft_isdigit(push->tab_number[i][j + 1])))
					ft_error("put a valid number", push);
			}
			if ((!ft_isdigit(push->tab_number[i][j]))
				&& ((push->tab_number[i][j] != '+'
				&& push->tab_number[i][j] != '-')
				&& (push->tab_number[i][j] != ' '
				&& push->tab_number[i][j] != '\t')))
				ft_error("put numbers only", push);
		}
	}
}

void	split_arg(t_push *push, char **av)
{
	int		i;
	//char	*new;

	i = 1;
	push->length = 0;
	push->res = ft_strdup("");
	while (av[i])
	{
		push->res = ft_strjoin1(push->res, av[i]);
		push->res = ft_strjoin1(push->res, " ");
		i++;
	}
	push->tab_number = ft_split(push->res, ' ');
	while (push->tab_number[push->length])
		push->length++;
	push->tab_int = (int *)malloc(sizeof(int) * push->length + 1);
	i = 0;
	while (push->tab_number[i])
	{
		push->tab_int[i] = ft_atoi_min_max(push->tab_number[i], push);
		i++;
	}
	free(push->res);
}

void	check_double(t_push *push)
{
	int	i;
	int	j;

	i = 0;
	while (i < push->length)
	{
		j = i + 1;
		while (j < push->length)
		{
			if (push->tab_int[i] == push->tab_int[j])
				ft_error("it must not have a double", push);
			j++;
		}
		i++;
	}
}

void	free_arg(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		free(arg[i]);
		i++;
	}
	free(arg);
}

void	init_node(int num, t_stack **stack)
{
	t_stack	*new_node;
	t_stack	*tmp;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->data = num;
	new_node->index = 0;
	if (*stack == NULL)
		*stack = new_node;
	else
	{
		tmp = *stack;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_node;
	}
}
