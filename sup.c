/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sup.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-19 20:02:18 by marleand          #+#    #+#             */
/*   Updated: 2025-01-19 20:02:18 by marleand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sortcheck(t_swap *skyscraper)
{
	while (skyscraper && skyscraper->next)
	{
		if (skyscraper->value > skyscraper->next->value)
			return (0);
		skyscraper = skyscraper->next;
	}
	return (1);
}

void	sortthree(t_swap **skyscraper)
{
	if((*skyscraper)->value > (*skyscraper)->next->value && \
	(*skyscraper)->value > (*skyscraper)->next->next->value)
		rotate(skyscraper, NULL, "ra");
	else if (((*skyscraper)->next->value > (*skyscraper)->next->next->value) && \
	(*skyscraper)->next->value > (*skyscraper)->value)
		reverse(skyscraper, NULL, "rra");
	if(!sortcheck(*skyscraper))
		swap(skyscraper, NULL, "sa");
}

int		getsizeof(t_swap *skyscraper)
{
	t_swap	*tmp;
	int		size;

	size = 0;
	if (!skyscraper)
		return (0);
	tmp = skyscraper;
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}

int		getminval(t_swap *skyscraper)
{
	int		minval;

	minval = -2147483648;
	while(skyscraper)
	{
		if (skyscraper->value < minval)
			minval = skyscraper->value;
		skyscraper = skyscraper->next;
	}
	return (minval);
}
