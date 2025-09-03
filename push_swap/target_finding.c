/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_finding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student42.lisboa.pt>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:38:53 by marleand          #+#    #+#             */
/*   Updated: 2025/09/03 15:27:44 by marleand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_target_position_in_a(t_swap *node_b, t_swap *stack_a)
{
	int		target;
	int		index;

	target = INT_MAX;
	index = 0;
	if (node_b->value > get_max_value(stack_a) || \
node_b->value < get_min_value(stack_a))
	{
		node_b->target_index = get_min_value_index(stack_a);
		return ;
	}
	while (stack_a)
	{
		if (stack_a->value > node_b->value && stack_a->value < target)
		{
			target = stack_a->value;
			index = stack_a->index;
		}
		stack_a = stack_a->next;
	}
	node_b->target_index = index;
}

void	find_target_position_in_b(t_swap *node_a, t_swap *stack_b)
{
	int		target;
	int		index;

	target = INT_MIN;
	index = 0;
	if (node_a->value > get_max_value(stack_b) || \
node_a->value < get_min_value(stack_b))
	{
		node_a->target_index = get_max_value_index(stack_b);
		return ;
	}
	while (stack_b)
	{
		if (stack_b->value < node_a->value && stack_b->value > target)
		{
			target = stack_b->value;
			index = stack_b->index;
		}
		stack_b = stack_b->next;
	}
	node_a->target_index = index;
}

t_swap	*find_cheapest_node_to_a(t_swap *stack_a, t_swap *stack_b)
{
	t_swap	*node_to_push;
	t_swap	*tmp;

	tmp = stack_b;
	node_to_push = stack_b;
	while (stack_b)
	{
		find_target_position_in_a(stack_b, stack_a);
		calculate_move_cost_back_to_a(stack_b, get_stack_size(stack_a), \
get_stack_size(tmp));
		if (node_to_push->cost > stack_b->cost)
			node_to_push = stack_b;
		stack_b = stack_b->next;
	}
	return (node_to_push);
}

t_swap	*find_cheapest_node_to_b(t_swap *stack_a, t_swap *stack_b)
{
	t_swap	*node_to_push;
	t_swap	*tmp;

	tmp = stack_a;
	node_to_push = stack_a;
	while (stack_a)
	{
		find_target_position_in_b(stack_a, stack_b);
		calculate_move_cost(stack_a, get_stack_size(tmp), \
get_stack_size(stack_b));
		if (node_to_push->cost > stack_a->cost)
			node_to_push = stack_a;
		stack_a = stack_a->next;
	}
	return (node_to_push);
}
