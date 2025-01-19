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

	skyscraper = NULL;
	*av++;
	while(*av)
	{
		temp = lstnew(ft_atoi(*av)); //criar novo node cujo valor é o int da str
		if (!temp)
			return(NULL);
		lstaddtail(&skyscraper, temp);
		*av++;
	}
	return(skyscraper);
}
#include "stdio.h"
int	main(int ac, char **av)
{
	t_swap	*skyscraper;

	if (ac == 1 || !(validate(av)))
		return(0);
	skyscraper = cstack(av);
	if (!skyscraper)
		return(1);
	while(skyscraper)
	{
		printf("Value -- %d\n", skyscraper->value);
		skyscraper = skyscraper->next;
	}
}