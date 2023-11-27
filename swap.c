/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atasyure <atasyure@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:16:09 by atasyure          #+#    #+#             */
/*   Updated: 2023/11/25 14:46:02 by atasyure         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack_node **node)
{
	(*node)->prev = (*node)->next;
	(*node)->next->prev = NULL;
	(*node)->next = (*node)->next->next;
	if ((*node)->next)
		(*node)->next->prev = *node;
	(*node)->prev->next = *node;
	*node = (*node)->prev;
}

void	sa(t_stack_node	**a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack_node **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
