/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student42.lisboa.pt>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:02:18 by marleand          #+#    #+#             */
/*   Updated: 2025/09/03 15:24:36 by marleand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_elements(t_swap **stack)
{
	if ((*stack)->value > (*stack)->next->value && \
(*stack)->value > (*stack)->next->next->value)
		rotate_instruction(stack, NULL, "ra");
	else if (((*stack)->next->value > (*stack)->next->next->value) && \
(*stack)->next->value > (*stack)->value)
		reverse_rotate_instruction(stack, NULL, "rra");
	if (!is_stack_sorted(*stack))
		swap_instruction(stack, NULL, "sa");
}

void	main_sort_algorithm(t_swap **stack_a, t_swap **stack_b)
{
	t_swap	*node_to_push;

	if (get_stack_size(*stack_a) > 3)
		push_instruction(stack_a, stack_b, "pb");
	if (get_stack_size(*stack_a) > 3)
		push_instruction(stack_a, stack_b, "pb");
	while (get_stack_size(*stack_a) > 3)
	{
		node_to_push = find_cheapest_node_to_b(*stack_a, *stack_b);
		execute_moves_to_b(stack_a, stack_b, node_to_push);
		push_instruction(stack_a, stack_b, "pb");
	}
	sort_three_elements(stack_a);
	while (*stack_b)
	{
		node_to_push = find_cheapest_node_to_a(*stack_a, *stack_b);
		execute_moves_to_a(stack_a, stack_b, node_to_push);
		push_instruction(stack_a, stack_b, "pa");
	}
}
