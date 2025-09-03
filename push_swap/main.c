/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-19 17:34:35 by marleand          #+#    #+#             */
/*   Updated: 2025-01-19 17:34:35 by marleand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_sorted(t_swap *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_swap	*create_stack_from_args(char **av)
{
	t_swap	*stack_a;
	t_swap	*temp;
	int		size;

	size = 0;
	stack_a = NULL;
	av++;
	while (*av)
	{
		temp = create_new_node(ft_atoi(*av));
		if (!temp)
			return (NULL);
		add_node_to_tail(&stack_a, temp);
		av++;
		size++;
	}
	return (stack_a);
}

int	main(int ac, char **av)
{
	t_swap	*stack_a;
	t_swap	*stack_b;

	if (ac == 1 || !(validate_arguments(av)))
		return (0);
	stack_a = create_stack_from_args(av);
	stack_b = NULL;
	if (!is_stack_sorted(stack_a))
	{
		if (get_stack_size(stack_a) == 2)
			swap_instruction(&stack_a, &stack_b, "sa");
		else
			main_sort_algorithm(&stack_a, &stack_b);
	}
	if (get_min_value_index(stack_a) > get_stack_size(stack_a) / 2)
		while (get_min_value_index(stack_a) != 0)
			reverse_rotate_instruction(&stack_a, &stack_b, "rra");
	else
		while (get_min_value_index(stack_a) != 0)
			rotate_instruction(&stack_a, &stack_b, "ra");
	free_stack(stack_a);
	return (0);
}

/* teste swap

	while(temp)
	{
		printf("Value -- %d\n", temp->value);
		temp = temp->next;
	}
	swap(&skyscraper);
	printf("---------------------------\n");
	temp = skyscraper;
	while(temp)
	{
		printf("Value -- %d\n", temp->value);
		if(temp->prev != NULL)
			printf("Prev ----- (%d)\n", temp->prev->value);
		temp = temp->next;
	} */

/* teste push

	temp = skyscraper;
	temp3 = sky_b;
	while(temp)
	{
		printf("Value -- %d\n", temp->value);
		temp = temp->next;
	}
	while(temp3)
	{
		printf("Value -- %d\n", temp3->value);
		temp3 = temp3->next;
	}
	push(&skyscraper, &sky_b);
	push(&skyscraper, &sky_b);
	push(&skyscraper, &sky_b);
	printf("---------------------------\n");
	temp = skyscraper;
	temp3 = sky_b;
	while(temp)
	{
		printf("Value -- %d\n", temp->value);
		if(temp->prev != NULL)
			printf("Prev ----- (%d)\n", temp->prev->value);
		temp = temp->next;
	}
	while(temp3)
	{
		printf("Value do B -- %d\n", temp3->value);
		if(temp3->prev != NULL)
			printf("Prev ----- (%d)\n", temp3->prev->value);
		temp3 = temp3->next;
	}
	if(!temp)
		printf("gg\n"); */

/* teste rotate
	while(temp)
	{
		printf("Value -- %d\n", temp->value);
		temp = temp->next;
	}
	rotate(&skyscraper);
	printf("---------------------------\n");
	temp = skyscraper;
	while(temp)
	{
		printf("Rotate -- %d\n", temp->value);
		if(temp->prev != NULL)
			printf("Prev ----- (%d)\n", temp->prev->value);
		temp = temp->next;
	}
} */