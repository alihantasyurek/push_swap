/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atasyure <atasyure@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:15:13 by atasyure          #+#    #+#             */
/*   Updated: 2023/11/25 14:40:06 by atasyure         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack_node *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

t_stack_node	*find_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	is_sorted(t_stack_node *stack)
{
	while (stack->next)
	{
		if (stack->x > stack->next->x)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_stack_node	*find_min(t_stack_node *stack)
{
	t_stack_node	*search;

	search = stack;
	while (stack->next)
	{
		if (search->x > stack->next->x)
			search = stack->next;
		stack = stack->next;
	}
	return (search);
}

t_stack_node	*find_max(t_stack_node *stack)
{
	t_stack_node	*search;

	search = stack;
	while (stack->next)
	{
		if (search->x < stack->next->x)
			search = stack->next;
		stack = stack->next;
	}
	return (search);
}
