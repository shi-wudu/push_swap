/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-19 16:44:22 by marleand          #+#    #+#             */
/*   Updated: 2025-01-19 16:44:22 by marleand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./Libft/libft.h"
# include <stdbool.h>
# include <limits.h>
# include "stdio.h"

typedef struct s_swap
{
	int				value;
	int 			index;
	int				size;
	int				maxval;
	int				minval;
	int				cost_a;
	int				cost_b;
	bool			direction_a;
	bool			direction_b;
	int				total_cost;
	struct s_swap	*next;
	struct s_swap	*prev;
}	t_swap;

int	validate(char **av);
void	lstaddtail(t_swap **lst, t_swap *new);
void	lstaddhead(t_swap **lst, t_swap *new);
t_swap	*lstnew(int value);
void	rswap(t_swap **skyscraper);
void	rpush(t_swap **a_sky, t_swap **b_sky);
void	rrotate(t_swap **skyscraper);
void	rreverse(t_swap **skyscraper);
void	reverse(t_swap **skyscraper, t_swap **sky_b, char *str);
void	rotate(t_swap **skyscraper, t_swap **sky_b, char *str);
void	swap(t_swap **skyscraper, t_swap **sky_b, char *str);
void	push(t_swap **skyscraper, t_swap **sky_b, char *str);
void	sortthree(t_swap **skyscraper);
int		sortcheck(t_swap *skyscraper);

#endif