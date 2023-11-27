/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atasyure <atasyure@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:20:16 by atasyure          #+#    #+#             */
/*   Updated: 2023/11/25 14:20:38 by atasyure         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				is_malloced;

	is_malloced = 0;
	a = NULL;
	b = NULL;
	if (argc < 2)
		return (-1);
	else if (argc == 2)
		manage_split(&a, argv, &is_malloced);
	else
		init_stack_a(&a, argv +1, is_malloced);
	if (!is_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	deallocate(&a);
}
