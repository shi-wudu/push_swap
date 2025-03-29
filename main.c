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

t_swap	*cstack(char **av)
{
	t_swap *skyscraper;
	t_swap *temp;
	int		size;
	
	size = 0;
	skyscraper = NULL;
	*av++;
	skyscraper->maxval = ft_atoi(av[1]);
	skyscraper->minval = ft_atoi(av[1]);
	while(*av)
	{
		temp = lstnew(ft_atoi(*av)); //criar novo node cujo valor é o int da str
		if (!temp)
			return(NULL);
		lstaddtail(&skyscraper, temp);
		if (skyscraper->maxval < skyscraper->value)
			skyscraper->maxval = skyscraper->value;
		if (skyscraper->minval > skyscraper->value)
			skyscraper->minval = skyscraper->value;
		*av++;
		size++;
	}
	if (skyscraper)
		skyscraper->size = size;
	return(skyscraper);
}
#include "stdio.h"
int	main(int ac, char **av)
{
	t_swap *sky_a;
	t_swap *sky_b;

	if (ac == 1 || !(validate(av)))
		return(0);
	sky_a = cstack(av);
	sky_b = 0;
	if (!sortcheck(sky_a))
	{
		if (getsizeof(sky_a) == 2)
		{
			swap(&sky_a, &sky_b, "sa");
			return (0);
		}
		else
			organize(&sky_a, &sky_b);
	}
	freestack(sky_a);
	return (0);
}

//cc main.c lists.c sort.c lifejacket.c ./Libft/ft_strlen.c ./Libft/ft_itoa.c ./Libft/ft_atoi.c ./Libft/ft_strncmp.c ./Libft/ft_strdup.c ./Libft/ft_memcpy.c && ./a.out 1 2 3 4 5


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