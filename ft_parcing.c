/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakambou <fakambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:53:03 by fakambou          #+#    #+#             */
/*   Updated: 2025/02/28 15:12:42 by fakambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_number(t_push *push)
{
	int	i;
	int	j;

	i = -1;
	while(push->tab_number[++i])
	{
		j = -1;
		while(push->tab_number[i][++j])
		{
			if (push->tab_number[i][j] == '+' || push->tab_number[i][j] == '-')
			{
				if (push->tab_number[i][j + 1] == '+' 
					|| push->tab_number[i][j + 1] == '-')
					ft_error("put a valid sign");
				if(!(ft_isdigit(push->tab_number[i][j + 1])))
					ft_error("put a valid number");
			}
			if ((!ft_isdigit(push->tab_number[i][j])) 
				&& ((push->tab_number[i][j] != '+' 
				&& push->tab_number[i][j] != '-')&& (push->tab_number[i][j] != ' '
				&& push->tab_number[i][j] != '\t')))
					ft_error("put numbers only");
		}
	}
}

void	split_arg(t_push *push, char **av)
{
	int	i;
	char	*new;

	i = 1;
	push->length = 0;
	new = ft_strdup("");
	while(av[i])
	{
		new = ft_strjoin1(new, av[i]);
		new = ft_strjoin1(new, " ");
		i++;
	}
	push->tab_number = ft_split(new, ' ');
	while(push->tab_number[push->length])
		push->length++;
	push->tab_int = (int*)malloc(sizeof(int) * push->length + 1);
	i = 0;
	while(push->tab_number[i])
	{
		push->tab_int[i] = ft_atoi_min_max(push->tab_number[i]);
		i++;
	}
	free(new);
}

void	check_double(t_push *push)
{
	int	i;
	int	j;

	i = 0;
	while(i < push->length)
	{
		j = i + 1;
		while(j < push->length)
		{
			if (push->tab_int[i] == push->tab_int[j])
				ft_error("it must not have a double");
			j++;
		}
		i++;
	}
}

void	free_arg(char **arg)
{
	int	i;

	i = 0;
	while(arg[i])
	{
		free(arg[i]);
		i++;
	}
	free(arg);
}