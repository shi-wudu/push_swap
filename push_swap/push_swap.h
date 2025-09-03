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

# include <stdbool.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum t_rot
{
	ROTATE_BOTH,
	REVERSE_A_ROTATE_B,
	ROTATE_A_REVERSE_B,
	REVERSE_BOTH
}				t_rot;

typedef struct s_swap
{
	int				value;
	int				index;
	int				target_index;
	int				cost;
	t_rot			move_direction;
	struct s_swap	*next;
	struct s_swap	*prev;
}	t_swap;

typedef struct s_overall
{
	int	costs[4];
	int	index_a;
	int	index_b;
	int	cheapest;
}	t_overall;

/* ========================================================================== */
/*                              FUNCTION INDEX                               */
/* ========================================================================== */
/*                                                                            */
/*  1. INPUT VALIDATION & MEMORY MANAGEMENT                                  */
/*     - validate_arguments()         : Check if arguments are valid         */
/*     - add_node_to_tail()          : Add node to end of linked list       */
/*     - create_new_node()           : Create new stack node                 */
/*     - free_stack()                : Free all nodes in stack              */
/*                                                                            */
/*  2. CORE STACK OPERATIONS (Low Level)                                     */
/*     - execute_swap()              : Swap top 2 elements                   */
/*     - execute_push()              : Move top element between stacks       */
/*     - execute_rotate()            : Rotate stack up by 1                  */
/*     - execute_reverse_rotate()    : Rotate stack down by 1                */
/*                                                                            */
/*  3. INSTRUCTION PRINTERS (High Level)                                     */
/*     - swap_instruction()          : Execute swap + print instruction      */
/*     - push_instruction()          : Execute push + print instruction      */
/*     - rotate_instruction()        : Execute rotate + print instruction    */
/*     - reverse_rotate_instruction() : Execute reverse rotate + print       */
/*                                                                            */
/*  4. STACK ANALYSIS & UTILITIES                                            */
/*     - is_stack_sorted()           : Check if stack is sorted              */
/*     - get_stack_size()            : Get number of elements in stack       */
/*     - get_min_value()             : Find minimum value in stack           */
/*     - get_max_value()             : Find maximum value in stack           */
/*     - get_min_value_index()       : Find index of minimum value           */
/*     - get_max_value_index()       : Find index of maximum value           */
/*                                                                            */
/*  5. SORTING ALGORITHMS                                                     */
/*     - sort_three_elements()       : Sort 3 elements optimally             */
/*     - main_sort_algorithm()       : Main sorting algorithm                */
/*                                                                            */
/*  6. TARGET FINDING & COST CALCULATION                                     */
/*     - find_target_position_in_a() : Find where element should go in A     */
/*     - find_target_position_in_b() : Find where element should go in B     */
/*     - find_cheapest_node_to_a()   : Find cheapest element to move to A    */
/*     - find_cheapest_node_to_b()   : Find cheapest element to move to B    */
/*     - calculate_move_cost()       : Calculate cost to move to B           */
/*     - calculate_move_cost_back_to_a() : Calculate cost to move to A       */
/*                                                                            */
/*  7. MOVE EXECUTION                                                         */
/*     - execute_moves_to_a()        : Execute optimal moves to push to A    */
/*     - execute_moves_to_b()        : Execute optimal moves to push to B    */
/*     - reverse_both_to_a()         : Reverse rotate both stacks (to A)     */
/*     - reverse_both_to_b()         : Reverse rotate both stacks (to B)     */
/*     - rotate_reverse_to_a()       : Rotate A, reverse rotate B (to A)     */
/*     - rotate_reverse_to_b()       : Rotate A, reverse rotate B (to B)     */
/*     - reverse_rotate_to_a()       : Reverse rotate A, rotate B (to A)     */
/*     - reverse_rotate_to_b()       : Reverse rotate A, rotate B (to B)     */
/*                                                                            */
/*  8. DEBUG & UTILITIES                                                     */
/*     - print_stack()               : Print stack contents (debug)          */
/*                                                                            */
/* ========================================================================== */

/* 1. INPUT VALIDATION & MEMORY MANAGEMENT */
int		validate_arguments(char **av);
void	add_node_to_tail(t_swap **lst, t_swap *new);
t_swap	*create_new_node(int value);
void	free_stack(t_swap *stack);

/* 2. CORE STACK OPERATIONS (Low Level) */
void	execute_swap(t_swap **stack);
void	execute_push(t_swap **source_stack, t_swap **dest_stack);
void	execute_rotate(t_swap **stack);
void	execute_reverse_rotate(t_swap **stack);

/* 3. INSTRUCTION PRINTERS (High Level) */
void	swap_instruction(t_swap **stack_a, t_swap **stack_b, char *str);
void	push_instruction(t_swap **stack_a, t_swap **stack_b, char *str);
void	rotate_instruction(t_swap **stack_a, t_swap **stack_b, char *str);
void	reverse_rotate_instruction(t_swap **stack_a, t_swap **s_b, char *str);

/* 4. STACK ANALYSIS & UTILITIES */
int		is_stack_sorted(t_swap *stack);
int		get_stack_size(t_swap *stack);
int		get_min_value(t_swap *stack);
int		get_max_value(t_swap *stack);
int		get_min_value_index(t_swap *stack);
int		get_max_value_index(t_swap *stack);

/* 5. SORTING ALGORITHMS */
void	sort_three_elements(t_swap **stack);
void	main_sort_algorithm(t_swap **stack_a, t_swap **stack_b);

/* 6. TARGET FINDING & COST CALCULATION */
void	find_target_position_in_a(t_swap *node_b, t_swap *stack_a);
void	find_target_position_in_b(t_swap *node_a, t_swap *stack_b);
t_swap	*find_cheapest_node_to_a(t_swap *stack_a, t_swap *stack_b);
t_swap	*find_cheapest_node_to_b(t_swap *stack_a, t_swap *stack_b);
void	calculate_move_cost(t_swap *node, int size_a, int size_b);
void	calculate_move_cost_back_to_a(t_swap *node, int size_a, int size_b);

/* 7. MOVE EXECUTION */
void	execute_moves_to_a(t_swap **stack_a, t_swap **stack_b, t_swap *node);
void	execute_moves_to_b(t_swap **stack_a, t_swap **stack_b, t_swap *node);
void	reverse_both_to_a(t_swap **stack_a, t_swap **stack_b, t_swap *node);
void	reverse_both_to_b(t_swap **stack_a, t_swap **stack_b, t_swap *node);
void	rotate_reverse_to_a(t_swap **stack_a, t_swap **stack_b, t_swap *node);
void	rotate_reverse_to_b(t_swap **stack_a, t_swap **stack_b, t_swap *node);
void	reverse_rotate_to_a(t_swap **stack_a, t_swap **stack_b, t_swap *node);
void	reverse_rotate_to_b(t_swap **stack_a, t_swap **stack_b, t_swap *node);

/* 8. DEBUG & UTILITIES */
void	print_stack(t_swap *stack);

/* UTILS FUNCTIONS */
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *s1);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		no_duplicates(t_swap *stack, int value);

#endif