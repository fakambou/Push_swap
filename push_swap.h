/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakambou <fakambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:02:01 by fakambou          #+#    #+#             */
/*   Updated: 2025/02/28 17:30:58 by fakambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/header/libft.h"
# include "libft/header/ft_printf.h"
# include <limits.h>

typedef struct s_push
{
	char	**tab_number;
	int	*tab_int;
	int	length;
}	t_push;

typedef struct s_stack
{
	int	data;
	struct s_stack *next;
}	t_stack;


void	check_number(t_push *push);
void	split_arg(t_push *push, char **av);
char	*ft_strjoin1(char *s1, char *s2);
void	ft_error(char *str);
long	ft_atoi_min_max(const char *nptr);
void	check_double(t_push *push);
void	free_arg(char **arg);
void	init_node(t_push *push, t_stack *stack);

#endif