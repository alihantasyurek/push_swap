/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atasyure <atasyure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:16:05 by atasyure          #+#    #+#             */
/*   Updated: 2023/11/25 18:49:43 by atasyure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_end(t_stack_node **tail, int value)
{
	t_stack_node	*new_node;

	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		deallocate(tail);
	new_node->x = value;
	new_node->next = NULL;
	new_node->prev = *tail;
	(*tail)->next = new_node;
	*tail = new_node;
}

void	first_init(t_stack_node **a, t_stack_node **tail, int value)
{
	t_stack_node	*new_node;

	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		exit (-1);
	new_node->x = value;
	new_node->prev = NULL;
	new_node->next = NULL;
	*a = new_node;
	*tail = new_node;
}

void	init_stack_a(t_stack_node **a, char **argv, int is_malloced)
{
	t_stack_node	*tail;
	long			value;
	int				i;

	tail = NULL;
	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(a, is_malloced, argv);
		value = ft_atol(argv[i]);
		if (value > INT_MAX || value < INT_MIN)
			free_errors(a, is_malloced, argv);
		if (error_duplicate(*a, (int)value))
			free_errors(a, is_malloced, argv);
		if (!(tail))
			first_init(a, &tail, (int)value);
		else
			insert_end(&tail, (int)value);
		i++;
	}
	tail = NULL;
}

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(t_stack_node **stack,
						t_stack_node *top_node,
						char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}
