/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakambou <fakambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:28:13 by fakambou          #+#    #+#             */
/*   Updated: 2025/03/13 21:48:26 by fakambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi_min_max(const char *nptr, t_push *push)
{
	int		i;

	i = 0;
	push->result = 0;
	push->sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
	{
		push->sign *= -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		push->result = push->result * 10 + (nptr[i] - 48);
		i++;
	}
	if (push->result * push->sign < INT_MIN || push->result * push->sign > INT_MAX)
	{
		free(push->res);
		ft_error("limits error", push);
	}
	return (push->result * push->sign);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	res = (char *)malloc(sizeof (char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	free(s1);
	return (res);
}

void	ft_error(char *str, t_push *push)
{
	ft_printf("%s\n", str);
	// if (push->res)
	// 	free(push->res);
	if (push->tab_number)
		free_arg(push->tab_number);
	if (push->tab_int)
		free(push->tab_int);
	exit(EXIT_FAILURE);
}

void	print_stack(t_stack	*stack)
{
	while (stack)
	{
		ft_printf("%d\n", stack->data);
		stack = stack->next;
	}
}

void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}
