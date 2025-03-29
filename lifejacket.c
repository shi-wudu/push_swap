/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifejacket.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-19 17:15:41 by marleand          #+#    #+#             */
/*   Updated: 2025-01-19 17:15:41 by marleand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	validate(char **av)
{
	int 	i;
	char 	*tmp;

	i = 1;
	while (av[i])
	{
		tmp = ft_itoa(ft_atoi(av[i]));
		if (ft_strncmp(tmp, av[i], ft_strlen(av[i])))
			return (free(tmp), 0);
		i++;
		free(tmp);
	}
	return(1);
}

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

void freestack(t_swap *sky)
{
	if (sky)
	{
		freestack(sky->next);
		free(sky);
	}
}