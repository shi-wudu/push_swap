/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_printers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student42.lisboa.pt>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:20:48 by marleand          #+#    #+#             */
/*   Updated: 2025/09/03 15:16:56 by marleand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_instruction(t_swap **stack_a, t_swap **stack_b, char *str)
{
	if (!ft_strncmp("sa", str, 2))
	{
		execute_swap(stack_a);
		write (1, "sa\n", 3);
	}
	if (!ft_strncmp("sb", str, 3))
	{
		execute_swap(stack_b);
		write (1, "sb\n", 3);
	}
	if (!ft_strncmp("ss", str, 3))
	{
		execute_swap(stack_a);
		execute_swap(stack_b);
		write (1, "ss\n", 3);
	}
}

void	push_instruction(t_swap **stack_a, t_swap **stack_b, char *str)
{
	if (!ft_strncmp("pb", str, 3))
	{
		execute_push(stack_a, stack_b);
		write (1, "pb\n", 3);
	}
	if (!ft_strncmp("pa", str, 3))
	{
		execute_push(stack_b, stack_a);
		write (1, "pa\n", 3);
	}
}

void	rotate_instruction(t_swap **stack_a, t_swap **stack_b, char *str)
{
	if (!ft_strncmp("ra", str, 3))
	{
		execute_rotate(stack_a);
		write (1, "ra\n", 3);
	}
	if (!ft_strncmp("rb", str, 3))
	{
		execute_rotate(stack_b);
		write (1, "rb\n", 3);
	}
	if (!ft_strncmp("rr", str, 3))
	{
		execute_rotate(stack_a);
		execute_rotate(stack_b);
		write (1, "rr\n", 3);
	}
}

void	reverse_rotate_instruction(t_swap **stack_a, t_swap **s_b, char *str)
{
	if (!ft_strncmp("rra", str, 3))
	{
		execute_reverse_rotate(stack_a);
		write (1, "rra\n", 4);
	}
	if (!ft_strncmp("rrb", str, 3))
	{
		execute_reverse_rotate(s_b);
		write (1, "rrb\n", 4);
	}
	if (!ft_strncmp("rrr", str, 3))
	{
		execute_reverse_rotate(stack_a);
		execute_reverse_rotate(s_b);
		write (1, "rrr\n", 4);
	}
}
