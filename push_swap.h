/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atasyure <atasyure@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:13:46 by atasyure          #+#    #+#             */
/*   Updated: 2023/11/25 14:45:14 by atasyure         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MAX 2147483647
# define INT_MAX_PLUS 2147483648
# define INT_MIN -2147483648
# define INT_MIN_MINUS -2147483649
# include "libft/libft.h"

typedef struct s_stack_node
{
	int					x;
	int					index;
	int					push_cost;
	int					above_median;
	int					cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

long			ft_atol(const char *str);
int				error_syntax(char *str_n);
int				error_duplicate(t_stack_node *a, int n);
int				stack_len(t_stack_node *stack);
int				is_sorted(t_stack_node *stack);

t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *stack);

void			manage_split(t_stack_node **a, char **argv, int *is_malloced);
void			sort_three(t_stack_node **a);
void			sort_stacks(t_stack_node **a, t_stack_node **b);
void			init_stack_a(t_stack_node **a, char **argv, int is_malloced);
void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);
void			current_index(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack);
void			prep_for_push(t_stack_node **s, t_stack_node *n, char c);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **b, t_stack_node **a);
void			deallocate(t_stack_node **stack);
void			free_errors(t_stack_node **a, int is_malloced, char **argv);
void			free_argv(char **argv);
void			move_b_to_a(t_stack_node **a, t_stack_node **b);
void			min_on_top(t_stack_node **a);

#endif