/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student42.lisboa.pt>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:12:24 by marleand          #+#    #+#             */
/*   Updated: 2025/09/03 14:47:22 by marleand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_swap *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		printf("stack[%d] = %d\n", i, stack->value);
		i++;
		stack = stack->next;
	}
}
