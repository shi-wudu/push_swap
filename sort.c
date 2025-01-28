/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-27 10:20:48 by marleand          #+#    #+#             */
/*   Updated: 2025-01-27 10:20:48 by marleand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_swap **skyscraper, t_swap **sky_b, char *str)
{
	if(!ft_strncmp("pa", str, 3))
	{
		rpush(skyscraper, sky_b);
	if ((*skyscraper)->maxval < (*skyscraper)->value)
		(*skyscraper)->maxval = (*skyscraper)->value;
	if ((*skyscraper)->minval > (*skyscraper)->value)
		(*skyscraper)->minval = (*skyscraper)->value;
		write (1, "pa\n", 3);
	}
	if(!ft_strncmp("pb", str, 3))
	{
		rpush(sky_b, skyscraper);
	if ((*sky_b)->maxval < (*sky_b)->value)
		(*sky_b)->maxval = (*sky_b)->value;
	if ((*sky_b)->minval > (*sky_b)->value)
		(*sky_b)->minval = (*sky_b)->value;
		write (1, "pb\n", 3);
	}
}
void	swap(t_swap **skyscraper, t_swap **sky_b, char *str)
{
	if(!ft_strncmp("sa", str, 3))
	{
		rswap(skyscraper);
		write (1, "sa\n", 3);
	}
	if(!ft_strncmp("sb", str, 3))
	{
		rswap(sky_b);
		write (1, "sb\n", 3);
	}
	if(!ft_strncmp("ss", str, 3))
	{
		rswap(skyscraper);
		rswap(sky_b);
		write (1, "ss\n", 3);
	}
}
void	rotate(t_swap **skyscraper, t_swap **sky_b, char *str)
{
	if(!ft_strncmp("ra", str, 3))
	{
		rrotate(skyscraper);
		write (1, "ra\n", 3);
	}
	if(!ft_strncmp("rb", str, 3))
	{
		rrotate(skyscraper);
		write (1, "rb\n", 3);
	}
	if(!ft_strncmp("rr", str, 3))
	{
		rrotate(skyscraper);
		rrotate(sky_b);
		write (1, "rr\n", 3);
	}
}
void	reverse(t_swap **skyscraper, t_swap **sky_b, char *str)
{
	if(!ft_strncmp("rra", str, 3))
	{
		rreverse(skyscraper);
		write (1, "rra\n", 4);
	}
	if(!ft_strncmp("rrb", str, 3))
	{
		rreverse(sky_b);
		write (1, "rrb\n", 4);
	}
	if(!ft_strncmp("rrr", str, 3))
	{
		rreverse(skyscraper);
		rreverse(sky_b);
		write (1, "rrr\n", 4);
	}
}