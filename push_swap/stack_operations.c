/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student42.lisboa.pt>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:52:36 by marleand          #+#    #+#             */
/*   Updated: 2025/09/03 15:26:50 by marleand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	update_indices(t_swap **stack)
{
	t_swap	*tmp;
	int		i;

	tmp = *stack;
	i = -1;
	while (tmp)
	{
		tmp->index = ++i;
		tmp = tmp->next;
	}
}

void	execute_swap(t_swap **stack)
{
	int	tmp;

	tmp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp;
}

void	execute_push(t_swap **source_stack, t_swap **dest_stack)
{
	t_swap	*temp;

	if (!(source_stack && *source_stack))
		return ;
	temp = *source_stack;
	*source_stack = (*source_stack)->next;
	if (!(dest_stack && *dest_stack))
	{
		*dest_stack = temp;
		(*dest_stack)->next = NULL;
	}
	else
	{
		(*dest_stack)->prev = temp;
		temp->next = *dest_stack;
		*dest_stack = temp;
	}
	if (*source_stack)
		(*source_stack)->prev = NULL;
	update_indices(source_stack);
	update_indices(dest_stack);
}

void	execute_rotate(t_swap **stack)
{
	t_swap	*temp;
	t_swap	*start;

	if (!(stack && *stack && (*stack)->next))
		return ;
	temp = *stack;
	start = *stack;
	start = start->next;
	while (temp->next)
		temp = temp->next;
	temp->next = *stack;
	(*stack)->prev = temp;
	(*stack)->next = NULL;
	start->prev = NULL;
	*stack = start;
	update_indices(stack);
}

void	execute_reverse_rotate(t_swap **stack)
{
	t_swap	*temp;
	t_swap	*end;

	if (!(stack && *stack && (*stack)->next))
		return ;
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	end = temp;
	end = end->prev;
	temp->next = *stack;
	temp->prev = NULL;
	(*stack)->prev = temp;
	end->next = NULL;
	*stack = (*stack)->prev;
	update_indices(stack);
}
