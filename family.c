/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   family.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-29 16:38:53 by marleand          #+#    #+#             */
/*   Updated: 2025-03-29 16:38:53 by marleand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bestofriendo(t_swap **sky_a, t_swap **sky_b)
{
	t_swap *temp_a;
	t_swap *temp_b;

	temp_a = *sky_a;
	while (temp_a)
	{
		targetb(sky_a, sky_b, temp_a, temp_b);
		brother(sky_a, sky_b);
	}
}

void	bestofrienda(t_swap **sky_a, t_swap **sky_b)
{
	t_swap *temp_a;
	t_swap *temp_b;

	temp_b = *sky_b;
	while (temp_b)
	{
		targetb(sky_a, sky_b, temp_a, temp_b);
		brother(sky_a, sky_b);
	}
}
void	targeta(t_swap **sky_a, t_swap **sky_b, t_swap *temp_a, t_swap *temp_b)
{
	while (temp_b)
	{
		temp_a = move_to_minval(sky_a);

		if(temp_b->value > (*sky_a)->maxval)
			return;
		while (temp_a && temp_b->value > temp_a->value)
		{
			if (temp_b->value < temp_a->value)
				return;
			temp_a = temp_a->next;
			(*sky_a)->index += 1;
		}
		temp_a = *sky_a;
		(*sky_a)->index = 0;
		while(temp_a->value != temp_a->minval && temp_b->value > temp_a->value)
		{
			temp_a = temp_a->next;
			(*sky_a)->index += 1;
		}
		(*sky_b)->index += 1;
		temp_b = temp_b->next;
	}
}
void	targetb(t_swap **sky_a, t_swap **sky_b, t_swap *temp_a, t_swap *temp_b)
{
	while (temp_a)
	{
		temp_b = move_to_maxval(sky_b);

		if(temp_a->value < (*sky_b)->minval)
			return;
		while (temp_b && temp_a->value < temp_b->value)
		{
			if (temp_a->value > temp_b->value)
				return;
			temp_b = temp_b->next;
			(*sky_b)->index += 1;
		}
		temp_b = *sky_b;
		(*sky_b)->index = 0;
		while(temp_b->value != temp_b->maxval && temp_a->value < temp_b->value)
		{
			temp_b = temp_b->next;
			(*sky_b)->index += 1;
		}
		(*sky_a)->index += 1;
		temp_a = temp_a->next;
	}
}