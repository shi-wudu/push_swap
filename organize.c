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
	(*sky_b)->minval = getminval(*sky_b);
	(*sky_a)->maxval = getmaxval(*sky_a);
	(*sky_b)->maxval = getmaxval(*sky_b);
	while ((*sky_a)->size > 3 )
	{
		bestofriendo(sky_a, sky_b);
		move_all_ts(sky_a, sky_b);
		push(sky_a, sky_b, "pb");
	}
	while ((*sky_b))
	{
		bestofrienda(sky_b, sky_a);
		move_all_ts(sky_a, sky_b);
		push(sky_a, sky_b, "pa");
	}
}

static t_list	*move_to_maxval(t_swap **sky_b)
{
	t_swap *temp_b = *sky_b;

	while (temp_b->value != temp_b->maxval)
	{
		temp_b = temp_b->next;
		(*sky_b)->index += 1;
	}
	return (temp_b);
}

static t_list	*move_to_minval(t_swap **sky_a)
{
	t_swap *temp_a = *sky_a;

	while (temp_a->value != temp_a->minval)
	{
		temp_a = temp_a->next;
		(*sky_a)->index += 1;
	}
	return (temp_a);
}


int	getcost(int val, t_swap *sky_a, t_swap *sky_b)
{
	int	index;
	t_swap *tmp;

	tmp = sky_a;
	index = 0;
	while (sky_a && (val != sky_a->maxval)) // index do max val
	{
		sky_a = sky_a->next;
		index++;
	}
	while (sky_a->value > val) // tentar encontrar o menor mais proximo antes de acabar a stack a partir do max
	{
		sky_a = sky_a->next;
		index++;
	}
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
