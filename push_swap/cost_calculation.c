/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student42.lisboa.pt>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:12:24 by marleand          #+#    #+#             */
/*   Updated: 2025/09/03 14:47:22 by marleand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	calculate_move_cost(t_swap *node, int size_a, int size_b)
{
	node->move_direction = ROTATE_BOTH;
	node->cost = ft_max(node->index, node->target_index);
	if (node->cost > (size_a - node->index) + node->target_index)
	{
		node->move_direction = REVERSE_A_ROTATE_B;
		node->cost = (size_a - node->index) + node->target_index;
	}
	if (node->cost > node->index + (size_b - node->target_index))
	{
		node->move_direction = ROTATE_A_REVERSE_B;
		node->cost = node->index + (size_b - node->target_index);
	}
	if (node->cost > ft_max(size_a - node->index, size_b - node->target_index))
	{
		node->move_direction = REVERSE_BOTH;
		node->cost = ft_max(size_a - node->index, size_b - node->target_index);
	}
}

void	calculate_move_cost_back_to_a(t_swap *node, int size_a, int size_b)
{
	node->move_direction = ROTATE_BOTH;
	node->cost = ft_max(node->target_index, node->index);
	if (node->cost > (size_a - node->target_index) + node->index)
	{
		node->move_direction = REVERSE_A_ROTATE_B;
		node->cost = (size_a - node->target_index) + node->index;
	}
	if (node->cost > node->target_index + (size_b - node->index))
	{
		node->move_direction = ROTATE_A_REVERSE_B;
		node->cost = node->target_index + (size_b - node->index);
	}
	if (node->cost > ft_max(size_a - node->target_index, size_b - node->index))
	{
		node->move_direction = REVERSE_BOTH;
		node->cost = ft_max(size_a - node->target_index, size_b - node->index);
	}
}
