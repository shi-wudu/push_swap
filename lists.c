/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-19 20:02:32 by marleand          #+#    #+#             */
/*   Updated: 2025-01-19 20:02:32 by marleand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

static t_swap	*lstlast(t_swap *lst)
{
	t_swap	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	lstaddtail(t_swap **lst, t_swap *new)
{
	t_swap	*last;

	if (lst)
	{
		if (*lst)
		{
			last = lstlast(*lst);
			last->next = new;
			new->prev = last;
		}
		else
			*lst = new;
	}
}
void	lstaddhead(t_swap **lst, t_swap *new)
{
	new->next = *lst;
	(*lst)->prev = new;
	*lst = new;
}

t_swap	*lstnew(int value)
{
	t_swap	*node;

	node = malloc(sizeof(t_swap));
	if (!node)
		return (0);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	node->index = 0;
	return (node);
}