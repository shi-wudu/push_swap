/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_analysis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student42.lisboa.pt>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:02:18 by marleand          #+#    #+#             */
/*   Updated: 2025/09/03 15:25:35 by marleand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_size(t_swap *stack)
{
	t_swap	*tmp;
	int		size;

	size = 0;
	if (!stack)
		return (0);
	tmp = stack;
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}

int	get_min_value(t_swap *stack)
{
	int		minval;

	minval = INT_MAX;
	while (stack)
	{
		if (stack->value < minval)
			minval = stack->value;
		stack = stack->next;
	}
	return (minval);
}

int	get_max_value(t_swap *stack)
{
	int		maxval;

	maxval = INT_MIN;
	while (stack)
	{
		if (stack->value > maxval)
			maxval = stack->value;
		stack = stack->next;
	}
	return (maxval);
}

int	get_min_value_index(t_swap *stack)
{
	int		minval;
	int		index;

	minval = INT_MAX;
	index = 0;
	while (stack)
	{
		if (stack->value < minval)
		{
			minval = stack->value;
			index = stack->index;
		}
		stack = stack->next;
	}
	return (index);
}

int	get_max_value_index(t_swap *stack)
{
	int		maxval;
	int		index;

	maxval = INT_MIN;
	index = 0;
	while (stack)
	{
		if (stack->value > maxval)
		{
			maxval = stack->value;
			index = stack->index;
		}
		stack = stack->next;
	}
	return (index);
}
