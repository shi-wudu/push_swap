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