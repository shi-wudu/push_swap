/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_execution2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student42.lisboa.pt>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:12:24 by marleand          #+#    #+#             */
/*   Updated: 2025/09/03 15:20:35 by marleand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_reverse_to_a(t_swap **stack_a, t_swap **stack_b, t_swap *node)
{
	if (node->move_direction == ROTATE_A_REVERSE_B)
	{
		while (node->target_index)
		{
			rotate_instruction(stack_a, stack_b, "ra");
			node->target_index--;
		}
		while (node->index)
		{
			reverse_rotate_instruction(stack_a, stack_b, "rrb");
		}
	}
}

void	rotate_reverse_to_b(t_swap **stack_a, t_swap **stack_b, t_swap *node)
{
	int	size_b;

	size_b = get_stack_size(*stack_b);
	if (node->move_direction == ROTATE_A_REVERSE_B)
	{
		while (node->index)
			rotate_instruction(stack_a, stack_b, "ra");
		while (node->target_index)
		{
			reverse_rotate_instruction(stack_a, stack_b, "rrb");
			node->target_index++;
			if (node->target_index == size_b)
				node->target_index = 0;
		}
	}
}

void	reverse_rotate_to_a(t_swap **stack_a, t_swap **stack_b, t_swap *node)
{
	int	size_a;

	size_a = get_stack_size(*stack_a);
	if (node->move_direction == REVERSE_A_ROTATE_B)
	{
		while (node->target_index)
		{
			reverse_rotate_instruction(stack_a, stack_b, "rra");
			node->target_index++;
			if (node->target_index == size_a)
				node->target_index = 0;
		}
		while (node->index)
		{
			rotate_instruction(stack_a, stack_b, "rb");
			node->index--;
		}
	}
}

void	reverse_rotate_to_b(t_swap **stack_a, t_swap **stack_b, t_swap *node)
{
	if (node->move_direction == REVERSE_A_ROTATE_B)
	{
		while (node->index)
			reverse_rotate_instruction(stack_a, stack_b, "rra");
		while (node->target_index)
		{
			rotate_instruction(stack_a, stack_b, "rb");
			node->target_index--;
		}
	}
}
