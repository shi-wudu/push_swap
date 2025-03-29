/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-28 16:12:24 by marleand          #+#    #+#             */
/*   Updated: 2025-01-28 16:12:24 by marleand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
  
void	organize(t_swap **sky_a, t_swap **sky_b)
{
	(*sky_a)->minval = getminval(*sky_a);
	(*sky_a)->maxval = getmaxval(*sky_a);
	if ((*sky_a)->size > 3)
		push(sky_a, sky_b, "pb");
	while ((*sky_a)->size > 3 )
	{
		bestofriendo(sky_a, sky_b);
		move_all_ts(sky_a, sky_b);
		push(sky_a, sky_b, "pb");
	}
	sortthree(sky_a);
	while ((*sky_b))
	{
		bestofrienda(sky_b, sky_a);
		move_all_ts(sky_a, sky_b);
		push(sky_a, sky_b, "pa");
	}
}

t_swap	*move_to_maxval(t_swap **sky_b)
{
	t_swap *temp_b = *sky_b;
	printf("maxval = %d\n", temp_b->maxval);

	while (temp_b->value != temp_b->maxval)
	{
		temp_b = temp_b->next;
		(*sky_b)->index += 1;
	}
	return (temp_b);
}

t_swap	*move_to_minval(t_swap **sky_a)
{
	t_swap *temp_a = *sky_a;

	while (temp_a->value != temp_a->minval)
	{
		temp_a = temp_a->next;
		(*sky_a)->index += 1;
	}
	return (temp_a);
}

void	brother(t_swap **sky_a, t_swap **sky_b)
{
	(*sky_b)->one_d = R_R;
	(*sky_b)->cost = ((*sky_a)->index - (*sky_b)->index < 0) * ((*sky_b)->index - (*sky_a)->index) + ((*sky_a)->index - (*sky_b)->index >= 0) * ((*sky_a) - (*sky_b));
	if ((*sky_b)->cost > ((*sky_a)->size - (*sky_a)->index + (*sky_b)->index))
	{
		(*sky_b)->one_d = RV_R;
		(*sky_b)->cost = ((*sky_a)->size - (*sky_a)->index + (*sky_b)->index);
	}
	if ((*sky_b)->cost > (*sky_a)->index + (*sky_b)->size - (*sky_b)->index)
	{
		(*sky_b)->one_d = R_RV;
		(*sky_b)->cost = (*sky_a)->index + (*sky_b)->size - (*sky_b)->index;
	}
	if ((*sky_b)->cost > 
		(((*sky_a)->size - (*sky_a)->index - (*sky_b)->size - (*sky_b)->index) < 0) * 
		((*sky_b)->size - (*sky_b)->index - (*sky_a)->size - (*sky_a)->index) +
		(((*sky_a)->size - (*sky_a)->index - (*sky_b)->size - (*sky_b)->index) >= 0) * 
		((*sky_a)->size - (*sky_a)->index - (*sky_b)->size - (*sky_b)->index))
	{
		(*sky_b)->one_d = RV_RV;
		(*sky_b)->cost = (((*sky_a)->size - (*sky_a)->index - (*sky_b)->size - (*sky_b)->index) < 0) * 
		((*sky_b)->size - (*sky_b)->index - (*sky_a)->size - (*sky_a)->index) +
		(((*sky_a)->size - (*sky_a)->index - (*sky_b)->size - (*sky_b)->index) >= 0) * 
		((*sky_a)->size - (*sky_a)->index - (*sky_b)->size - (*sky_b)->index);
	}
}
