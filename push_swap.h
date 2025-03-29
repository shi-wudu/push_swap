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
	int				cost;
	int				one_d;
	int				total_cost;
	struct s_swap	*next;
	struct s_swap	*prev;
}	t_swap;

typedef enum t_rot
{
	R_R,
	RV_R,
	R_RV,
	RV_RV
}				t_rot;

typedef struct s_overall
{
	int costs[4];
	int index_a;
	int index_b;
	int cheapest;
} t_overall;

int	validate(char **av);
void	lstaddtail(t_swap **lst, t_swap *new);
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
int		getsizeof(t_swap *skyscraper);
void	bestofriendo(t_swap **sky_a, t_swap **sky_b);
void	brother(t_swap **sky_a, t_swap **sky_b);
int		getminval(t_swap *skyscraper);
int		getmaxval(t_swap *skyscraper);
void	freestack(t_swap *sky);
void	move_all_ts(t_swap **sky_a, t_swap **sky_b);
void	organize(t_swap **sky_a, t_swap **sky_b);
void	bestofrienda(t_swap **sky_a, t_swap **sky_b);
void	targeta(t_swap **sky_a, t_swap **sky_b, t_swap *temp_a, t_swap *temp_b);
void	targetb(t_swap **sky_a, t_swap **sky_b, t_swap *temp_a, t_swap *temp_b);
t_swap	*move_to_maxval(t_swap **sky_b);
t_swap	*move_to_minval(t_swap **sky_a);

#endif