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
		{
			printf("meow\n");
			return(0);
		}
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
	t_list	*tmp;
	int		size;

	size = 0;
	if (!skyscraper)
		return (NULL);
	tmp = skyscraper;
	while (tmp->next)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}
//-----

//update value add to
//     