/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-29 17:37:41 by marleand          #+#    #+#             */
/*   Updated: 2025-03-29 17:37:41 by marleand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void move_all_ts2(t_swap **sky_a, t_swap **sky_b)
{
	if ((*sky_b)->one_d == RV_RV) {
		while ((*sky_a)->size - (*sky_a)->index && (*sky_b)->size - (*sky_b)->index)
		{
			rotate(sky_a, sky_a, "rr");
			(*sky_a)->index++;
			(*sky_b)->index++;
		}
		while ((*sky_a)->size - (*sky_a)->index)
		{
			rotate(sky_a, sky_a, "ra");
			(*sky_a)->index++;
		}
		while ((*sky_b)->size - (*sky_b)->index)
		{
			rotate(sky_a, sky_a, "rb");
			(*sky_b)->index++;
		}
	}
}

static void move_all_ts3(t_swap **sky_a, t_swap **sky_b)
{
	if ((*sky_b)->one_d == R_RV)
	{
		while ((*sky_a)->index)
		{
			rotate(sky_a, sky_a, "ra");
			(*sky_a)->index--;
		}
		while ((*sky_b)->size - (*sky_b)->index)
		{
			rotate(sky_a, sky_a, "rb");
			(*sky_b)->index++;
		}
	}
}

static void move_all_ts4(t_swap **sky_a, t_swap **sky_b)
{
	if ((*sky_b)->one_d == R_RV)
	{
		while ((*sky_b)->index)
		{
			rotate(sky_a, sky_a, "rb");
			(*sky_b)->index--;
		}
		while ((*sky_a)->size - (*sky_a)->index)
		{
			rotate(sky_a, sky_a, "ra");
			(*sky_a)->index++;
		}
	}
}
int		getmaxval(t_swap *skyscraper)
{
	int		maxval;

	maxval = 2147483647;
	while(skyscraper)
	{
		if (skyscraper->value > maxval)
			maxval = skyscraper->value;
		skyscraper = skyscraper->next;
	}
	return (maxval);
}

void move_all_ts(t_swap **sky_a, t_swap **sky_b)
{
	if ((*sky_b)->one_d == R_R)
	{
		while ((*sky_a)->index && (*sky_b)->index)
		{
			rotate(sky_a, sky_a, "rr");
			(*sky_a)->index--;
			(*sky_b)->index--;
		}
		while ((*sky_a)->index)
		{
			rotate(sky_a, sky_a, "ra");
			(*sky_a)->index--;
		}
		while ((*sky_b)->index)
		{
			rotate(sky_a, sky_a, "rb");
			(*sky_b)->index--;
		}
	}
	move_all_ts2(sky_a, sky_b);
	move_all_ts3(sky_a, sky_b);
	move_all_ts4(sky_a, sky_b);
}