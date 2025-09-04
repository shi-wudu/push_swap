/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student42.lisboa.pt>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:15:41 by marleand          #+#    #+#             */
/*   Updated: 2025/09/04 17:17:23 by marleand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_arguments(char **av)
{
	int		i;
	char	*tmp;

	i = 1;
	while (av[i])
	{
		if ((av[i][0] == '\'' && av[i][1] == '\0') || av[i][0] == '\0')
			return (0);
		if ((av[i][0] == '\'' && av[i][1] != '\0') || av[i][0] == '\0')
			return (0);
		tmp = ft_itoa(ft_atoi(av[i]));
		if (ft_strncmp(tmp, av[i], ft_strlen(av[i])))
			return (free(tmp), 0);
		i++;
		free(tmp);
	}
	return (1);
}

static t_swap	*get_last_node(t_swap *lst)
{
	t_swap	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	add_node_to_tail(t_swap **lst, t_swap *new)
{
	t_swap	*last;

	if (lst)
	{
		if (*lst)
		{
			last = get_last_node(*lst);
			last->next = new;
			new->prev = last;
			new->index = last->index + 1;
		}
		else
			*lst = new;
	}
}

t_swap	*create_new_node(int value)
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

void	free_stack(t_swap *stack)
{
	if (stack)
	{
		free_stack(stack->next);
		free(stack);
	}
}
