/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-22 15:52:36 by marleand          #+#    #+#             */
/*   Updated: 2025-01-22 15:52:36 by marleand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rswap(t_swap **skyscraper)
{
	t_swap	*temp;
	t_swap	*swop;

	if (!(skyscraper && *skyscraper && (*skyscraper)->next))
		return ;
	printf("Value of skyscraper ---> (%d)\n", (*skyscraper)->value);
	temp = *skyscraper; // A
	temp = temp->next; // ..B
	(*skyscraper)->prev = temp;//prev a (null) = next a == (&b)
	(*skyscraper)->next = temp->next;// next a (&b) = next b = (&c) | prev(&b)<-[a]->next(&c)
	temp->next = temp->prev;//next b (&c) = prev b = (&a)
	temp->prev = NULL;//prev b (&a) = null (start of list) | prev(null)<-[b]->next(&a)
	swop = *skyscraper;
	swop = swop->next;
	swop->prev = temp->next;
	*skyscraper = (*skyscraper)->prev;//swap cuz im goofy and lazy
}

void	rpush(t_swap **a_sky, t_swap **b_sky)
{
	t_swap *temp;

	if (!(a_sky && *a_sky))
		return ;
	temp = *a_sky;
	*a_sky = (*a_sky)->next;
	if (!(b_sky && *b_sky))
	{
		*b_sky = temp;
		(*b_sky)->next = NULL;
		(*b_sky)->size = 1;
		(*a_sky)->size--;
	}
	else
	{
		(*b_sky)->prev = temp;
		temp->next = *b_sky;
		*b_sky = temp;
		(*b_sky)->size++;
		(*a_sky)->size--;
	}
	if (!(*a_sky))
		a_sky = NULL;
	else
		(*a_sky)->prev = NULL;
}

void	rrotate(t_swap **skyscraper)
{
	t_swap *temp;
	t_swap *start;

	if (!(skyscraper && *skyscraper && (*skyscraper)->next))
		return ;
	temp = *skyscraper;
	start = *skyscraper;
	start = start->next;
	while(temp->next)
		temp = temp->next;

	temp->next = *skyscraper;
	(*skyscraper)->prev = temp;
	(*skyscraper)->next = NULL;
	start->prev = NULL;
	*skyscraper = start;
}

void	rreverse(t_swap **skyscraper)
{
	t_swap *temp;
	t_swap *end;

	if (!(skyscraper && *skyscraper && (*skyscraper)->next))
		return ;
	temp = *skyscraper;
	while(temp->next)
		temp = temp->next;

	end = temp;
	end = end->prev;
	temp->next = *skyscraper;
	temp->prev = NULL;
	(*skyscraper)->prev = temp;
	end->next = NULL;
	*skyscraper = (*skyscraper)->prev;
}
