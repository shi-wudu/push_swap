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

typedef struct s_swap
{
	int				value;
	int 			index;
	struct s_swap	*next;
	struct s_swap	*prev;
}	t_swap;

int	validate(char **av);
void	lstaddtail(t_swap **lst, t_swap *new);
void	lstaddhead(t_swap **lst, t_swap *new);
t_swap	*lstnew(int value);

#endif